#include "ast.hpp"
#include <map>

class ast_analyzer {
public:
    ast_analyzer(program* program, FILE* file) : program_(program), file_(file) {}
    ~ast_analyzer() {
        fclose(file_);
    }

    bool analyze();

private:
    static const int FSEEK_ERROR = -1;
    FILE* file_;
    program* program_;

    bool analyze_shadow_import();
    bool have_such_code_id(std::map<std::string, std::string>& map, import* import);
    bool analyze_df_double_declaration();
    std::string get_line_from_file(uint num);
};