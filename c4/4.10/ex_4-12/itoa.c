/* K&R Exercise 4-12
 * Adapt the ideas of printd to write a recursive version of itoa; that is,
 * convert an integer into a string by calling a recursive routine.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <string.h>

void itoa(char s[], int n, int i);

/* main: demo itoa */
int main()
{
	char s[] = "abcdefg";
	itoa(s, 1234567, strlen(s) - 1);
	printf("%s\n", s);
	return 0;
}
	

/* itoa: recursively convert an integer to a string */
void itoa(char s[], int n, int i)
{
	if (n / 10) {
		itoa(s, n / 10, --i);
		s[++i] = n % 10 + '0';
	} else {
		s[i] = n + '0';
	}
}
