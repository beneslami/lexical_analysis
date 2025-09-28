#pragma once

#include <cassert>

typedef struct lex_data_ {
    int token_code;
    int token_len;
    char *token_val;
}lex_data_t;

#define MAX_MEXPR_LEN 512
#define MAX_MEXPR_SIZE 512
#define PARSER_WHITE_SPACE 10002

typedef struct stack_ {
    int top;
    lex_data_t data[MAX_MEXPR_LEN];
}stack_tt;

extern "C" int yylex();

extern char lex_buffer[MAX_MEXPR_SIZE];
extern stack_tt undo_stack;
extern int cyylex();
extern void yyrewind(int n);


extern char *curr_ptr;
extern char *lex_curr_token;
extern int lex_curr_token_len;
extern void RESTORE_CHKP(int a);

stack_tt undo_stack = {-1, {0, 0, 0}};
#define CHECKPOINT(a)   a = undo_stack.top
//#define RESTORE_CHKP(a)  yyrewind(undo_stack.top - a)