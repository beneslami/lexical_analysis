#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "ParserExport.h"
#include "MexprEnums.h"

parse_rc_t circle_eqn () {
    parse_init() ;
    int x_pos, y_pos;
    token_code = cyylex();
    if (token_code != MATH_CPP_POW) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_POW)
    token_code = cyylex();
    if (token_code != MATH_CPP_BRACKET_START) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_BRACKET_START)
    token_code = cyylex ();
    if (token_code != MATH_CPP_VARIABLE) {
        RETURN_PARSE_ERROR;
    }
    if (strcmp (lex_curr_token, "x") != 0) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_VARIABLE)
    token_code = cyylex ();
    if (token_code != MATH_CPP_COMMA) {
       RETURN_PARSE_ERROR;
    }
    token_code = cyylex ();
    if (token_code != MATH_CPP_INT) {
       RETURN_PARSE_ERROR;
    }
    x_pos = atoi(lex_curr_token);
    //PARSER_LOG_ERR(token_code, MATH_CPP_INT)
    token_code = cyylex();
    if (token_code != MATH_CPP_BRACKET_END) {
        RETURN_PARSE_ERROR;
    }
    token_code = cyylex();
    if (token_code != MATH_CPP_PLUS) {
       RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_PLUS)
    token_code = cyylex();
    if (token_code != MATH_CPP_POW) {
        RETURN_PARSE_ERROR;
    }
    token_code = cyylex();
    if (token_code != MATH_CPP_BRACKET_START) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_BRACKET_START)
    token_code = cyylex ();
    if (token_code != MATH_CPP_VARIABLE) {
        RETURN_PARSE_ERROR;
    }
    if (strcmp (lex_curr_token, "y") != 0) {
       RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_VARIABLE)
    token_code = cyylex ();
    if (token_code != MATH_CPP_COMMA) {
        RETURN_PARSE_ERROR;
    }
    token_code = cyylex ();
    if (token_code != MATH_CPP_INT) {
        RETURN_PARSE_ERROR;
    }
    y_pos = atoi(lex_curr_token);
    //PARSER_LOG_ERR(token_code, MATH_CPP_INT)
    token_code = cyylex();
    if (token_code != MATH_CPP_BRACKET_END) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_BRACKET_END)
   token_code = cyylex();
   if (token_code != MATH_CPP_EQ) {
        RETURN_PARSE_ERROR;
   }
   token_code = cyylex();
   if (token_code != MATH_CPP_INT && token_code != MATH_CPP_DOUBLE) {
            RETURN_PARSE_ERROR;
    }
    if(x_pos != y_pos) {
        RETURN_PARSE_ERROR;
    }
    RETURN_PARSE_SUCCESS;
}

parse_rc_t ellipse_eqn () {
    parse_init();
    int x_pos, y_pos;
    token_code = cyylex();
    if (token_code != MATH_CPP_POW) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_POW)
    token_code = cyylex();
    if (token_code != MATH_CPP_BRACKET_START) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_BRACKET_START)
    token_code = cyylex ();
    if (token_code != MATH_CPP_VARIABLE) {
        RETURN_PARSE_ERROR;
    }
    if (strcmp (lex_curr_token, "x") != 0) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_VARIABLE)
    token_code = cyylex ();
    if (token_code != MATH_CPP_COMMA) {
       RETURN_PARSE_ERROR;
    }
    token_code = cyylex ();
    if (token_code != MATH_CPP_INT) {
       RETURN_PARSE_ERROR;
    }
    x_pos = atoi(lex_curr_token);
    //PARSER_LOG_ERR(token_code, MATH_CPP_INT)
    token_code = cyylex();
    if (token_code != MATH_CPP_BRACKET_END) {
        RETURN_PARSE_ERROR;
    }
    token_code = cyylex();
    if (token_code != MATH_CPP_PLUS) {
       RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_PLUS)
    token_code = cyylex();
    if (token_code != MATH_CPP_POW) {
        RETURN_PARSE_ERROR;
    }
    token_code = cyylex();
    if (token_code != MATH_CPP_BRACKET_START) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_BRACKET_START)
    token_code = cyylex ();
    if (token_code != MATH_CPP_VARIABLE) {
        RETURN_PARSE_ERROR;
    }
    if (strcmp (lex_curr_token, "y") != 0) {
       RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_VARIABLE)
    token_code = cyylex ();
    if (token_code != MATH_CPP_COMMA) {
        RETURN_PARSE_ERROR;
    }
    token_code = cyylex ();
    if (token_code != MATH_CPP_INT) {
        RETURN_PARSE_ERROR;
    }
    y_pos = atoi(lex_curr_token);
    //PARSER_LOG_ERR(token_code, MATH_CPP_INT)
    token_code = cyylex();
    if (token_code != MATH_CPP_BRACKET_END) {
        RETURN_PARSE_ERROR;
    }
    //PARSER_LOG_ERR(token_code, MATH_CPP_BRACKET_END)
   token_code = cyylex();
   if (token_code != MATH_CPP_EQ) {
        RETURN_PARSE_ERROR;
   }
   token_code = cyylex();
   if (token_code != MATH_CPP_INT && token_code != MATH_CPP_DOUBLE) {
            RETURN_PARSE_ERROR;
    }
    if(x_pos == y_pos) {
        RETURN_PARSE_ERROR
    }
    RETURN_PARSE_SUCCESS;
}

void Parse_Equations() {
    parse_rc_t rc = circle_eqn();
    if (rc == PARSE_SUCCESS) {
        printf ("Equation of Circle\n");
    }
    else{
        rc = ellipse_eqn();
        if (rc == PARSE_SUCCESS) {
            printf ("Equation of Ellipse\n");
        }
        else {
            printf("Invalid Equation\n");
        }
    }
}