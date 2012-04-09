/* K&R Exercise 5-5
 * Write versions of the library functions kr_strncpy, kr_strncat, and
 * kr_strncmp, which
 * operate on at most the first n characters of their argument strings. For
 * example, kr_strncpy(s, t, n) copies at most n characters of t to s. Full
 * descriptions are in appendix B. 
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>

char *kr_strncpy(char *s, char *t, int n);
char *kr_strncat(char *s, char *t, int n);
int kr_strncmp(char *s, char *t, int n);

int main()
{
	char s[20] = "123";
	char t[20] = "4567";
	printf("s = %s\n", s);
	printf("t = %s\n", t);
	printf("s = %s\n", kr_strncpy(s, t, 2));
	printf("s = %s\n", s);
	printf("t = %s\n", t);
}

/* kr_strncpy: copy at most n characters of string t to s; return s. Pad with
'\0's if t has fewer than n characters. */
char *kr_strncpy(char *s, char *t, int n)
{
	int i, j;
	for (i = 0; *s; s++, i++)
		;
	for (j = 0; j < n; s++, t++, j++)
		if (!(*s = *t))
			*s = '\0';
	return s - (i + n);	
}

/* kr_strncat: concatenate at most n characters of string t to string s,
terminate with '\0'; return s. */
char *kr_strncat(char *s, char *t, int n)
{

}

/* kr_strncmp: compare at most n characters of string s to string t; return < 0 if
s < t, 0 of s == t, or > 0 if s > t. */
int kr_strncmp(char *s, char *t, int n)
{

}
