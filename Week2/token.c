/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "token.h"

typedef struct {
  char string[MAX_IDENT_LEN + 1];
  TokenType keywordType;
} Keyword;

Keyword keywords[KEYWORDS_NUM] = {
  {"PROGRAM", KW_PROGRAM},
  {"CONST", KW_CONST},
  {"TYPE", KW_TYPE},
  {"VAR", KW_VAR},
  {"INTEGER", KW_INTEGER},
  {"CHAR", KW_CHAR},
  {"PROCEDURE", KW_PROCEDURE},
  {"FUNCTION", KW_FUNCTION},
  {"BEGIN", KW_BEGIN},
  {"END", KW_END},
  {"ARRAY", KW_ARRAY},
  {"OF", KW_OF},
  {"CALL", KW_CALL},
  {"IF", KW_IF},
  {"ELSE", KW_ELSE},
  {"WHILE", KW_WHILE},
  {"DO", KW_DO},
  {"FOR", KW_FOR},
  {"TO", KW_TO}
};

int compare(char* str1, char* str2){
  while(*str1 != '\0' && *str2 != '\0'){
    if (toupper(*str1) == toupper(*str2)){
      str1++;
      str2++;
    } else 
      return 0;
  }
  if (*str1 == '\0' && *str2 == '\0')
    return 1;  
  else 
    return 0;
}

TokenType checkKeyword(char *string){
  int i;
  for (i = 0; i < KEYWORDS_NUM; i++){
    if (compare(string, keywords[i].string))
      return keywords[i].keywordType;   
  }
  return TK_NONE;
}

char* getKeywordName(TokenType type){
  switch(type){
  case KW_PROGRAM:
    return "KW_PROGRAM";
  case KW_CONST:
    return "KW_CONST";
  case KW_TYPE:
    return "KW_TYPE";
  case KW_VAR:
    return "KW_VAR";
  case KW_INTEGER:
    return "KW_INTEGER";
  case KW_CHAR:
    return "KW_CHAR";
  case KW_PROCEDURE:
    return "KW_PROCEDURE";
  case KW_FUNCTION: 
    return "KW_FUNCTION";
  case KW_BEGIN:
    return "KW_BEGIN";
  case KW_END:
    return "KW_END";
  case KW_ARRAY: 
    return "KW_ARRAY";
  case KW_OF: 
    return "KW_OF";
  case KW_CALL:
    return "KW_CALL";
  case KW_IF:
    return "KW_IF";
  case KW_ELSE:
    return "KW_ELSE";
  case KW_WHILE:
    return "KW_WHILE";
  case KW_DO:
    return "KW_DO";
  case KW_FOR:
    return "KW_FOR";
  case KW_TO:
    return "KW_TO";
  default:
    return NULL;
  }
}

char* getSymbolName(TokenType type){
  switch(type){
  case SB_SEMICOLON:
    return "SB_SEMICOLON";
  case SB_COLON:
    return "SB_COLON";
  case SB_PERIOD:
    return "SB_PERIOD";
  case SB_COMMA:
    return "SB_COMMA";
  case SB_ASSIGN:
    return "SB_ASSIGN";
  case SB_EQ:
    return "SB_EQ";
  case SB_NEQ:
    return "SB_NEQ";
  case SB_LT:
    return "SB_LT";
  case SB_LE:
    return "SB_LE";
  case SB_GT:
    return "SB_GT";
  case SB_GE:
  return "SB_GE";
  case SB_PLUS:
    return "SB_PLUS";
  case SB_MINUS:
    return "SB_MINUS";
  case SB_TIMES:
    return "SB_TIMES";
  case SB_SLASH:
    return "SB_SLASH";
  case SB_LPAR:
    return "SB_LPAR";
  case  SB_RPAR:
    return "SB_RPAR";
  case SB_LSEL:
    return "SB_LSEL";
  case  SB_RSEL:
    return "SB_LSEL";
  default:
    return NULL;
  }
}

Token* makeToken(TokenType tokenType, int lineNo, int colNo){
  Token* newTok = (Token*)malloc(sizeof(Token));
  newTok->tokenType = tokenType;
  newTok->lineNo = lineNo;
  newTok->colNo = colNo;
  return newTok;
}
