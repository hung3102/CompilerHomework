/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#ifndef _CHARCODE_H_
#define _CHARCODE_H_

typedef enum {
  CHAR_SPACE,           // space
  CHAR_LETTER,          // letter
  CHAR_DIGIT,           // digital
  CHAR_PLUS,            // '+'
  CHAR_MINUS,           // '-'
  CHAR_TIMES,           // '*'
  CHAR_SLASH,           // '/'
  CHAR_LT,              // '<'
  CHAR_GT,              // '>'
  CHAR_EXCLAIMATION,    // '!'
  CHAR_EQ,              // '='
  CHAR_COMMA,           // ','
  CHAR_PERIOD,          // '.'
  CHAR_COLON,           // ':'
  CHAR_SEMICOLON,       // ';'
  CHAR_SINGLEQUOTE,     // '\''
  CHAR_LPAR,            // '('
  CHAR_RPAR,            // ')'
  CHAR_UNKNOWN          // other characters
} CharCode;

extern CharCode charCodes[];

#endif /* _CHARCODE_H_ */
