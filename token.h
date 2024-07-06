#ifndef CREPL_TOKEN_H
#define CREPL_TOKEN_H

/**
 * Author: Akash Lohar
 *
 * token.h defines the token_t enum which represents the different types of
 * tokens
 */

typedef enum {
    TOKEN_ILLEGAL = 0,
    TOKEN_EOF,

    /* literals */
    TOKEN_IDENT,
    TOKEN_LIT_DECIMAL_INT,
    TOKEN_LIT_OCTAL_INT,
    TOKEN_LIT_HEX_INT,
    TOKEN_LIT_BIN_INT,
    TOKEN_LIT_FLOAT,
    TOKEN_LIT_CHAR,
    TOKEN_LIT_STR,

    /* arithmetic operators */
    TOKEN_ADD,  // +
    TOKEN_SUB,  // -
    TOKEN_STAR, // *
    TOKEN_DIV,  // /
    TOKEN_REM,  // %

    /* assignments */
    TOKEN_ASSIGN, // =

    /* logical operators */
    TOKEN_EQUAL,         // ==
    TOKEN_NOT_EQUAL,     // !=
    TOKEN_LESS_THAN,     // <
    TOKEN_GREATER_THAN,  // >
    TOKEN_LESS_EQUAL,    // <=
    TOKEN_GREATER_EQUAL, // >=
    TOKEN_LOGICAL_NOT,   // !
    TOKEN_LOGICAL_AND,   // &&
    TOKEN_LOGICAL_OR,    // ||

    /* bitwise operators */
    TOKEN_AND, // &
    TOKEN_OR,  // |
    TOKEN_XOR, // ^

    /* shift operators */
    TOKEN_SHIFT_LEFT,  // <<
    TOKEN_SHIFT_RIGHT, // >>

    /* increment and decrement */
    TOKEN_INCREMENT, // ++
    TOKEN_DECREMENT, // --

    /* delimiters */
    TOKEN_COMMA,     // ,
    TOKEN_SEMICOLON, // ;

    /* parentheses */
    TOKEN_LEFT_PARENTHESES,  // (
    TOKEN_LEFT_CURLY_BRACE,  // {
    TOKEN_LEFT_BRACKET,      // [
    TOKEN_RIGHT_PARENTHESES, // )
    TOKEN_RIGHT_CURLY_BRACE, // }
    TOKEN_RIGHT_BRACKET,     // ]

    /* keywords */
    TOKEN_KW_AUTO,
    TOKEN_KW_BREAK,
    TOKEN_KW_CASE,
    TOKEN_KW_CHAR,
    TOKEN_KW_CONST,
    TOKEN_KW_CONTINUE,
    TOKEN_KW_DEFAULT,
    TOKEN_KW_DO,
    TOKEN_KW_DOUBLE,
    TOKEN_KW_ELSE,
    TOKEN_KW_ENUM,
    TOKEN_KW_EXTERN,
    TOKEN_KW_FLOAT,
    TOKEN_KW_FOR,
    TOKEN_KW_GOTO,
    TOKEN_KW_IF,
    TOKEN_KW_INLINE,
    TOKEN_KW_INT,
    TOKEN_KW_LONG,
    TOKEN_KW_REGISTER,
    TOKEN_KW_RETURN,
    TOKEN_KW_SHORT,
    TOKEN_KW_SIGNED,
    TOKEN_KW_SIZEOF,
    TOKEN_KW_STATIC,
    TOKEN_KW_STRUCT,
    TOKEN_KW_SWITCH,
    TOKEN_KW_TYPEDEF,
    TOKEN_KW_UNION,
    TOKEN_KW_UNSIGNED,
    TOKEN_KW_VOID,
    TOKEN_KW_VOLATILE,
    TOKEN_KW_WHILE,

    /*  // will think about these later
    TOKEN_KW_ALIGNAS,
    TOKEN_KW_ALIGNOF,
    TOKEN_KW_ATOMIC,
    TOKEN_KW_BOOL,
    TOKEN_KW_COMPLEX,
    TOKEN_KW_GENERIC,
    TOKEN_KW_IMAGINARY,
    TOKEN_KW_NORETURN,
    TOKEN_KW_STATIC_ASSERT,
    TOKEN_KW_THREAD_LOCAL
    */

} token_t;

#endif // CREPL_TOKEN_H