/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#ifndef _READER_H_
#define _READER_H_

// read a character from input stream
extern int readChar(void);
// open input stream
extern int openInputStream(char *fileName);
// close input stream
extern void closeInputStream(void);
// current line, column index
extern int lineNo, colNo;
// current character
extern int currentChar;

#endif /* _READER_H_ */
