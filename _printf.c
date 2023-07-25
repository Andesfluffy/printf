#include "main.h"

/**
 * _print_char - Prints a single character to standard output
 * @c: The character to be printed
 * Return: Returns the number of characters printed (always 1)
 */
static int _print_char(char c)
{
	write(1, &c, sizeof(c));
	return (1);
}

/**
 * _print_string - Prints a string to standard output
 * @str: The string to be printed
 * Return: Returns the number of characters printed
 */
static int _print_string(const char *str)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return 6;
	}

	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	write(1, str, len);
	return (len);
}

/**
 * _printf - This function prints all that is given to it
 * @format: The format specifier for the different data types
 * Return: Returns the total number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return -1;

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
					total += _print_char((char)c);
					break;
				}

				case 's':
				{
					char *str = va_arg(args, char*);
					total += _print_string(str);
					break;
				}

				case '%':
				{
					total += _print_char('%');
					break;
				}

				default:
				{
					// Unsupported format specifier, just print the character
					total += _print_char('%');
					total += _print_char(*format);
					break;
				}
			}
		}
		else
		{
			total += _print_char(*format);
		}
		format++;
	}

	va_end(args);
	return (total);
}
