all: bison flex analyzer

flex: lexics.l
	lex lexics.l

bison: grammar.ypp
	bison -d grammar.ypp

analyzer: grammar.tab.cpp lex.yy.c main.cpp
	g++ -std=c++11 lex.yy.c grammar.tab.cpp main.cpp ast_analyzer.cpp -o a.out -fsanitize=address

clean: 
	rm grammar.tab.cpp  grammar.tab.hpp lex.yy.c  

