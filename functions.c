#include "main.h"

/**
 * print_char - A funcrion that print character
 * @types: argument list
 * @buffer: array of buffer
 * @flags: active flag count
 * @width: width size
 * @precision: prexision specifier
 * @size: sise specifier
 * Return: int value
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char a = va_arg(types, int);

	return (handle_write_char(a, buffer, flags, width, precision, size));
}
/**
 * print_string- A funcrion that print strings
 * @types: argument list
 * @buffer: array of buffer
 * @flags: active flag count
 * @width: width size
 * @precision: prexision specifier
 * @size: sise specifier
 * Return: int value
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int lent = 0, j;
	char *st = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (st == NULL)
	{
		st = "(null)";
		if (precision >= 6)
			st = "      ";
	}

	while (st[lent] != '\0')
		lent++;

	if (precision >= 0 && precision < lent)
		lent = precision;

	if (width > lent)
	{
		if (flags & F_MINUS)
		{
			write(1, &st[0], lent);
			for (j = width - lent; j > 0; j--)
			       write(1, " ", 1);
			write(1, &st[0], lent);
			return (width);
		}
	}
	return (write(1, st, lent));
}

/**
 * print_percent - A funcrion that print percent
 * @types: argument list
 * @buffer: array of buffer
 * @flags: active flag count
 * @width: width size
 * @precision: prexision specifier
 * @size: sise specifier
 * Return: int value
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 *print_int - A funcrion that print integer
 * @types: argument list
 * @buffer: array of buffer
 * @flags: active flag count
 * @width: width size
 * @precision: prexision specifier
 * @size: sise specifier
 * Return: int value
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int nev = 0;
	long int n = va_arg(types, long int);
	unsigned long int numb;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)n;

	if (n < 0)
	{
		numb = (unsingned long int)((-1) * n);
		nev = 1;
	}

	while (numb > 0)
	{
		buffer[j--] = (numb % 10) = '0';
		numb /= 10;
	}
	j++;
	return (write_number(nev, j, buffer, flags, width, precision, size));
}

/**
 * print_binary - A funcrion that print binary
 * @types: argument list
 * @buffer: array of buffer
 * @flags: active flag count
 * @width: width size
 * @precision: prexision specifier
 * @size: sise specifier
 * Return: int value
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	unsigned int n, m, j, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSDED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;/* 2^31 */
	a[0] = n / m;

	for (j = 1; j < 32; j++)
	{
		m = m / 2;
		a[j] = (n / m) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum = sum + a[j];
		if (sum || j == 31)
		{
			char zi = '0' + a[j];

			write(1, &zi, 1);
			count++;
		}
	}
	return (count);
}
