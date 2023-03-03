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

bool ast_analyzer::analyze(program* program) {
    return analyze_shadow_import(program);
}

bool ast_analyzer::analyze_shadow_import(program* program) {
    assert(program->sub_defs != nullptr);

    bool has_errors;
    std::map<std::string, std::string> map;

    std::vector<sub_def *> sub_defs = *(program->sub_defs);

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
                "import c_init1(int, name) as init;",
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
