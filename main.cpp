#include "ast.hpp"
#include "grammar.tab.hpp"
#include "ast_analyzer.hpp"

extern int yyparse();
int line_num = 1;
std::string line, prev_line;
program* ast;

int main() {
    ast_analyzer ast_analyzer;
    
    std::cerr << "parse\n";

    yyparse();

    ast_analyzer.analyze(ast);

    return 0;
}