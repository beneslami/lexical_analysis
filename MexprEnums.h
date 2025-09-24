#pragma once

typedef enum {
    MATH_CPP_INT,
    MATH_CPP_DOUBLE,
    MATH_CPP_VARIABLE,
    MATH_CPP_IPV4,
    MATH_CPP_EMAIL,
    MATH_CPP_SINGLE_QUOTED_STRING,
    MATH_CPP_DOUBLE_QUOTED_STRING,
    
    MATH_CPP_DTYPE_MAX
} mexprcpp_dtypes_t;

typedef enum {
    PARSER_EOL = (int)MATH_CPP_DTYPE_MAX + 1
}EXTRA_ENUMS;