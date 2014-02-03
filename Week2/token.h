/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#ifndef _TOKEN_H_
#define _TOKEN_H_

#define MAX_IDENT_LEN 20
#define KEYWORDS_NUM 19

typedef enum {
  TK_NONE,           // error
  TK_IDENT,          // identify     
  TK_NUMBER,         // number
  TK_CHAR,           // character constant
  TK_EOF,            // end of file

  /* KEYWORDS */
  KW_PROGRAM, KW_CONST, KW_TYPE, KW_VAR,
  KW_INTEGER, KW_CHAR, KW_ARRAY, KW_OF,
  KW_FUNCTION, KW_PROCEDURE,
  KW_BEGIN, KW_END, KW_CALL,
  KW_IF, KW_THEN, KW_ELSE,
  KW_WHILE, KW_DO, KW_FOR, KW_TO,

  /* SPECIAL SYMBOLS */
  SB_SEMICOLON, SB_COLON, SB_PERIOD, SB_COMMA,
  SB_ASSIGN, SB_EQ, SB_NEQ, SB_LT, SB_LE, SB_GT, SB_GE,
  SB_PLUS, SB_MINUS, SB_TIMES, SB_SLASH,
  SB_LPAR, SB_RPAR, SB_LSEL, SB_RSEL
  } TokenType;

/* struct to store a token */
typedef struct {
  char string[MAX_IDENT_LEN + 1];
  int lineNo, colNo;
  TokenType tokenType;
  int value;
} Token;

// Check if a string is a keyword
extern TokenType checkKeyword(char *string);

extern char* getKeywordName(TokenType type);

extern char* getSymbolName(TokenType type);

// Create a new token with TokenType and position (line, col)
extern Token* makeToken(TokenType tokenType, int lineNo, int colNo);

#endif /* _TOKEN_H_ */
