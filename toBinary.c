#include "main.h"
/**
 * toBinary - returns the binary equivalent 
 * of the decimal number provided as a string 
 * @x: Decimal number
 * Return: decimal values 
*/

/*if(format == 'b')*/
	int toBinary(int x)
{
	if (x == 0)
	{
	return (0);
	}
	else if (x == 1)
	{
	return (1);
	}
	else
	{
	return ((x % 2) + 10 * toBinary(x / 2));
	}
}