/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#include <string.h>
#include <stdio.h>
#include "error.h"

void error(ErrorCode err, int lineNo, int colNo){
  char errorStr[200];
  switch(err){
  case ERR_ENDOFCOMMENT:
    strcpy(errorStr, ERM_ENDOFCOMMENT);break;
  case ERR_IDENTTOOLONG:
    strcpy(errorStr, ERM_IDENTTOOLONG);break;
  case ERR_INVALIDCHARCONSTANT:
    strcpy(errorStr, ERM_INVALIDCHARCONSTANT);break;
  case ERR_INVALIDSYMBOL:
    strcpy(errorStr, ERM_INVALIDSYMBOL);break;
  default:
    strcpy(errorStr, "Error ");
  }

  printf("%s at: %d,%d\n", errorStr, lineNo, colNo);
}
