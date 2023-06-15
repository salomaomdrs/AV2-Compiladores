%{
#include <stdio.h>
int yylex();
void yyerror(const char* message);
%}

%token IF ELSE WHILE ID NUM
%left '+' '-'
%left '*' '/'

%%
program: statement
        ;

statement: 'if' '(' expr ')' statement
         | 'if' '(' expr ')' statement 'else' statement
         | 'while' '(' expr ')' statement
         | '{' statement_list '}'
         | expr ';'
         ;

statement_list: statement
              | statement_list statement
              ;

expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | ID
    | NUM
    ;

%%
void yyerror(const char* message) {
    printf("Error: %s\n", message);
}

int main() {
    yyparse();
    return 0;
}
