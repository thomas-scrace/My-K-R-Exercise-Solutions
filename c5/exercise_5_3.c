/* K&R Exercise 5-3
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>

void strct(char *s, char *t);

int main()
{
	char s[15] = "Hello, ";
	char t[7] = "world!";
	printf("s = %s\n", s);
	printf("t = %s\n", t);
	strct(s, t);
	printf("s = %s\n", s);
	printf("t = %s\n", t);
}

/* strct: concatenate t to the end of s; s must be big enough */
void strct(char *s, char *t)
{
	for ( ; *s; s++)
		;
	for ( ; *s = *t; s++, t++)
		;
}
