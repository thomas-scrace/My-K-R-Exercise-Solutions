/* K&R Exercise 5-4
 * Write the function strend(s,t), which returns 1 if the string t occurs at
 * the end of string s, and zero otherwise. 
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>

int stred(char *s, char *t);

int main()
{
	char s[15] = "Hello, world!";
	char t[7] = "world!";
	if (stred(s, t)) {
		printf("t occurs at the end of s\n");
	} else {
		printf("t does not occur at the end of s\n");
	}
}

/* stred: return 1 if t occurs at the end of s, and 0 otherwise. */
int stred(char *s, char *t)
{
	int i;

	for ( ; *s; s++) 
		;
	for (i = 0; *t; t++) 
		i++;
	for ( ; *t == *s; s--, t--) 
		i--;
	return (i == -1) ? 1 : 0;
}
