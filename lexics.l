%{
#include "ast.hpp"
#include "grammar.tab.hpp"
#include <string>
#include <cstring>

void yyerror(const char*);
extern "C" int yywrap() { return 1; }
using namespace std;

#define SAVE_TOKEN yylval.string_ = new luna_string(new std::string(yytext))
%}

%%
as {  return KW_AS; }
cf {  return KW_CF; }
df {  return KW_DF; }
import { return KW_IMPORT; }
for {  return KW_FOR; }
if {  return KW_IF; }
else {  return KW_ELSE; }
let {  return KW_LET; }
in {  return KW_IN; }
out {  return KW_OUT; }
SIZE {  return KW_SIZE; }
sub {  return KW_SUB; }
while {  return KW_WHILE; }
int {  return KW_INT; }
real {  return KW_REAL; }
string {  return KW_STRING; }
name {  return KW_NAME; }
value {  return KW_VALUE; }
rush {  return KW_RUSH; }
static {  return KW_STATIC; }
static_for {  return KW_STATIC_FOR; }
unrolling {  return KW_UNROLLING; }
CUDA {  return KW_CUDA;}
NOCPU {  return KW_NOCPU;}

"$" {  return BUCK; }
"&" {  return AMP; }
"=" {  return EQ; }
"<" {  return LT; }
">" {  return GT; }
";" {  return SCOLON; }
":" {  return COLON; }
"?" {  return QMARK; }
"," {  return COMMA; }
"." {  return DOT; }
".." {  return DIAP; }
"{" {  return LCB; }
"}" {  return RCB; }
"(" {  return LB; }
")" {  return RB; }
"[" {  return LSB; }
"]" {  return RSB; }
"+" {  return PLUS; }
"-" {  return MINUS; }
"*" {  return MUL; }
"/" {  return DIV; }
"%" {  return MOD; }
"#" {  return SHARP; }
"@" {  return AT; }
"==" {  return DBLEQ; }
"<=" {  return LEQ; }
"=>" {  return EQG; }
">=" {  return GEQ; }
"!=" {  return NEQ; }
"&&" {  return DBLAMP; }
"||" {  return DBLPIPE; }
"-->" {  return ARROW; }
"<--" {  return LARROW; }
"<<" {  return LARR; }
">>" {  return RARR; }
"C++" {  return KW_CPP; }
"__block" {  return KW_BLOCK; }

[0-9]+ { return INT; }

[0-9]+"."[0-9]+ { return REAL;}

\/\/.*$ { }
\"[^\"]*\" { return STRING; }

[A-Za-z_][A-Za-z0-9_]* {
	SAVE_TOKEN;
 	return NAME;
}

\n {}

[ \t]+ { }

. { yyerror("invalid symbol"); }

%%

void yyerror(const char* msg) {
	printf("%s\n", msg);
}