#ifndef __LEX_H
#define __LEX_H

#include <iostream>

#define BLOCK_SIZE          1024

#define LEX_DISCARD_TOKEN   0

#define CONTINUE_LEX        0
#define END_LEX		        -1

struct token {
    int token;
    std::string lexeme;
};

class Lexer {
public:
    Lexer(DFA dfa);

    /* Initializes the lexer to a given input stream (usually a file) */
    void init(std::istream *stream, int size);

    /* Gets the next token (CONTINUE_LEX), or END_LEX if none exists */
    int next_token(struct token &token);

    /* Gets the current line number and line position */
    int line_number();
    int position();

private:
    DFA dfa;

    std::istream *in;
    char *buffer, *forward, *back;

    int line = 0, pos = 0;

    char cur_char();
    char next_char();
    void retreat(int num);
    std::string matched_lexeme();
};

#endif