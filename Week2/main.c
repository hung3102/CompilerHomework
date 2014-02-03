/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "token.h"
#include "scanner.h"

void scan(){
  readChar();
  while(currentChar != EOF){
    Token* token = getToken();
    switch(token->tokenType){
    case TK_IDENT:
      printf("%d,%d: TK_IDENT(%s)\n",token->lineNo, token->colNo, token->string);
      break;
    case TK_NUMBER:
      printf("%d,%d: TK_NUMBER(%d)\n",token->lineNo, token->colNo, token->value);
      break;
    case TK_CHAR:
      printf("%d,%d: TK_CHAR(%s)\n",token->lineNo, token->colNo, token->string);
      break;
    case TK_EOF:
      break;
    case TK_NONE:
      return;
    default:
      if (getKeywordName(token->tokenType) != NULL)
	printf("%d,%d: %s\n",token->lineNo, token->colNo, getKeywordName(token->tokenType));
      else
	printf("%d,%d: %s\n",token->lineNo, token->colNo, getSymbolName(token->tokenType));
    }                
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2){
    printf("No input file\nUsage: scanner <file's name>. Please try again\n"); exit(1);
  } else {
    if (openInputStream(argv[1])){
      scan();
    } else {
      printf("Error, please check and try again\n");
    }
  }

  return 0;
}
