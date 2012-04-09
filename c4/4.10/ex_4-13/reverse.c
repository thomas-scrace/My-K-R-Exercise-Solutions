/* K&R Exercise 4-13
 * Write a recursive version of the function reverse(s), which reverses the
 * string in place.
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
