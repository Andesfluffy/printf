#include "main.h"

/**
 * _printf - This function prints all is given to it
 * @format: The format specifier for the different data types
 * Return: Returns the incremented value
 */

int _printf(const char *format, ...)
{
	va_list args;
	int total = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					int c = va_arg(args, int);

					write(1, &c, sizeof(c));
					total++;
					break;
				}

				case 's':
				{
					char *str = va_arg(args, char*);

					int len = 0;

					while (str[len] != '\0')
					{
						len++;
					}
					write(1, str, len);
					total += len;
					break;
				}

				case '%':
				{
					write(1, format, 1);
					total++;
				}
				default:
					break;
			}
		}
		else
		{
			write(1, format, 1);
			total++;
		}
		format++;
	}

	va_end(args);
	return (total);
}