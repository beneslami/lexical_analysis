%{
extern "C" int yylex();

extern char lex_buffer[512];

char lex_buffer[512];

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
            printf("Token Code = %d | token = %s, token length = %lu\n", token_code, yytext, yyleng);
        }
    }
    return 0;
}