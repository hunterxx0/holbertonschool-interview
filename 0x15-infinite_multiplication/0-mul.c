#include "holberton.h"
/**
 * _digit(:)? (- char)?
 *
 * @p: input char
 * Return: 0 or 1
 */
int _digit(char *p)
{
	while (*p != '\0')
	{
		if (*p != '-')
		{
			if (*p < '0' || *p > '9')
		{
			return (0);
		}
		}
		p++;
	}
	return (1);

}

/**
* main(:)? (- mul)?
*
* @argc: input int
* @argv: input char
* Return: mul
*/
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	if (_digit(argv[1]) == 0 || _digit(argv[2]) == 0)
	{
		printf("Error\n");
		exit(98);
	}
	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return (0);
}