/*
 * K&R Exercise 2-10
 * Rewrite the function lower, which converts upper case letters to lower
 * case, with a conditional expression instead of if-else.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>

int lower(int c);

/* main(): test out the lower() function. */
int main()
{
	int i = 0;
	char s[5];
	s[0] = 'a';
	s[1] = 'B';
	s[2] = 'c';
	s[3] = 'D';
	s[4] = '\0';
	for (i=0; i<=4; i++)
		printf("%c", lower(s[i]));
	printf("\n");
	return 0;
}

int lower(int c)
{
	return (c>= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
