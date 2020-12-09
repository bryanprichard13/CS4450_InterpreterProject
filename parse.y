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
     int                      int_value;
     float                    float_value;
     char*                    string;
     ArithmeticExpression*    expression;
     Statement*               statement;
}

%token <int_value>       TOKEN_INT
%token <float_value>     TOKEN_FLOAT
%token <string_value>    TOKEN_STRING

%left '+' '-'
%left '*' '/' '%' '^'
%nonassoc UMINUS

%type <expression> exp
%type <statement>  stmt

%%

exp       : 
            '(' exp ')'          { $$ = $2; }
          | TOKEN_INT            { $$ = new Constant($1); }
          | TOKEN_FLOAT          { $$ = new Constant($1); }
          | TOKEN_STRING         { $$ = new Identity($1); delete [] $1; }
          | exp '+' exp          { $$ = new Add($1, $3); }
          | exp '-' exp          { $$ = new Subtract($1, $3); }
          | exp '*' exp          { $$ = new Multiply($1, $3); }
          | exp '/' exp          { $$ = new Divide($1, $3); }
          | exp '%' exp          { $$ = new Mod($1, $3); }
          | exp '^' exp          { $$ = new Exponent($1, $3); }
          | '-' exp %prec UMINUS { $$ = new Negative($2); }


%%
