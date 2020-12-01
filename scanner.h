//
// Created by User on 10/31/2020.
//

#ifndef WLP4SCANNER_SCANNER_H
#define WLP4SCANNER_SCANNER_H


//
// Created by User on 10/8/2020.
//

#ifndef CS241_SCANNER_H
#define CS241_SCANNER_H
#include <string>
#include <vector>
#include <set>
#include <cstdint>
#include <ostream>

/*
 * C++ Starter code for CS241 A3
 * All code requires C++14, so if you're getting compile errors make sure to
 * use -std=c++14.
 *
 * This file contains helpers for asm.cc and should not need to be modified by
 * you. However, its comments contain important information and you should
 * read the entire file before you start modifying asm.cc.
 */

class Token;

/* Scans a single line of input and produces a list of tokens.
 *
 * Scan returns tokens with the following kinds:
 * ID: identifiers and keywords.
 * LABEL: labels (identifiers ending in a colon).
 * WORD: the special ".word" keyword.
 * COMMA: a comma.
 * LPAREN: a left parenthesis.
 * RPAREN: a right parenthesis.
 * INT: a signed or unsigned 32-bit integer written in decimal.
 * HEXINT: an unsigned 32-bit integer written in hexadecimal.
 * REG: a register between $0 and $31.
 */

std::vector<Token> scan(const std::string &input);

/* A scanned token produced by the scanner.
 * The "kind" tells us what kind of token it is
 * while the "lexeme" tells us exactly what text
 * the programmer typed. For example, the token
 * "abc" might have kind "ID" and lexeme "abc".
 *
 * While you can create tokens with any kind and
 * lexeme, the list of kinds produced by the
 * starter code can be found in the documentation
 * for scan above.
 */
class Token {
public:
    enum Kind {
        ID = 0,
        LABEL,
        WORD,
        COMMA,
        LPAREN,
        RPAREN,
        NUM,
        REG,
        WHITESPACE,
        LBRACE,
        RBRACE,
        LBRACKET,
        RBRACKET,
        INT,
        ELSE,
        WHILE,
        WAIN,
        NULA,
        NEW,
        RETURN,
        DELETE,
        IF,
        PRINTLN,
        COMMENT,
        ZERO,
        SLASH,
        MINUS,
        BECOMES,
        EQ,
        NEQ,
        LT,
        GT,
        LE,
        GE,
        PLUS,
        STAR,
        AMP,
        PCT,
        SEMI,
    };

private:
    Kind kind;
    std::string lexeme;

public:
    Token(Kind kind, std::string lexeme);

    Kind getKind() const;
    const std::string &getLexeme() const;

    /* Only works on tokens of type INT, HEXINT, or REG
     *
     * Although all results will be integers, this function
     * returns a long since the result may be either signed
     * or unsigned, and thus may lie anywhere in the range
     * -2147483648 .. 4294967295
     */
    int64_t toLong() const;

};

std::ostream &operator<<(std::ostream &out, const Token &tok);

/* An exception class thrown when an error is encountered while scanning.
 */
class ScanningFailure {
    std::string message;

public:
    ScanningFailure(std::string message);

    // Returns the message associated with the exception.
    const std::string &what() const;
};

#endif



#endif //WLP4SCANNER_SCANNER_H
