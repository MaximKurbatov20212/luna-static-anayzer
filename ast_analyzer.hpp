#include "ast.hpp"
#include <map>

class ast_analyzer {
public:
    bool analyze(program* program);

private:
    bool analyze_shadow_import(program* program);
    bool have_such_code_id(std::map<std::string, std::string>& map, import* import);
};