#include "main.h"

/**
 * print_unsigned - A function that print unsigned types
 * @types: argument list
 * @map_to: array to map value to
 * @buffer: array for printing
 * @flags: active flags
 * @width: width size
 * @precision: precision specifier
 * @size: size specifier
 * @Return: interger value
 */
int print_unsigned(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int numb = arg(types, unsigned long int);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[j--] = (numb % 10) + '0';
		numb /= 10;
	}

	j++;
	return (write_unsgnd(0, j, buffer, flags, with, precision, size));
}

/**
 * print_octal - A function that print hexa uppe
rcase type
 * @types: argument list
 * @buffer: array for printing
 * @flags: active flags
 * @width: width size
 * @precision: precision specifier
 * @size: size specifier
 * @Return: interger value
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[j--] = (numb % 8) + '0';
		numb /= 8;
	}
	if (flags & F_HASH && init_numb != 0)
		buffer[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - A function that print hexadecimal
 * @types: argument list
 * @buffer: array for printing
 * @flags: active flags
 * @width: width size
 * @precision: precision specifier
 * @size: size specifier
 * @Return: interger value
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdf",
	buffer, flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - A function that print hexa uppercase type
 * @types: argument list
 * @buffer: array for printing
 * @flags: active flags
 * @width: width size
 * @precision: precision specifier
 * @size: size specifier
 * @Return: interger value
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF",
	buffer, flags, 'X', width, precision, size));
}

/**
 * print_hexa - A function that print hexa type
 * @types: argument list
 * @map_to: array to map value to
 * @buffer: array for printing
 * @flags: active flags
 * @width: width size
 * @precision: precision specifier
 * @size: size specifier
 * Return: interger value
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = convert_size_unsgnd(numb, size);

	if (numb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[j--] = map_to[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && init_numb != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}
