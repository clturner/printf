#ifndef SFCODE_H
#define SFCODE_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct op
{
	char op;
	void (*f)();
} op_t;

int _printf(const char *format, ...);
void print_char(va_list ap);
void print_string(va_list ap);
int _putchar(char c);
int _strlen(char *s);
void print_int(int n);
void print_mod(char c);
#endif
