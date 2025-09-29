#pragma once

typedef enum {
    /* Mathematical Operator*/
    MATH_CPP_OPR_FIRST,
    MATH_CPP_MOD,
    MATH_CPP_PLUS,
    MATH_CPP_MINUS,
    MATH_CPP_MUL,
    MATH_CPP_DIV,
    MATH_CPP_SQR,
    MATH_CPP_SQRT,
    MATH_CPP_MAX,
    MATH_CPP_MIN,
    MATH_CPP_SIN,
    MATH_CPP_COS,
    MATH_CPP_POW,
    
    /* Inequality Operator*/
    MATH_CPP_EQ,
    MATH_CPP_NEQ,
    MATH_CPP_LESS_THAN,
    MATH_CPP_LESS_THAN_EQ,
    MATH_CPP_GREATER_THAN,

    /* Logical Operators */
    MATH_CPP_OR,
    MATH_CPP_AND,

    /* Other entities which can appear in Math Expression*/
    MATH_CPP_BRACKET_START,
    MATH_CPP_BRACKET_END,
    MATH_CPP_COMMA,
    MATH_CPP_OPR_INVALID,
    MATH_CPP_SINGLE_QUOTED_STRING,
    MATH_CPP_DOUBLE_QUOTED_STRING,
    MATH_CPP_EMAIL,
    MATH_CPP_OPR_MAX,
} mexprcpp_operators_t;

typedef enum {
    MATH_CPP_DTYPE_FIRST = (int) MATH_CPP_OPR_MAX + 1,
    MATH_CPP_INT ,
    MATH_CPP_DOUBLE,
    MATH_CPP_STRING,
    MATH_CPP_IPV4,
    MATH_CPP_BOOL,
    MATH_CPP_VARIABLE,
    MATH_CPP_DTYPE_LAST,
    MATH_CPP_DTYPE_WILDCRAD,
    MATH_CPP_DTYPE_INVALID,
    MATH_CPP_DTYPE_MAX
} mexprcpp_dtypes_t;

/*const char *mexprcppOperatorsStringType[] = {
    "MATH_CPP_OPR_FIRST",
    "MATH_CPP_MOD",
    "MATH_CPP_PLUS",
    "MATH_CPP_MINUS",
    "MATH_CPP_MUL",
    "MATH_CPP_DIV",
    "MATH_CPP_SQR",
    "MATH_CPP_SQRT",
    "MATH_CPP_MAX",
    "MATH_CPP_MIN",
    "MATH_CPP_SIN",
    "MATH_CPP_COS",
    "MATH_CPP_POW",
    "MATH_CPP_EQ",
    "MATH_CPP_NEQ",
    "MATH_CPP_LESS_THAN",
    "MATH_CPP_LESS_THAN_EQ",
    "MATH_CPP_GREATER_THAN",
    "MATH_CPP_OR",
    "MATH_CPP_AND",
    "MATH_CPP_BRACKET_START",
    "MATH_CPP_BRACKET_END",
    "MATH_CPP_COMMA",
    "MATH_CPP_OPR_INVALID",
    "MATH_CPP_SINGLE_QUOTED_STRING",
    "MATH_CPP_DOUBLE_QUOTED_STRING",
    "MATH_CPP_EMAIL",
    "MATH_CPP_OPR_MAX",
};

const char *mexprcppDtypesStringType[] = {
    "MATH_CPP_DTYPE_FIRST",
    "MATH_CPP_INT",
    "MATH_CPP_DOUBLE",
    "MATH_CPP_STRING",
    "MATH_CPP_IPV4",
    "MATH_CPP_BOOL",
    "MATH_CPP_VARIABLE",
    "MATH_CPP_DTYPE_LAST",
    "MATH_CPP_DTYPE_WILDCRAD",
    "MATH_CPP_DTYPE_INVALID",
    "MATH_CPP_DTYPE_MAX",
};
*/