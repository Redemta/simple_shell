#include "shell.h"

/**
 * my_printf - my custom printf function.
 * @format: format string, first argument.
 *
 * Return: 0.
 */

int my_printf(const char *format, ...)
{
	va_list args;
	int written = 0, num, length;
	size_t i;
	char c;
	const char *str;
	char buffer[12];

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
			{
				num = va_arg(args, int);
				length = sprintf(buffer, "%d", num);
				written += write(1, buffer, length);
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, const char *);
				length = strlen(str);
				written += write(1, str, length);
			}
		}
		else
		{
			c = format[i];
			written += write(1, &c, 1);
		}
	}
	va_end(args);
	return (written);
}
