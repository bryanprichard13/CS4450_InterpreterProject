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
%token TOKEN_ADD
%token TOKEN_MINUS
%token TOKEN_MULTIPLY
%token TOKEN_DIVIDE
%token TOKEN_MOD
%token TOKEN_EXPO
%token TOKEN_LEFT
%token TOKEN_RIGHT

%left TOKEN_ADD TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIVIDE TOKEN_MOD TOKEN_EXPO

%type <expression> exp

%%

exp       : TOKEN_INT
          | TOKEN_FLOAT
          | TOKEN_STRING
          | exp TOKEN_ADD exp {}

TODO: Add expressions

%%
