#include "ast.hpp"
#include <map>
#include <set>

class ast_analyzer {
public:
    ast_analyzer(ast* ast, FILE* file) : ast_(ast), file_(file) {}

    ~ast_analyzer() {}

    bool analyze();

private:
    static const int FSEEK_ERROR = -1;
    FILE* file_;
    ast* ast_;

    bool analyze_shadow_import();
    bool have_such_code_id(std::map<std::string, std::string>& map, import* import);
    bool analyze_df_double_declaration();
    bool analyze_existance_main_cf();
    bool analyze_cf_redeclaration();
    bool analyze_df_redeclaration();
    bool has_df_redeclaration(std::vector<luna_string *> prev_values, block* block_);
    std::vector<luna_string *> get_block_values(block* block_);
    std::map<std::string, std::set<uint>> find_redecls(std::vector<luna_string* > values);

    template <typename T>
    std::vector<T> find_pairs(std::vector<T>* v);
   
    std::string get_line_from_file(uint num);
};