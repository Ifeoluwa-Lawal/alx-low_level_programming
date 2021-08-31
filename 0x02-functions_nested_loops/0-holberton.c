#include "main.h"
/**
 * main - Entry Point
 *
 * Return: 0 is always success
 */
int main(void)
{
	char text[9] = "Holberton";
	int i;

	for (i = 0; i < 9; i++)
	{
		_putchar(text[i]);
	}
	_putchar('\n');
	return (0);
}
