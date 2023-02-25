#include "ast_analyzer.hpp"
#include "error_reporter.hpp"
#include <iterator>
#include <map>

extern error_reporter reporter;

bool ast_analyzer::analyze(program* program) {
    std::cerr << "analyze\n";
    return shadow_import(program);
}

bool ast_analyzer::shadow_import(program* program) {
    std::map<std::string, std::string> map;

    std::vector<sub_def *> sub_defs = *(program->sub_defs);

    auto it = sub_defs.begin();
    auto end = sub_defs.end();

    while (it != end) {
        sub_def* def = *it;

        import_def* import = dynamic_cast<import_def *> (def); 

        if (import != nullptr) {

            // have such codeid 
            if (map.find(*(import->luna_code_id_->value_)) != map.end()) {
                // reporter.report("Shadowing",
                //     import->first_line,
                //     import->first_column,
                //     "hello"
                //     );

                reporter.report(ERROR_LEVEL::WARNING,
                    "line",
                    1,
                    1, 
                    "Shadowing"
                );
            }

            else {
                map.insert(std::pair<std::string, std::string>(*(import->luna_code_id_->value_), *(import->cxx_code_id_->value_)));
            }
        }
        it++;
    }
}
