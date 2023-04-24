#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSE(x) (void) (x)

#define F_PLUS 2
#define F_MINUS 1
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - operator
 * @fmt: format
 * @fn: function 
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int)
};

/**
 * typedef struct fmt fmt_t - operator
 * @fmt: format
 * @fmt_t: function 
 */
typedef struct fmt fmt_t

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

#endif
