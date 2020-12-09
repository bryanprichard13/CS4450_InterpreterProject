%{

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "arithmetic.h"
#include "statement.h"

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
     int                       int_value;
     float                   float_value;
     char*                        string;
     ArithmeticExpression*    expression;
     Statement*                statement;
}

%token <int_value>       TOKEN_INT
%token <float_value>     TOKEN_FLOAT
%token <string>    TOKEN_STRING
%token PLUSEQ  "+="
%token MINUSEQ "-="
%token TIMESEQ  "*="
%token DIVEQ   "/="
%token POWEQ   "^="
%token MODEQ   "%="


%left '+' '-'
%left '*' '/' '%' '^'
%nonassoc UMINUS

%type <expression> exp
%type <statement> statement
%type <statement> assign

%%

statement : assign
          ;

assign    : TOKEN_STRING '=' exp
            {
              $$ = new Assignment($1, $3);
              delete [] $1;
            }

          | TOKEN_STRING PLUSEQ exp
            {
              $$ = new Assignment($1, new Add(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING MINUSEQ exp
            {
              $$ = new Assignment($1, new Subtract(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING TIMESEQ exp
            {
              $$ = new Assignment($1, new Multiply(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING DIVEQ exp
            {
              $$ = new Assignment($1, new Divide(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING POWEQ exp
            {
              $$ = new Assignment($1, new Exponent(new Identity($1), $3));
              delete [] $1;
            }

          | TOKEN_STRING MODEQ exp
            {
              $$ = new Assignment($1, new Mod(new Identity($1), $3));
              delete [] $1;
            };

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
          | '-' exp %prec UMINUS { $$ = new Negative($2); };


%%
