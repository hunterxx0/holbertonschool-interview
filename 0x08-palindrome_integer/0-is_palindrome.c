#include <stdlib.h>
#include "palindrome.h"
/**
 * is_palindrome - checks if an int is palindrome
 *
 * @n: Number
 * Return: 0 or 1
 */
int is_palindrome(unsigned long n)
{
int rev = 0, rest, N = n;

while (n != 0)
{
rest = n % 10;
rev = rev * 10 + rest;
n /= 10;
}
if (rev == N)
return (1);
return (0);
}
