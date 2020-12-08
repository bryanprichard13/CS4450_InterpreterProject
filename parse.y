%{

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using std::cerr;
using std::endl;

extern int yylineno;
extern int yylex();
extern int yyparse();

bool error = false;

void yyerror(const char* s) {
   // bision seems to call both versions of yyerror, check a flag to supress the duplicate message
   if (!error) {
      cerr << "error (line " << yylineno << "): " << s << endl;
   }
}

void yyerror(const char* s, char c) {
   cerr << "error (line " << yylineno << "): " << s << " \"" << c << "\"" << endl;
   error = true;
}
%}

%union {
     int            int_value;
     float          float_value;
     char*          string;
}

%token <int_value>       TOKEN_INT
%token <float_value>     TOKEN_FLOAT
%token <string_value>    TOKEN_STRING

%left '+' '-'
%left '*' '/' '%' '^'

%type <expression> exp

%%

exp       : TOKEN_INT
          | TOKEN_FLOAT
          | TOKEN_STRING
          | exp '+' exp {}


%%
