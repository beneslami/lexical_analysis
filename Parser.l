%{

typedef struct lex_data_ {
    int token_code;
    int token_len;
    char *token_val;
}lex_data_t;

#define MAX_MEXPR_LEN 512
#define MAX_MEXPR_SIZE 512

typedef stuct stack_ {
    int top;
    lex_data_t data[MAX_MEXPR_LEN];
}stack_t;

extern "C" int yylex();

extern char lex_buffer[MAX_MEXPR_SIZE];
extern stack_t undo_stack;
extern char *curr_ptr;

stack_t undo_stack = {-1, {0, 0, 0}};
char lex_buffer[MAX_MEXPR_SIZE];
char *curr_ptr = lex_buffer;

static void lex_push(lex_data_t lex_data) {
    assert(undo_stack.top < MAX_MEXPR_LEN - 1);
    undo_stack.data[++undo_stack.top] = lex_data;
}

static lex_data_t lex_pop() {
    assert(undo_stack.top > -1);
    lex_data_t res = undo_stack.data[undo_stack.top];
    undo_stack.top--;
    return res;
}

#include "MexprEnums.h"

%}

%%

[ ] {
    //space
}

\n {
    // end of line
    return PARSER_EOL;
}

[\t] {
    // tab
}

0|-?[1-9][0-9]* {
    // integer value
    return MATH_CPP_INT;
}

-?[0-9]*\.[0-9]+ {
    // decimal number
    return MATH_CPP_DOUBLE;
}

[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]+ {
    // simple email test
    return MATH_CPP_EMAIL;
}

'[^']*' {
    // string enclosed within single quotes
    return MATH_CPP_SINGLE_QUOTED_STRING;
}

\"[^"]*\" {
    // string enclosed within double quotes
    return MATH_CPP_DOUBLE_QUOTED_STRING;
}

(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9]) {
    // IPv4 address
    return MATH_CPP_IPV4;
}

[a-zA-Z0-9_]+\.[a-zA-Z0-9_]+ {
    // variable with dot notation
    return MATH_CPP_VARIABLE;
}

[a-zA-Z0-9]+ {
    // simple variable/word
    return MATH_CPP_VARIABLE;
}

. {
    printf("ignore non-parsable character - %s\n", yytext);
}

%%

int main(int argc, char **argv) {
    while(1){
        fgets(lex_buffer, sizeof(lex_buffer), stdin);

        if(lex_buffer[0] == '\n') {
            lex_buffer[0] = 0;
            continue;
        }

        yy_scan_string(lex_buffer);

        int token_code;
        while((token_code = yylex()) != PARSER_EOL) {
            printf("Token Type = %s | token = %s, token length = %lu\n", stringTypes[token_code], yytext, yyleng);
        }
    }
    return 0;
}