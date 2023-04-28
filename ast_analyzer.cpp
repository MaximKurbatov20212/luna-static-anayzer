#include "ast_analyzer.hpp"
#include "error_reporter.hpp"
#include <iterator>
#include <set>
#include <map>
#include <assert.h>

extern error_reporter reporter;
extern std::string line;

bool ast_analyzer::have_such_code_id(std::map<std::string, std::string>& map,
                                    import* import) {
    if (import == nullptr) return false;

    if (map.find(*(import->luna_code_id_->value_)) != map.end()) {
        return true;
    }

    return false;
}

bool ast_analyzer::analyze() {
    assert(ast_->get_program()->sub_defs != nullptr);

    bool has_errors = analyze_shadow_import();
    has_errors = analyze_df_redeclaration();
    has_errors = analyze_existance_main_cf();
    has_errors = analyze_cf_redeclaration();
    return has_errors;
}


template <typename T>
std::vector<T> ast_analyzer::find_pairs(std::vector<T>* v) {
    std::set<std::string> set;
    std::vector<T> duplicated;

    for (auto i : *v) {
        if ((set.count(*(i->get_value())) > 0)) {
            duplicated.push_back(i);
        }
        else {
            set.insert(*(i->get_value()));
        }
    }
    return duplicated;
}

bool ast_analyzer::analyze_existance_main_cf() {
    std::vector<sub_def *> sub_defs = *(ast_->get_program()->sub_defs);

    bool has_main = false;
    for (auto i : sub_defs) {
        if (i == nullptr) continue;

        luna_sub_def* luna_func = dynamic_cast<luna_sub_def *> (i); 
        if (luna_func == nullptr) continue;

        if (*(luna_func->code_id_->value_) == "main") {
            has_main = true;
            break;
        }
    }

    if (has_main) return false;

    reporter.report(ERROR_LEVEL::ERROR,
        "No sub main",
        "",
        0,
        0
    );
    return true;
}
            
std::map<std::string, std::set<uint>> ast_analyzer::find_redecls(std::vector<luna_string* > values) {
    auto map = std::map<std::string, std::set<uint>>();

    for (auto i : values) {
        if (map.count(*(i->get_value())) == 0) {
            // std::cerr << i->line_ << std::endl;
            std::set<uint> set = std::set<uint>();
            set.insert(i->line_);
            map.insert(std::pair<std::string, std::set<uint>>(*(i->get_value()), set));
        }
        else {
            // std::cerr << i->line_ << std::endl;
            map.at(*(i->get_value())).insert(i->line_);
            // std::cerr << map.at(*(i->get_value())).size() << std::endl;
            // std::cerr << set.size() << std::endl;
        }
    }
    return map;
}

bool ast_analyzer::has_df_redeclaration(std::vector<luna_string* > prev_values, block* block_) {
    bool has_errors = false;

    std::vector<luna_string* > all_values = prev_values;
    std::vector<luna_string* > block_values = get_block_values(block_);

    // std::cerr << "HELLO" << std::endl;
    // for (auto i : block_values) {
    //     std::cerr << *(i->get_value()) << std::endl;
    // }
    
    all_values.insert(all_values.end(), block_values.begin(), block_values.end());
   
    // for (auto i : all_values) {
    //     std::cerr << *(i->get_value()) << std::endl;
    // }

    std::map<std::string, std::set<uint>> map = find_redecls(all_values);

    // for (auto i : map) {
    //     for (auto j : i.second){
    //         std::cerr << j << std::endl;
    //     }
    //     std::cerr << i.first << ": " <<  i.second.size() << std::endl;
    // }

    for (auto i : map) {
        if (i.second.size() <= 1) continue;
        std::string prev_decls;

        for (auto line : i.second) {
            prev_decls += "\tLine " + std::to_string(line) + ": " + get_line_from_file(line);
        }

        reporter.report(ERROR_LEVEL::ERROR,
            "Alias \"" + i.first + "\" multiple declarations",
            prev_decls,
            0 
        );
    }

    for (auto i : *(block_->statement_seq_->statements_)) {
        cf_statement* cur_cf = dynamic_cast<cf_statement*> (i);
        if (cur_cf != nullptr) continue; 

        if_statement* cur_if = dynamic_cast<if_statement*> (i);

        if (cur_if != nullptr) {
            has_df_redeclaration(all_values, cur_if->block_);
            continue;
        }

        while_statement* cur_while = dynamic_cast<while_statement*> (i);
        if (cur_while != nullptr) {
            has_df_redeclaration(all_values, cur_while->block_);
            continue;
        }

        for_statement* cur_for = dynamic_cast<for_statement*> (i);
        if (cur_for != nullptr) {
            has_df_redeclaration(all_values, cur_for->block_);
        }
    }
    return has_errors;
}

std::vector<luna_string *> ast_analyzer::get_block_values(block* block_) {

    std::vector<luna_string* > all_values = std::vector<luna_string* >();

    if (block_->opt_dfdecls_->dfdecls_ != nullptr) {
        auto names = block_->opt_dfdecls_->dfdecls_->name_seq_->names_;
        all_values.insert(all_values.end(), names->begin(), names->end());
    } 

    for (auto i : *(block_->statement_seq_->statements_)) {
        cf_statement* cur_cf = dynamic_cast<cf_statement*> (i);
        if (cur_cf == nullptr) continue;
        if (cur_cf->opt_label_->id_ == nullptr) continue;
        all_values.push_back(new luna_string(cur_cf->opt_label_->id_->get_value(), cur_cf->opt_label_->id_->line_));           
    }

    return all_values;
}

bool ast_analyzer::analyze_df_redeclaration() {
    std::vector<sub_def *> sub_defs = *(ast_->get_program()->sub_defs);
    std::vector<luna_sub_def *> luna_funcs;

    for (auto i : sub_defs) {
        if (i == nullptr) continue;
        luna_sub_def* luna_func = dynamic_cast<luna_sub_def *> (i); 
        if (luna_func == nullptr) continue;
        luna_funcs.push_back(luna_func);
    }

    bool has_errors;

    for (auto luna_func : luna_funcs) {
        std::vector<param *>* params = nullptr;
        if (luna_func->params_->param_seq_ != nullptr) {
            params = luna_func->params_->param_seq_->params_;
        }

        std::vector<luna_string* > all_values = std::vector<luna_string* >();

        if (params != nullptr) {
            for (auto i : *params) {
                all_values.push_back(i->name_);
            }
        }
        has_df_redeclaration(all_values, luna_func->block_);
        all_values.clear();
    }
    return false;
}

bool ast_analyzer::analyze_cf_redeclaration() {
    std::vector<sub_def *> sub_defs = *(ast_->get_program()->sub_defs);
    std::vector<luna_sub_def *> luna_funcs;

    for (auto i : sub_defs) {
        if (i == nullptr) continue;
        luna_sub_def* luna_func = dynamic_cast<luna_sub_def *> (i); 
        if (luna_func == nullptr) continue;
        luna_funcs.push_back(luna_func);
    }

    std::vector<luna_sub_def *> duplicated = find_pairs<luna_sub_def *>(&luna_funcs);

    for (auto i : duplicated) {
        reporter.report(ERROR_LEVEL::ERROR,
            "CF \"" + *(i->code_id_->value_) + "\" is aleady defined.",
            get_line_from_file(i->code_id_->line_),
            i->code_id_->line_
        );
    }

    return duplicated.size() > 0;
}

bool ast_analyzer::analyze_shadow_import() {
    bool has_errors;

    std::vector<sub_def *> sub_defs = *(ast_->get_program()->sub_defs);
    std::vector<luna_string* > aliases;

    for (auto i : sub_defs) {
        if (i == nullptr) continue;
        import* import_decl = dynamic_cast<import *> (i); 
        if (import_decl == nullptr) continue;
        aliases.push_back(import_decl->luna_code_id_);
    }

    std::map<std::string, std::set<uint>> map = find_redecls(aliases); // alias : <line1, line2, line3 ... >

    for (auto i : map) {
        if (i.second.size() <= 1) continue;
        std::string prev_decls;

        for (auto line : i.second) {
            prev_decls += "\tLine " + std::to_string(line) + ": " + get_line_from_file(line);
        }

        reporter.report(ERROR_LEVEL::WARNING,
            "LuNA alias \"" + i.first + "\" multiple declarations",
            prev_decls,
            0 
        );
        has_errors = true;
    }
    return has_errors;
}

std::string ast_analyzer::get_line_from_file(uint num) {
    // std::cerr << num;
    int fseek_res = fseek(file_, 0, SEEK_SET);
    if (fseek_res == FSEEK_ERROR) {
        perror("fseek");
        throw std::runtime_error("fseek");
    }

    int i = 1;
    while (i != num) {
        char c = fgetc(file_);
        assert(c != EOF);

        if (c == '\n') {
            i++;
        }
    }

    size_t len = 0;
    char* line = NULL;
    ssize_t string_len = getline(&line, &len, file_);

    if (string_len == -1) {
        throw std::runtime_error("Couldn't allocate memory");
    }

    std::string l = std::string(line);

    delete line;
    return l;
}