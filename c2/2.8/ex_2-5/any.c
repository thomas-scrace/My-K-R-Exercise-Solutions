/*
 * K&R Exercise 2-5
 * Write the function any(s1, s2), which returns the first location in the
 * string s1 where any character from the string s2 occurs, or -1 if s1
 * contains no characters from s2.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	int i;

	char st1[4];
	char st2[2];

	st1[0] = 'a';
	st1[1] = 'c';
	st1[2] = 'c';
	st1[3] = '\0';
	st2[0] = 'c';
	st2[1] = '\0';

	i =  any(st1, st2);
	printf("%d\n", i);
	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;
	return -1;
} 
