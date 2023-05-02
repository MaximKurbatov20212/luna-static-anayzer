#include "ast.hpp"
#include "grammar.tab.hpp"
#include "ast_analyzer.hpp"
#include "error_reporter.hpp"
#include <fstream>

const int EXIT_ERROR = 1;

extern int yyparse();
extern FILE *yyin;
int line_num = 1;
std::string line, prev_line;
extern error_reporter reporter;

ast* ast_ = new ast();

int main(int argc, char** argv) {

    if (argc != 2) {
        std::cerr << "Bad number of args. Usage: ./a.out test.fa" << std::endl;
        return EXIT_ERROR;
    }

    yyin = fopen(argv[1], "r");

    if (!yyin) {
        std::cerr << "Couldn'e open file" << std::endl;
        return EXIT_ERROR;
    }

    std::cerr << "parse\n";

    yyparse();

    // std::cerr << ast_->to_string() << std::endl;

    ast_analyzer analyzer = ast_analyzer(ast_, yyin);

    std::cerr << "analyze\n";

    analyzer.analyze();

    // delete ast_;
    fclose(yyin);
    return EXIT_SUCCESS;
}