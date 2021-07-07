#include "menger.h"
/**
 * flor - floor a number
 *
 * @a: floor
 * Return: floor of a
 */
double flor(double a)
{
	return (floor(a / 3));
}
/**
 * check - check if a void needed
 *
 * @x: box pos
 * @y: box pos
 * Return: 1 or 0
 */
int check(int x, int y)
{
	while (x || y)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x = flor((double)x);
		y = flor((double)y);
	}
	return (1);
}
/**
 * show - print a char
 *
 * @a: char to be printed
 */
void show(char a)
{
	putchar(a);
}
/**
 * menger - Binary tree node
 *
 * @level: Menger sponge level
 */
void menger(int level)
{
	int m, i, j, n = level;

	m = pow(3, n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m;)
		{
			if (check(i, j++))
				show('#');
			else
				show(' ');
		}
		show('\n');
	}
}
