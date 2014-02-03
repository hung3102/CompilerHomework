/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#include <stdio.h>
#include "reader.h"

FILE* inputStream;
int lineNo, colNo;
int currentChar;

int readChar(void){
  currentChar = fgetc(inputStream);
  if (currentChar == '\n'){
    lineNo++;
    colNo = 0;
  } else {
    colNo++;
  }
  return currentChar;
}

int openInputStream(char *fileName){
  if ((inputStream = fopen(fileName,"r")) == NULL){
    printf("Can't open file %s\n",fileName);return 0;
  }
  lineNo = 1;
  colNo = 0;
  return 1;
}

void closeInputStream(void){
  fclose(inputStream);
}
