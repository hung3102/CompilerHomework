/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "charcode.h"
#include "token.h"
#include "reader.h"
#include "error.h"

void skipBlank(){
  while (currentChar != EOF && charCodes[currentChar] == CHAR_SPACE){
    readChar();
  }
}

void skipComment(){
  CharCode waitCharCode = CHAR_TIMES;
  while (readChar() != EOF){
    if (charCodes[currentChar] == waitCharCode){
      if (waitCharCode == CHAR_TIMES){
	waitCharCode = CHAR_RPAR;
      } else {
	readChar();
	return;
      }
    } else if (waitCharCode != CHAR_TIMES && charCodes[currentChar] != CHAR_TIMES){
      waitCharCode = CHAR_TIMES;
    }	
  }
    
  error(ERR_ENDOFCOMMENT, lineNo, colNo);     
}

Token* readIdentKeyword(void){
  Token* token;
  char string[MAX_IDENT_LEN+1];
  int ln = lineNo, cn = colNo;
  int i = 0;
  do{
    if (i < MAX_IDENT_LEN)    string[i++] = currentChar;    
    readChar();
  } while(currentChar != EOF && (charCodes[currentChar] == CHAR_LETTER || charCodes[currentChar] == CHAR_DIGIT) );
  if (i < MAX_IDENT_LEN){
    string[i] = '\0';
    TokenType kwType = checkKeyword(string);
    if (kwType == TK_NONE)
      token = makeToken(TK_IDENT, ln, cn);
    else 
      token = makeToken(kwType, ln, cn);
    strcpy(token->string,string);
  } else {
    error(ERR_IDENTTOOLONG, ln, cn);
    token = makeToken(TK_NONE, ln, cn);
  }
  return token;
}

Token* readNumber(void){
  Token* token;
  char string[MAX_IDENT_LEN];
  int ln = lineNo, cn = colNo;
  int i = 0;

  do{
    if (i < MAX_IDENT_LEN)  string[i++] = currentChar;    
    readChar();
  } while(currentChar != EOF && charCodes[currentChar] == CHAR_DIGIT);

  if (i < MAX_IDENT_LEN){
    string[i] = '\0';
    token = makeToken(TK_NUMBER, ln, cn);
    strcpy(token->string,string);
    token->value = atoi(string);
  } else {
    token = makeToken(TK_NONE, ln, cn);
  }
  return token;
}

Token* readConstChar(void){
  Token *token = makeToken(TK_CHAR, lineNo, colNo);

  readChar();
  if (currentChar == EOF) {
    token->tokenType = TK_NONE;
    error(ERR_INVALIDCHARCONSTANT, token->lineNo, token->colNo);
    return token;
  }
    
  token->string[0] = currentChar;
  token->string[1] = '\0';

  readChar();
  if (currentChar == EOF) {
    token->tokenType = TK_NONE;
    error(ERR_INVALIDCHARCONSTANT, token->lineNo, token->colNo);
    return token;
  }

  if (charCodes[currentChar] == CHAR_SINGLEQUOTE) {
    readChar();
    return token;
  } else {
    token->tokenType = TK_NONE;
    error(ERR_INVALIDCHARCONSTANT, token->lineNo, token->colNo);
    return token;
  }
}

Token* getToken(void){
  Token *token;
  int ln, cn;
  if (currentChar == EOF)
    return makeToken(TK_EOF, lineNo, colNo);
  switch (charCodes[currentChar]) {
  case CHAR_SPACE: skipBlank(); return getToken();
  case CHAR_LETTER: return readIdentKeyword();
  case CHAR_DIGIT: return readNumber();
  case CHAR_PLUS:
    token = makeToken(SB_PLUS, lineNo, colNo);
    readChar();
    return token;
  case CHAR_MINUS:
    token = makeToken(SB_MINUS, lineNo, colNo);
    readChar();
    return token;
  case CHAR_TIMES:
    token = makeToken(SB_TIMES, lineNo, colNo);
    readChar();
    return token;
  case CHAR_SLASH:
    token = makeToken(SB_SLASH, lineNo, colNo);
    readChar();
    return token;
  case CHAR_LT:
    ln = lineNo;
    cn = colNo;
    readChar();
    if (currentChar != EOF && charCodes[currentChar] == CHAR_EQ){
      token = makeToken(SB_LE, ln, cn);
      readChar();
    } else {
      token = makeToken(SB_LT, lineNo, colNo);
    }
    return token;
  case CHAR_GT:
    ln = lineNo;
    cn = colNo;
    readChar();
    if (currentChar != EOF && charCodes[currentChar] == CHAR_EQ){
      token = makeToken(SB_GE, ln, cn);
      readChar();
    } else {
      token = makeToken(SB_GT, lineNo, colNo);
    }
    return token;
  case CHAR_EXCLAIMATION:
    ln = lineNo;
    cn = colNo;
    readChar();
    if (currentChar != EOF && charCodes[currentChar] == CHAR_EQ){
      token = makeToken(SB_NEQ, ln, cn);
      readChar();
    } else {
      error(ERR_INVALIDSYMBOL,ln,cn);
      token = makeToken(TK_NONE, ln, cn);
      readChar();
    }
    return token;
  case CHAR_EQ:
    token = makeToken(SB_EQ, lineNo, colNo);
    readChar();
    return token;
  case CHAR_COMMA:
    token = makeToken(SB_COMMA, lineNo, colNo);
    readChar();
    return token;
  case CHAR_PERIOD:
    ln = lineNo;
    cn = colNo;
    readChar();
    if (currentChar != EOF && charCodes[currentChar] == CHAR_RPAR){
      token = makeToken(SB_RSEL, lineNo, colNo);
      readChar();
    } else {
      token = makeToken(SB_PERIOD, ln, cn);
    }
    return token;
  case CHAR_COLON:
    ln = lineNo;
    cn = colNo;
    readChar();
    if (currentChar != EOF && charCodes[currentChar] == CHAR_EQ){
      token = makeToken(SB_ASSIGN, ln, cn);
      readChar();
    } else {
      token = makeToken(SB_COLON, ln, cn);
    }
    return token;
  case CHAR_SEMICOLON:
    token = makeToken(SB_SEMICOLON, lineNo, colNo);
    readChar();
    return token;
  case CHAR_SINGLEQUOTE: return readConstChar();
  case CHAR_LPAR:
    ln = lineNo;
    cn = colNo;
    readChar();
    if ( currentChar != EOF && charCodes[currentChar] == CHAR_PERIOD){
      token = makeToken(SB_LSEL, ln, cn);
      readChar();
    } else if (currentChar != EOF && charCodes[currentChar] == CHAR_TIMES){
      skipComment();
      return getToken();
    } else {
      token = makeToken(SB_LPAR, ln, cn);
    }
    return token;
  case CHAR_RPAR:
    token = makeToken(SB_RPAR, lineNo, colNo);
    readChar();
    return token;  
  case CHAR_UNKNOWN:
    error(ERR_INVALIDSYMBOL,lineNo,colNo);
    token = makeToken(TK_NONE, lineNo, colNo);
    return token;  
  }
  return makeToken(TK_NONE, lineNo, colNo);
}
