#include "ast.hpp"
#include "grammar.tab.hpp"
#include "ast_analyzer.hpp"
#include "error_reporter.hpp"

const int EXIT_ERROR = 1;

extern int yyparse();
int line_num = 1;
std::string line, prev_line;
program* ast;
bool has_errors = false;
extern error_reporter reporter;

int main() {
    ast_analyzer ast_analyzer;
    
    std::cerr << "parse\n";

    yyparse();

    if (reporter.has_errors()) {
        delete ast;
        return EXIT_ERROR;
    }

    std::cerr << "analyze\n";
    ast_analyzer.analyze(ast);

    delete ast;
    return EXIT_SUCCESS;
}