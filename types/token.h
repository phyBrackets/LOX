#ifndef TYPES_TOKEN_H 
#define TYPES_TOKEN_H 
#pragma once 

#include <string>
#include "types/literal.h" 

enum class TokenType {
    // Single-character tokens 
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACES,
    COLON,
    COMMA,
    DOT,
    QUESTION,
    SEMICOLON,
    SLASH,
    STAR,

    //ONE OR TWO CHARACTER TOKENS
    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    LESS,
    LESS_EQUAL,
    MINUS,
    MINUS_MINUS,
    PLUS,
    PLUS_PLUS,

    //LITERALS
    IDENTIFIER,
    STRING,
    NUMBER,

    //KEYWORDS
    AND,
    CLASS,
    ELSE,
    LOX_FALSE,
    FUN,
    FOR,
    IF,
    NIL,
    OR,
    PRINT,
    RETURN,
    SUPER,
    THIS,
    LOX_TRUE,
    VAR,
    WHILE,

    LOX_EOF
};  

class Token {
    public: 
     Token(TokenType p_type, std::string p_lexeme, OptionalLiteral p_literal, int p_line);

     Token(TokenType p_type, const char* p_lexeme, OptionalLiteral p_literal, int p_line);

     Token(TokenType p_type, const char* p_lexeme);
     
     [[nodiscard]] auto toString() const -> std::string;
     [[nodiscard]] auto getType() const -> TokenType;
     [[nodiscard]] auto getTypeString() const -> const std::string&;
     [[nodiscard]] auto getLine() const -> int;
     [[nodiscard]] auto getLexeme() const -> const std::string&;
     [[nodiscard]] auto getOptionalLiteral() const -> const OptionalLiteral&;
    
    private: 
      const TokenType types;
      const std::string lexeme;
      OptionalLiteral literal = std::nullopt; 
      const int line = -1;

};

#endif 