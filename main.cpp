#include "ast.hpp"
extern int yyparse();

int main() {
    std::cerr << "parse\n";
    yyparse();
    return 0;
}