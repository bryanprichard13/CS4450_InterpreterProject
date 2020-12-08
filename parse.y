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

exp       : 
            '(' exp ')'    { $$ = $2; }
          | TOKEN_INT      { $$ = new Constant($1); }
          | TOKEN_FLOAT    { $$ = new Constant($1); }
          | TOKEN_STRING   { $$ = new Identity($1); delete [] $1; }
          | exp '+' exp    { $$ = new Addition($1, $3); }
          | exp '-' exp    { $$ = new Subtraction($1, $3); }
          | exp '*' exp    { $$ = new Multiplication($1, $3); }
          | exp '/' exp    { $$ = new Division($1, $3); }
          | exp '%' exp    { $$ = new Modulus($1, $3); }
          | exp '^' exp    { $$ = new Exponent($1, $3); }


%%
