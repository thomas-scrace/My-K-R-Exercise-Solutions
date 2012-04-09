/* K&R Exercise 3-5
 * Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16)
 * formats n as a hexadecimal integer in s.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	int n;
	char s[4];

	n = 32;
	itob(n, s, 16);
	printf("%d = %s\n", n, s);
	return 0;
}

/* itob: convert n to base b characters in s (highest allowed base: 16) */
void itob(int n, char s[], int b)
{
	int i, sign;
	char hexdig[16];

	for (i = 0; i <= 15; i++) {	/* set up digits up to 15 */
		if (i <= 9)
			hexdig[i] = '0' + i;
		else
			hexdig[i] = 'A' + i - 10;
	}
	i = 0;
	sign = n;
	do {
		s[i++] = (sign > 0) ? hexdig[n % b] : hexdig[-(n % b)];
	} while (((sign > 0) && ((n /= b) > 0)) || ((sign < 0) && ((n /= b)
								< 0)));
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
