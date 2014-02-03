/**
 * @author: pvhau
 * @tag: compiler-homework
 * @subject: scanner
 */

#ifndef _ERROR_H_
#define _ERROR_H_

// List errors
typedef enum {
ERR_ENDOFCOMMENT,
ERR_IDENTTOOLONG,
ERR_INVALIDCHARCONSTANT,
ERR_INVALIDSYMBOL
} ErrorCode;

#define ERM_ENDOFCOMMENT "End of comment expected!"
#define ERM_IDENTTOOLONG "Identification too long!"
#define ERM_INVALIDCHARCONSTANT "Invalid const char!"
#define ERM_INVALIDSYMBOL "Invalid symbol!"

extern void error(ErrorCode err, int lineNo, int colNo);

#endif /* _ERROR_H_ */
