#include "ast_analyzer.hpp"
#include "error_reporter.hpp"
#include <iterator>
#include <set>
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
    has_errors = analyze_df_double_declaration();
    has_errors = analyze_existance_main_cf();
    has_errors = analyze_cf_redeclaration();
    return has_errors;
}

bool ast_analyzer::analyze_df_double_declaration() {
    std::vector<sub_def *> sub_defs = *(ast_->get_program()->sub_defs);
    std::vector<luna_sub_def *> luna_funcs;

    bool has_errors = false;

    for (auto i : sub_defs) {
        luna_sub_def* luna_func = dynamic_cast<luna_sub_def *> (i); 
        if (luna_func == nullptr) continue;
        luna_funcs.push_back(luna_func);
        if (luna_func->block_->opt_dfdecls_->dfdecls_ == nullptr) continue;

        std::vector<luna_string *>* dfs = luna_func->block_->opt_dfdecls_->dfdecls_->name_seq_->names_;

        std::vector<luna_string*> duplicated = find_pairs<luna_string *> (dfs);

        for (auto i : duplicated) {
            reporter.report(ERROR_LEVEL::ERROR,
                "DF " + i->to_string() + " is already defined",
                get_line_from_file(i->line_),
                i->line_,
                i->pos_
            );
            has_errors = true;
        }
    }
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

bool ast_analyzer::analyze_cf_redeclaration() {
    std::vector<sub_def *> sub_defs = *(ast_->get_program()->sub_defs);
    std::vector<luna_sub_def *> luna_funcs;

    for (auto i : sub_defs) {
        luna_sub_def* luna_func = dynamic_cast<luna_sub_def *> (i); 
        if (luna_func == nullptr) continue;
        luna_funcs.push_back(luna_func);
    }

    std::vector<luna_sub_def *> duplicated = find_pairs<luna_sub_def *>(&luna_funcs);

    for (auto i : duplicated) {
        reporter.report(ERROR_LEVEL::ERROR,
            "CF " + *(i->code_id_->value_) + " is aleady defined",
            get_line_from_file(i->code_id_->line_),
            i->code_id_->line_,
            i->code_id_->pos_
        );
    }

    return duplicated.size() > 0;
}

bool ast_analyzer::analyze_shadow_import() {

    bool has_errors;
    std::map<std::string, std::string> map;

    std::vector<sub_def *> sub_defs = *(ast_->get_program()->sub_defs);

    auto it = sub_defs.begin();
    auto end = sub_defs.end();


    while (it != end) {
        import* import_decl = dynamic_cast<import *> (*it); 

        if (import_decl == nullptr) {
            it++;
            continue;
        }

        if (have_such_code_id(map, import_decl)) {
            reporter.report(ERROR_LEVEL::WARNING,
                "such codeid aleady define",
                get_line_from_file(import_decl->luna_code_id_->line_),
                import_decl->luna_code_id_->line_,
                import_decl->luna_code_id_->pos_
            );
        }

        else {
            map.insert(std::pair<std::string, std::string>(
                *(import_decl->luna_code_id_->value_),   
                 *(import_decl->cxx_code_id_->value_))
            );
        }
        it++;
    }
    return has_errors;
}

// template <typename T>
// std::vector<T> ast_analyzer::find_pairs(std::vector<T>* v) {
//     std::set<std::string> set;
//     std::vector<T> duplicated;

//     for (auto i : *v) {
//         if (set.count(*(i->get_value()) > 0)) {
//             duplicated.push_back(i);
//         }
//         else {
//             set.insert(*(i->get_value()));
//         }
//     }
//     return duplicated;
// }


std::string ast_analyzer::get_line_from_file(uint num) {
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