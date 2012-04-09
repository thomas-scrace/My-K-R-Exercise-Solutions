/* K&R Exercise 3-6
 * Write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <string.h>


void itoa(int n, char s[], int m);
void reverse(char s[]);

int main()
{
	int n;
	char s[10];

	n = -128;
	itoa(n, s, 8);
	printf("%d = %s\n", n, s);
	return 0;
}

/* itoa: convert n to characters with minimum field width m in s */
void itoa(int n, char s[], int m)
{
	int i, sign, size;

	i = 0;
	sign = n;
	size = 0;
	do {
		s[i++] = (sign > 0) ? n % 10 + '0' : -(n % 10) + '0';
		size++;
	} while (((sign > 0) && ((n /= 10) > 0)) || ((sign < 0) && ((n /= 10)
			< 0)) || (size < m)); /* ensure at least m digits */
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
