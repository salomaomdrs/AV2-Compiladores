#include <stdio.h>
#include <stdlib.h>

// Definição dos tokens
#define NUM 256
#define ID 257
#define PLUS 258
#define MINUS 259
#define MULT 260
#define DIV 261
#define LPAREN 262
#define RPAREN 263
#define SEMICOLON 264
#define ASSIGN 265
#define END 266

int lookahead;

void expr();
void term();
void factor();
void match(int token);

void error(const char* message) {
    fprintf(stderr, "Erro: %s\n", message);
    exit(1);
}

void getToken() {
    lookahead = getchar();
}

void expr() {
    term();
    while (1) {
        if (lookahead == PLUS) {
            match(PLUS);
            term();
            printf("+ ");
        } else if (lookahead == MINUS) {
            match(MINUS);
            term();
            printf("- ");
        } else {
            return;
        }
    }
}

void term() {
    factor();
    while (1) {
        if (lookahead == MULT) {
            match(MULT);
            factor();
            printf("* ");
        } else if (lookahead == DIV) {
            match(DIV);
            factor();
            printf("/ ");
        } else {
            return;
        }
    }
}

void factor() {
    if (lookahead == NUM) {
        printf("%c ", lookahead);
        match(NUM);
    } else if (lookahead == ID) {
        printf("%c ", lookahead);
        match(ID);
    } else if (lookahead == LPAREN) {
        match(LPAREN);
        expr();
        match(RPAREN);
    } else {
        error("Expressão inválida");
    }
}

void match(int token) {
    if (lookahead == token) {
        getToken();
    } else {
        error("Token inválido");
    }
}

int main() {
    printf("Digite uma expressão: ");
    getToken();
    expr();
    match(END);
    printf("\nExpressão válida!\n");
    return 0;
}
