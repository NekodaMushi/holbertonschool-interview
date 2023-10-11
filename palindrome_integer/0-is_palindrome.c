#include "palindrome.h"

/**
 * main - Entry point
 *
 * @n: number to be checked
 *
 * Return: 1 if palindrome, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
  int end = 0;
  int start = n;

  while (n != 0) {
    end = end * 10 + n % 10;
    n /= 10;
  }
  return (start == end);

}
