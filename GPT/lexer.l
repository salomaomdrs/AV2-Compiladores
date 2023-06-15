%{
#include "parser.tab.h"
%}

%%
"if"       { return IF; }
"else"     { return ELSE; }
"while"    { return WHILE; }
"{"        { return '{'; }
"}"        { return '}'; }
"+"        { return '+'; }
"-"        { return '-'; }
"*"        { return '*'; }
"/"        { return '/'; }
"("        { return '('; }
")"        { return ')'; }
";"        { return ';'; }
[a-zA-Z][a-zA-Z0-9]* { yylval.strval = yytext; return ID; }
[0-9]+     { yylval.intval = atoi(yytext); return NUM; }
[ \t\n]    { /* Ignorar espaços em branco, tabulações e quebras de linha */ }
.          { yyerror("Caractere inválido"); }
%%

int yywrap() {
    return 1;
}
