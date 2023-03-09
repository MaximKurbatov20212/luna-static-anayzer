#ifndef LUNA_AST
#define LUNA_AST

#include <cstring>
#include <iostream>
#include <vector>

class virtual_token {
public:
    unsigned int line_;
    unsigned int pos_;

    void set_position(uint line, uint pos) {
        pos_ = pos;
        line_ = line;
    }

    virtual std::string to_string() const { return std::string("hello");}
    virtual ~virtual_token(){}
};

class expr : public virtual_token {};

class luna_string : public expr {
    public:
        std::string* value_;
        luna_string(std::string* value) : value_(value) {} 

        luna_string() : value_(new std::string()) {}

        ~luna_string() {
            std::cerr << "luna string dtor: " << *value_ << std::endl;
            delete value_;
            std::cerr << "after luna string dtor: " << std::endl;
        }

        std::string to_string() const override {
            return *value_;
        }
};
    
class id : public virtual_token {};

class param : public virtual_token {
    public:    
        luna_string *type_;
        luna_string* name_;
        param(luna_string* type, luna_string* name) : type_(type), name_(name) {}

        ~param() {
            delete type_;
            delete name_;
        }
};

class param_seq : public virtual_token {
    public:    
        std::vector<param *>* params_;
        param_seq(std::vector<param *>* params, uint pos = 0) : params_(params) {}

        param_seq() : params_(new std::vector<param *>()) {}

        ~param_seq() {
            for (auto i : *params_) {
                delete i;
            }
            delete params_;
        }
};

class opt_params : public virtual_token {
    public:
        param_seq *param_seq_;
        opt_params(param_seq *param_seq) : param_seq_(param_seq) {}
        opt_params() : param_seq_(new param_seq()) {}

        ~opt_params() {
            delete param_seq_;
        }
};

class name_seq : public virtual_token {
    public:
        std::vector<luna_string *> * names_;
        name_seq(std::vector<luna_string *> * names) : names_(names) {}
        name_seq() : names_(new std::vector<luna_string *>()) {}

        ~name_seq() {
            for (auto i : *names_) {
                delete i;
            }
            delete names_;
        }
};

class dfdecls : public virtual_token {
    public:
        name_seq *name_seq_;
        dfdecls(name_seq *name_seq) : name_seq_(name_seq) {}
        dfdecls() : name_seq_(new name_seq()) {}

        ~dfdecls() {
            delete name_seq_;
        }
};

class opt_dfdecls : public virtual_token {
    public:
        dfdecls *dfdecls_;
        opt_dfdecls(dfdecls *dfdecls) : dfdecls_(dfdecls) {}
        opt_dfdecls() : dfdecls_(new dfdecls()) {}
        ~opt_dfdecls() {
            delete dfdecls_;
        }
};

class statement : public virtual_token {};

class statement_seq : public virtual_token {
    public:
        std::vector<statement *>* statements_;
        statement_seq(std::vector<statement *>* statements) : statements_(statements) {}
        statement_seq() : statements_(new std::vector<statement *>()) {}

        ~statement_seq() {
            for (auto i : *statements_) {
                delete i;
            }
            delete statements_;
        }
};

class behv_pragma : public virtual_token {};

class behv_pragmas_seq : public virtual_token {
    public:
        std::vector<behv_pragma*>* behv_pragma_;
        behv_pragmas_seq(std::vector<behv_pragma*>* behv_pragma) : behv_pragma_(behv_pragma) {}
        behv_pragmas_seq() : behv_pragma_(new std::vector<behv_pragma*>()) {}

        ~behv_pragmas_seq() {
            for (auto i : *behv_pragma_) {
                delete i;
            }
            delete behv_pragma_;
        }
};

class opt_behavior : public virtual_token {
    public:
        behv_pragmas_seq *seq_;
        opt_behavior(behv_pragmas_seq *seq) : seq_(seq) {}
        opt_behavior() : seq_(new behv_pragmas_seq()) {}

        ~opt_behavior() {
            delete seq_;
        }
};

class block : public virtual_token {
    public:
        opt_dfdecls* opt_dfdecls_;
        statement_seq* statement_seq_;
        opt_behavior* opt_behavior_;

        block(opt_dfdecls* opt_dfdecls,
                statement_seq* statement_seq,
                opt_behavior* opt_behavior)

            : opt_dfdecls_(opt_dfdecls), statement_seq_(statement_seq), opt_behavior_(opt_behavior) {}
        
        block() : opt_dfdecls_(new opt_dfdecls()),
                 statement_seq_(new statement_seq()),
                 opt_behavior_(new opt_behavior()) {}

        ~block() {
            delete opt_dfdecls_;
            delete statement_seq_;
            delete opt_behavior_;

            std::cerr << "block dtor\n";
        }
};

class complex_id : public id {
    public:
        id *id_;
        expr *expr_;
        complex_id(id *id, expr *expr) : id_(id), expr_(expr) {}
        complex_id() : id_(new id()), expr_(new expr()) {}

        ~complex_id() {
            delete id_;
            delete expr_;
            std::cerr << "complex id dtor\n";
        }
};

class integer : public expr {
    public:
        int* value_;
        integer(int* value) : value_(value) {}
        ~integer() {
            delete value_;
            std::cerr << "integer dtor\n";
        }
};

class real : public expr {
    public:
        double* value_;
        real(double* value) : value_(value) {} 
        ~real() {
            delete value_;
        }
};

class luna_cast : public expr {
    public:
        expr *expr_;
        luna_cast(expr *expr) : expr_(expr) {}
        ~luna_cast() {
            delete expr_;
        }
};

class to_int : public luna_cast {};
class to_real : public luna_cast {};
class to_string : public luna_cast {};

class code_df_param : public virtual_token {
    public:
        luna_string *type_;
        luna_string *code_df_;
        code_df_param(luna_string* type, luna_string* df) : type_(type), code_df_(df) {}

        ~code_df_param() {
            std::cerr << "code param dtor: type_\n";
            delete type_;
            std::cerr << "code param dtor: code_df\n";
            delete code_df_;
        }
};

class ext_params_seq : public virtual_token {
    public:
        std::vector<code_df_param *>* params_;
        ext_params_seq(std::vector<code_df_param *>* params) : params_(params) {}
        ext_params_seq() : params_(new std::vector<code_df_param *>()) {}

        ~ext_params_seq() {
            std::cerr << "ext_params_seq dtor\n";

            for (auto param : *params_) {
                delete param;
            }
            delete params_;
        }
};

class opt_ext_params : public virtual_token {
    public:
        ext_params_seq *seq_;
        opt_ext_params(ext_params_seq *seq) : seq_(seq) {}
        opt_ext_params() : seq_(new ext_params_seq()) {}

        ~opt_ext_params() {
            std::cerr << "opt_ext_params dtor\n";
            delete seq_;
        }

};

class bin_op : public expr {
    public:
        expr *left_;
        expr *right_;
        bin_op(expr *left, expr *right) : left_(left), right_(right) {}

        ~bin_op() {
            delete left_;
            delete right_;
        }
};

class eq : public bin_op {
    public:
        eq(expr *left, expr *right) : bin_op(left, right) {}
};

class eqg : public bin_op {
    public:
        eqg(expr *left, expr *right) : bin_op(left, right) {}
};

class sum : public bin_op {
    public:
        sum(expr *left, expr *right) : bin_op(left, right) {}
};

class sub : public bin_op {
    public:
        sub(expr *left, expr *right) : bin_op(left, right) {}
};

class div1 : public bin_op {
    public:
        div1(expr *left, expr *right) : bin_op(left, right) {}
};

class mul : public bin_op {
    public:
        mul(expr *left, expr *right) : bin_op(left, right) {}
};

class mod : public bin_op {
    public:
        mod(expr *left, expr *right) : bin_op(left, right) {}
};

class lt : public bin_op {
    public:
        lt(expr *left, expr *right) : bin_op(left, right) {}
};

class gt : public bin_op {
    public:
        gt(expr *left, expr *right) : bin_op(left, right) {}
};

class leq : public bin_op {
    public:
        leq(expr *left, expr *right) : bin_op(left, right) {}
};

class geq : public bin_op {
    public:
        geq(expr *left, expr *right) : bin_op(left, right) {}
};

class dbleq : public bin_op {
    public:
        dbleq(expr *left, expr *right) : bin_op(left, right) {}
};

class neq : public bin_op {
    public:
        neq(expr *left, expr *right) : bin_op(left, right) {}
};

class dblamp : public bin_op {
    public:
        dblamp(expr *left, expr *right) : bin_op(left, right) {}
};

class dblpipe : public bin_op {
    public:
        dblpipe(expr *left, expr *right) : bin_op(left, right) {}
};

class sub_def : public virtual_token {
    public:
        ~sub_def() {
            std::cerr << "sub_def dtor\n";
        }
};

class program : public virtual_token {
    public:
        std::vector<sub_def *>* sub_defs;

        program(std::vector<sub_def *>* other) : sub_defs(other) {}

        program() : sub_defs(new std::vector<sub_def *>(0)) {}
        
        ~program() {
            std::cerr << "program dtor\n";

            for (auto i : *sub_defs) {
                delete i;
            }
            delete sub_defs;
        }

        std::string to_string() const override {
            std::string res;
            for (auto i : *sub_defs) {
                res += i->to_string();
            }
            return res;
        }
};

class control_pragma : public virtual_token {
    public:
        luna_string *where_type_;
        std::vector<expr *>* expr_;
        control_pragma(luna_string* other_type, std::vector<expr *>* other_expr) : where_type_(other_type), expr_(other_expr) {}
        control_pragma() : where_type_(new luna_string()), expr_(new std::vector<expr *>()) {}
        ~control_pragma() {
            std::cerr << "control pragma dtor\n";
            delete where_type_;
            delete expr_;
        }
};

class luna_sub_def : public sub_def {
    public:
        control_pragma *control_pragma_;
        luna_string *code_id_;
        opt_params *params_;
        block *block_;

        luna_sub_def(control_pragma* cp,
                    luna_string* id,
                    opt_params* params,
                    block* block) 
            : control_pragma_(cp), code_id_(id), params_(params), block_(block) {}
        
        luna_sub_def() : control_pragma_(new control_pragma()), 
                        code_id_(new luna_string()),
                        params_(new opt_params()),
                        block_(new block()) {}

        ~luna_sub_def() {
            std::cerr << "luna_sub_def dtor\n";
            delete control_pragma_;
            delete code_id_;
            delete params_;
            delete block_;
        }
};

class import : public sub_def {
    public:
        luna_string *cxx_code_id_;
        opt_ext_params *params_;
        luna_string *luna_code_id_;
        std::string options_;

        import(luna_string* cxx_id, opt_ext_params* params, luna_string* luna_id, const std::string options) 
            : cxx_code_id_(cxx_id), params_(params), luna_code_id_(luna_id), options_(options) 
            {}

        import() : cxx_code_id_(new luna_string()),
                        params_(new opt_ext_params()),
                        luna_code_id_(new luna_string()) {}

        ~import() {
            std::cerr << "import dtor\n";
            std::cerr << "delete : " << cxx_code_id_<< std::endl;
            delete cxx_code_id_;
            std::cerr << "delete : " << params_ << std::endl;
            delete params_;
            std::cerr << "delete : " << luna_code_id_ << std::endl;
            delete luna_code_id_;
        }

        std::string to_string() const override {
            return "import " + cxx_code_id_->to_string() + "(" + params_->to_string() + ") as " + luna_code_id_->to_string() + options_ + ";";
        }
};

class cxx_block_with_params_def : public sub_def {
    public:
        luna_string *code_id_;
        opt_params *params_;

        cxx_block_with_params_def(luna_string* id, opt_params* params) 
            : code_id_(id), params_(params) {}
        
        ~cxx_block_with_params_def() {
            delete code_id_;
            delete params_;
        }
};

class cxx_block_def : public sub_def {
    public:
        luna_string *name_;
        cxx_block_def(luna_string* id) : name_(id) {}

        ~cxx_block_def() {
            delete name_;
        }
};

class if_statement : public statement {
    public:
        expr *expr_;
        block *block_;
        if_statement(expr *expr, block *block) : block_(block), expr_(expr) {}

        ~if_statement() {
            delete expr_;
            delete block_;
        }
};

class for_statement : public statement {
    public:
        control_pragma *control_pragma_;
        luna_string *name_;
        expr *expr_1_;
        expr *expr_2_;
        block *block_;
        for_statement(control_pragma *control_pragma,
                luna_string *name,
                expr *expr_1,
                expr *expr_2,
                block *block)
            : control_pragma_(control_pragma), name_(name), expr_1_(expr_1), expr_2_(expr_2), block_(block) {}
        
        ~for_statement() {
            delete control_pragma_;
            delete name_;
            delete expr_1_;
            delete expr_2_;
            delete block_;
        }
};

class assign : public virtual_token {
    public:
        luna_string *name_;
        expr *expr_;
        assign(luna_string *name, expr *expr) : name_(name), expr_(expr) {}

        ~assign() {
            delete name_;
            delete expr_;
        }
};

class assign_seq : public virtual_token {
    public:
        std::vector<assign* >* assign_seq_;
        assign_seq(std::vector<assign* >* assign_seq) : assign_seq_(assign_seq) {}
        assign_seq() : assign_seq_(new std::vector<assign* >()) {}

        ~assign_seq() {
            for (auto i : *assign_seq_) {
                delete i;
            }
            delete assign_seq_;
        }
};

class let_statement : public statement {
    public:
        assign_seq *assign_seq_;
        block *block_;
        let_statement(assign_seq *assign_seq_, block *block) : assign_seq_(assign_seq_), block_(block) {}

        ~let_statement() {
            delete assign_seq_;
            delete block_;
        }
};

class behv_pragma_seq : public behv_pragma {
    public:
        name_seq* name_seq_;
        behv_pragma_seq(name_seq* name_seq) : name_seq_(name_seq) {}
        ~behv_pragma_seq() {
            delete name_seq_;
        }
};

class while_statement : public statement {
    public:
        control_pragma *control_pragma_;
        luna_string *left_;
        expr *expr_;
        expr *right_;
        block *block_;
        id *id_;

        while_statement(control_pragma *control_pragma,
                expr *expr_,
                luna_string *left,
                expr *right,
                id* id,
                block *block) 
            : block_(block), expr_(expr_), left_(left), right_(right), id_(id), control_pragma_(control_pragma) {}

        ~while_statement() {
            delete control_pragma_;
            delete expr_;
            delete left_;
            delete right_;
            delete id_;
            delete block_;
        }
};
class exprs_seq : public virtual_token {
    public:
        std::vector<expr* >* expr_;
        exprs_seq(std::vector<expr* >* expr) : expr_(expr) {}
        exprs_seq() : expr_(new std::vector<expr* >()) {}

        ~exprs_seq() {
            for (auto i : *expr_) {
                delete i;
            }
            delete expr_;
        }
};

class opt_exprs : public virtual_token {
    public:
        exprs_seq *exprs_seq_;
        opt_exprs(exprs_seq *exprs_seq) : exprs_seq_(exprs_seq) {}
        ~opt_exprs() { 
            delete exprs_seq_;
        }
};

class opt_setdf_rules : public virtual_token {
    public:
        opt_exprs *opt_exprs_;
        opt_setdf_rules(opt_exprs *opt_exprs) : opt_exprs_(opt_exprs) {}
        ~opt_setdf_rules() {
            delete opt_exprs_;
        }
};

class opt_label : public virtual_token {
    public:
        id *id_;
        opt_label(id *id) : id_(id) {}

        ~opt_label() {
            delete id_;
        }
};

class opt_rules : public virtual_token {
    public:
        opt_exprs *opt_exprs_;
        opt_rules(opt_exprs *opt_exprs) : opt_exprs_(opt_exprs) {}

        ~opt_rules() {
            delete opt_exprs_;
        }
};


class cf_statement : public statement {
    public:
        opt_label *opt_label_;
        luna_string *code_id_;
        opt_exprs *opt_exprs_;
        opt_setdf_rules *opt_setdf_rules_;
        opt_rules *opt_rules_;
        opt_behavior *opt_behavior_;

        cf_statement(opt_label *opt_label,
                luna_string *code_id,
                opt_exprs *opt_exprs,
                opt_setdf_rules *opt_setdf_rules,
                opt_rules *opt_rules,
                opt_behavior *opt_behavior)
            : opt_label_(opt_label),
            code_id_(code_id), 
            opt_exprs_(opt_exprs),
            opt_setdf_rules_(opt_setdf_rules),
            opt_rules_(opt_rules),
            opt_behavior_(opt_behavior) {}
        
        ~cf_statement() {
            delete opt_label_;
            delete code_id_;
            delete opt_exprs_;
            delete opt_setdf_rules_;
            delete opt_rules_;
            delete opt_behavior_;
        }
};

class id_seq : public virtual_token {
    public:
        std::vector<id*>* seq_;
        id_seq(std::vector<id*>* seq) : seq_(seq) {}
        id_seq() : seq_(new std::vector<id*>()) {}

        ~id_seq() {
            for (auto i : *seq_) {
                delete i;
            }
            delete seq_;
        }
};

class behv_pragma_eq : public behv_pragma {
    public:
        luna_string *name_;
        id* id_;
        expr* expr_;
        behv_pragma_eq(luna_string *name, id* id, expr* expr) : name_(name), id_(id), expr_(expr) {}

        ~behv_pragma_eq() {
            delete name_;
            delete id_;
            delete expr_;
        }
};

class behv_pragma_eqg : public behv_pragma {
    public:
        luna_string *name_;
        id* id_;
        expr* expr_;
        behv_pragma_eqg(luna_string *name, id* id, expr* expr) : name_(name), id_(id), expr_(expr) {}

        ~behv_pragma_eqg() {
            delete name_;
            delete id_;
            delete expr_;
        }
};

class behv_pragma_id_seq : public behv_pragma {
    public:
        luna_string *name_;
        id_seq *id_seq_;
        behv_pragma_id_seq(luna_string *name, id_seq *id_seq) : name_(name), id_seq_(id_seq) {}
        behv_pragma_id_seq() : name_(new luna_string()), id_seq_(new id_seq()) {}

        ~behv_pragma_id_seq() {
            delete name_;
            delete id_seq_;
        }
};

class behv_pragma_expr : public behv_pragma {
    public:
        luna_string *name_;
        expr *expr_;
        behv_pragma_expr(luna_string *name, expr *expr) : expr_(expr), name_(name) {}

        ~behv_pragma_expr() {
            delete name_;
            delete expr_;
        }
};

class behv_pragma_name_seq : public behv_pragma {
    public:    
        luna_string *name_;
        name_seq *seq_;
        behv_pragma_name_seq(luna_string *name, name_seq *seq) : name_(name), seq_(seq) {}

        ~behv_pragma_name_seq() {
            delete name_;
            delete seq_;
        }
};

class opt_expr : public virtual_token {
    public:
        exprs_seq *exprs_seq_;
        opt_expr(exprs_seq *exprs_seq) : exprs_seq_(exprs_seq) {}

        ~opt_expr() {
            delete exprs_seq_;
        }
};

class simple_id : public id {
    public:
        luna_string *name_;
        simple_id(luna_string * name) : name_(name) {}

        ~simple_id() {
            delete name_;
        }
};
#endif
