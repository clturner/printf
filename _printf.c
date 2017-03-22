#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _putchar - puts a char to stdout
 * @c: char to put to stdout
 * Return: none
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 * print_char - print a char
 * @ap: list of args
 * Return: none
 */
void print_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	putchar(c);
}

/**
 * print_string - print a string
 * @ap: list of args
 * Return: none
 */
void print_string(va_list ap)
{
	int i;
	char *string = va_arg(ap, char *);

	for (i = 0; string[i] != '\0'; i++)
	{
		putchar(string[i]);
	}
}

void print_int_helper(int n)
{

	int a;
/**	printf("test%d\n", n);*/
	if (n < 0)
	{
		n = n * (-1);
		_putchar('-');
	}
	if (n > 9)
        {
		a = n / 10;

		n = n - (10 * a);
		print_int_helper(a);
		_putchar('0' + n);
        }
        else
        {
                _putchar('0' + n);
                return;
        }
}
/**
 * print_int - prints an integer to stdout
 * @n: integer to print to stdout
 * Return: none
 */
void print_int(va_list ap)
{
	int n;

	n  = va_arg(ap, int);
	print_int_helper(n);

}

/**
 * _printf - costum printf function
 * @format: list of characters corresponding to arguments
 * Return: none
 */
int _printf(const char *format, ...)
{

	op_t fmt[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL},
	};

	va_list ap;
	int i, j;

	va_start(ap, format);
	i = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;
			while (fmt[j].op)
			{
				if (format[i] == fmt[j].op)
				{
					fmt[j].f(ap);
					break;
				}
				j++;
			}
		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (0);
}
