%{

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

extern int yylineno;
extern int yylex();
extern int yyparse();

%}

%union {
     int            int_value;     "int"
     float          float_value;   "float"
     char*          string         "string"
     Arithmetic*    expression   "expression"    
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

TODO: Add expressions

%%
