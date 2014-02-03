/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#ifndef _SCANNER_H_
#define _SCANNER_H_

#include "token.h"

extern void skipBlank();
extern void skipComment();
extern Token* readIdentKeyword(void);
extern Token* readNumber(void);
extern Token* readConstChar(void);
extern Token* getToken(void);

#endif /* _SCANNER_H_ */
