#include "ast_analyzer.hpp"
#include "error_reporter.hpp"
#include <iterator>
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
    bool has_errors = analyze_shadow_import();
    // has_errors = analyze_df_double_declaration();
    return has_errors;
}

bool ast_analyzer::analyze_df_double_declaration() {
    std::vector<sub_def *> sub_defs = *(program_->sub_defs);
    std::vector<luna_sub_def *> luna_sub_defs;

    auto it = sub_defs.begin();
    auto end = sub_defs.end();

    while (it != end) {
        luna_sub_def* luna_def = dynamic_cast<luna_sub_def *> (*it); 

        if (luna_def == nullptr) {
            it++;
            continue;
        }

        std::vector<luna_string *>* dfs = luna_def->block_->opt_dfdecls_->dfdecls_->name_seq_->names_;

        // while ()
    }
    return true;
}

bool ast_analyzer::analyze_shadow_import() {
    assert(program_->sub_defs != nullptr);

    bool has_errors;
    std::map<std::string, std::string> map;

    std::vector<sub_def *> sub_defs = *(program_->sub_defs);

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
