#ifndef LUNA_AST
#define LUNA_AST

#include <cstring>
#include <iostream>
#include <vector>

class Base {
    unsigned int first_line;
    unsigned int last_line;
    unsigned int first_column;
    unsigned int last_column;
    // public:
    // virtual luna_string to_string() = 0;
};

class expr : public Base {};

class luna_string : public expr {
    public:
        std::string* value_;
        luna_string(std::string* value) : value_(value) {
            std::cerr << "string Ctor\n";
        } 

        luna_string() : value_(new std::string()) {}
};
    
class id : public Base {};

class param : public Base {
    public:    
        luna_string *type_;
        luna_string* name_;
        param(luna_string* type, luna_string* name) : type_(type), name_(name) {}
};

class param_seq : public Base {
    public:    
        std::vector<param *>* params_;
        param_seq(std::vector<param *>* params) : params_(params) {}
        param_seq() : params_(new std::vector<param *>()) {}
};

class opt_params : public Base {
    public:
        param_seq *param_seq_;
        opt_params(param_seq *param_seq) : param_seq_(param_seq) {}
        opt_params() : param_seq_(new param_seq()) {}
};

class name_seq : public Base {
    public:
        std::vector<luna_string *> * names_;
        name_seq(std::vector<luna_string *> * names) : names_(names) {}
        name_seq() : names_(new std::vector<luna_string *>()) {}
};

class dfdecls : public Base {
    public:
        name_seq *name_seq_;
        dfdecls(name_seq *name_seq) : name_seq_(name_seq) {}
        dfdecls() : name_seq_(new name_seq()) {}
};

class opt_dfdecls : public Base {
    public:
        dfdecls *dfdecls_;
        opt_dfdecls(dfdecls *dfdecls) : dfdecls_(dfdecls) {}
        opt_dfdecls() : dfdecls_(new dfdecls()) {}
};

class statement : public Base {};

class statement_seq : public Base {
    public:
        std::vector<statement *>* statements_;
        statement_seq(std::vector<statement *>* statements) : statements_(statements) {}
        statement_seq() : statements_(new std::vector<statement *>()) {}
};

class behv_pragma : public Base {};

class behv_pragmas_seq : public Base {
    public:
        std::vector<behv_pragma*>* behv_pragma_;
        behv_pragmas_seq(std::vector<behv_pragma*>* behv_pragma) : behv_pragma_(behv_pragma) {}
        behv_pragmas_seq() : behv_pragma_(new std::vector<behv_pragma*>()) {}
};

class opt_behavior : public Base {
    public:
        behv_pragmas_seq *seq_;
        opt_behavior(behv_pragmas_seq *seq) : seq_(seq) {}
        opt_behavior() : seq_(new behv_pragmas_seq()) {}
};


class block : public Base {
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
};

class complex_id : public id {
    public:
        id *id_;
        expr *expr_;
        complex_id(id *id, expr *expr) : id_(id), expr_(expr) {}
        complex_id() : id_(new id()), expr_(new expr()) {}
};

class integer : public expr {
    public:
        int* value_;
        integer(int* value) : value_(value) {}
};

class real : public expr {
    public:
        double* value_;
        real(double* value) : value_(value) {} 
};

class luna_cast : public expr {
    public:
        expr *expr_;
        luna_cast(expr *expr) : expr_(expr) {}
};

class to_int : public luna_cast {};
class to_real : public luna_cast {};
class to_string : public luna_cast {};

class code_df_param : public Base {
    public:
        luna_string *type_;
        luna_string *code_df_;
        code_df_param(luna_string* type, luna_string* df) : type_(type), code_df_(df) {}
};

class ext_params_seq : public Base {
    public:
        std::vector<code_df_param *>* params_;
        ext_params_seq(std::vector<code_df_param *>* params) : params_(params) {}
        ext_params_seq() : params_(new std::vector<code_df_param *>()) {}
};

class opt_ext_params : public Base {
    public:
        ext_params_seq *seq_;
        opt_ext_params(ext_params_seq *seq) : seq_(seq) {}
        opt_ext_params() : seq_(new ext_params_seq()) {}
};

class bin_op : public expr {
    public:
        expr *left_;
        expr *right_;
        bin_op(expr *left, expr *right) : left_(left), right_(right) {}
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

class sub_def : public Base {};

class program : public Base {
    public:
        std::vector<sub_def *>* sub_defs;

        program(std::vector<sub_def *>* other) : sub_defs(other) {}

        program() : sub_defs(new std::vector<sub_def *>(0)) {}
};

class control_pragma : public Base {
    public:
        luna_string *where_type_;
        std::vector<expr *>* expr_;
        control_pragma(luna_string* other_type, std::vector<expr *>* other_expr) : where_type_(other_type), expr_(other_expr) {}
        control_pragma() : where_type_(new luna_string()), expr_(new std::vector<expr *>()) {}
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
};

class import_def : public sub_def {
    public:
        luna_string *cxx_code_id_;
        opt_ext_params *params_;
        luna_string *luna_code_id_;

        import_def(luna_string* cxx_id, opt_ext_params* params, luna_string* luna_id) 
            : cxx_code_id_(cxx_id), params_(params), luna_code_id_(luna_id) 
            {
                std::cerr << "import Ctor\n";
                std::cerr << cxx_code_id_->value_ << std::endl;
                std::cerr << params_->seq_ << std::endl;
                std::cerr << luna_code_id_->value_ << std::endl;
            }

        import_def() : cxx_code_id_(new luna_string()),
                        params_(new opt_ext_params()),
                        luna_code_id_(new luna_string()) {}
};

class import_def_cuda : public sub_def {
    public:
        luna_string *cxx_code_id_;
        opt_ext_params *params_;
        luna_string *luna_code_id;

        import_def_cuda(luna_string* cxx_id, opt_ext_params* params, luna_string* luna_id) 
            : cxx_code_id_(cxx_id), params_(params), luna_code_id(luna_id) {}
};

class import_def_cuda_nocpu : public sub_def {
    public:
        luna_string *cxx_code_id_;
        opt_ext_params *params_;
        luna_string *luna_code_id;

        import_def_cuda_nocpu(luna_string* cxx_id, opt_ext_params* params, luna_string* luna_id) 
            : cxx_code_id_(cxx_id), params_(params), luna_code_id(luna_id) {}
};

class cxx_block_with_params_def : public sub_def {
    public:
        luna_string *code_id_;
        opt_params *params_;

        cxx_block_with_params_def(luna_string* id, opt_params* params) 
            : code_id_(id), params_(params) {}
};

class cxx_block_def : public sub_def {
    public:
        luna_string *name_;
        cxx_block_def(luna_string* id) : name_(id) {}
};




class if_statement : public statement {
    public:
        expr *expr_;
        block *block_;
        if_statement(expr *expr, block *block) : block_(block), expr_(expr) {}
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
};

class assign : public Base {
    public:
        luna_string *name_;
        expr *expr_;
        assign(luna_string *name, expr *expr) : name_(name), expr_(expr) {}
};

class assign_seq : public Base {
    public:
        std::vector<assign* >* assign_seq_;
        assign_seq(std::vector<assign* >* assign_seq) : assign_seq_(assign_seq) {}
};

class let_statement : public statement {
    public:
        assign_seq *assign_seq_;
        block *block_;
        let_statement(assign_seq *assign_seq_, block *block) : assign_seq_(assign_seq_), block_(block) {}
};

class behv_pragma_seq : public behv_pragma {
    public:
        name_seq* name_seq_;
        behv_pragma_seq(name_seq* name_seq) : name_seq_(name_seq) {}
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
};
class exprs_seq : public Base {
    public:
        std::vector<expr* >* expr_;
        exprs_seq(std::vector<expr* >* expr) : expr_(expr) {}
};

class opt_exprs : public Base {
    public:
        exprs_seq *exprs_seq_;
        opt_exprs(exprs_seq *exprs_seq) : exprs_seq_(exprs_seq) {}
};

class opt_setdf_rules : public Base {
    public:
        opt_exprs *opt_exprs_;
        opt_setdf_rules(opt_exprs *opt_exprs) : opt_exprs_(opt_exprs) {}
};

class opt_label : public Base {
    public:
        id *id_;
        opt_label(id *id) : id_(id) {}
};

class opt_rules : public Base {
    public:
        opt_exprs *opt_exprs_;
        opt_rules(opt_exprs *opt_exprs) : opt_exprs_(opt_exprs) {}
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
};

class id_seq : public Base {
    public:
        std::vector<id*>* seq_;
        id_seq(std::vector<id*>* seq) : seq_(seq) {}
};

class behv_pragma_eq : public behv_pragma {
    public:
        luna_string *name_;
        id* id_;
        expr* expr_;
        behv_pragma_eq(luna_string *name, id* id, expr* expr) : name_(name), id_(id), expr_(expr) {}

};

class behv_pragma_eqg : public behv_pragma {
    public:
        luna_string *name_;
        id* id_;
        expr* expr_;
        behv_pragma_eqg(luna_string *name, id* id, expr* expr) : name_(name), id_(id), expr_(expr) {}
};

class behv_pragma_id_seq : public behv_pragma {
    public:
        luna_string *name_;
        id_seq *id_seq_;
        behv_pragma_id_seq(luna_string *name, id_seq *id_seq) : name_(name), id_seq_(id_seq) {}
};

class behv_pragma_expr : public behv_pragma {
    public:
        luna_string *name_;
        expr *expr_;
        behv_pragma_expr(luna_string *name, expr *expr) : expr_(expr), name_(name) {}
};

class behv_pragma_name_seq : public behv_pragma {
    public:    
        luna_string *name_;
        name_seq *seq_;
        behv_pragma_name_seq(luna_string *name, name_seq *seq) : name_(name), seq_(seq) {}
};

class opt_expr : public Base {
    public:
        exprs_seq *exprs_seq_;
        opt_expr(exprs_seq *exprs_seq) : exprs_seq_(exprs_seq) {}
};

class simple_id : public id {
    public:
        luna_string *name_;
        simple_id(luna_string * name) : name_(name) {}
};
#endif
