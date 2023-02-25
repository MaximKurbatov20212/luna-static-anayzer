#include "ast.hpp"

class ast_analyzer {
public:
    bool analyze(program* program);

private:
    bool shadow_import(program* program);
};