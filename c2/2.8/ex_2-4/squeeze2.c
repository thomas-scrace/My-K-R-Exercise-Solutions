/*
 * K&R Exercise 2-4
 * Write a function squeeze(s1, s2) that deletes each character in s1 that
 * matches any character in the string s2.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{

	char st1[4];
	char st2[2];

	st1[0] = 'a';
	st1[1] = 'b';
	st1[2] = 'c';
	st1[3] = '\0';
	st2[0] = 'a';
	st2[1] = '\0';

	squeeze(st1, st2);
	printf("%s\n", st1);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k, t;

	for (i = k = t = 0; s1[i] != '\0'; i++, t = 0) {
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				t = 1;
		if (!t)
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
} 
