#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - A print function
 * @format: format
 * Return: prtchar
 */
int _printf(const char *format, ...)
{
	int j, prt = 0, prtchar = 0;
	int flg, width, prisess, size, buff_ind = 0;

	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j]; j++)
	{
		if (format[j] != %)
		{
		buffer[buff_ind++] = format[j];
		if (buff_ind == BUFF_SIZE)
			print_buffer(buffer, &buff_ind);
		prtchar++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flg = get_flags(format, &j);
			width = get_width(format, &j, list);
			prisess = get_precision(format, &j, list);
			size = get_size(format, &j);
			j++;
			prt = handle_print(format, &j, list, buffer,
flg, width, prisess, size);
			if (prt == -1)
				return (-1);
			prtchar += prt;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (prtchar);
}

/**
 * print_buffer - print the exiting buffer
 * @buffer: Array of buffer
 * @buff_ind: index for input
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
