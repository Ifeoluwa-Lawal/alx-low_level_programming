#include<stdio.h>
/**
 * main - Starting Point
 *
 * Return: 0 is always (Success)
 */
int main(void)
{
	printf("Size of int: %d bytes\n", sizeof(int));
	printf("Size of float: %d bytes\n", sizeof(float));
	printf("Size of char: %d byte\n", sizeof(char));
	printf("Size of a long int: %d byte(s)\n", sizeof(long int));
	printf("Size of a long long int: %d byte(s)\n", sizeof(long long int));
	return (0);
}
