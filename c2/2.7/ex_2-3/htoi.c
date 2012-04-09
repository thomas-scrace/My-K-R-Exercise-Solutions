/*
 * K&R Exercise 2-3
 * Convert a string of hexadecimal digits (including an optional 0x or 0X) into
 * its equivalent integer value. The allowable digits are 0 through 9,
 * a through f, and A through F.
 *
 * We're not bothering with any error checking here. htoi() assumes you are
 * feeding it a well formed string of hexadecimal digits.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>

int htoi(char s[]);

/* demo htoi() */
int main()
{
	int i;
	char s[7];

	s[0] = '0';
	s[1] = 'x';
	s[2] = '2';
	s[3] = 'A';
	s[4] = 'F';
	s[5] = '3';
	s[6] = '\0';

	i = htoi(s);
	printf("%d\n", i); /* i should print as 10995, the decimal 
				equivalent of 0x2AF3. */
	return 0;	
}

/* htoi: convert string of hex, s, to integer */
int htoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; (s[i] >= '0' && s[i] <= '9') ||
			(s[i] >= 'a' && s[i] <= 'f') ||
			(s[i] >= 'A' && s[i] <= 'F') ||
			s[i] == 'x' ||
			s[i] == 'X'
			 ; ++i)

		if (s[i] >= '0' && s[i] <= '9')
			n = 16 * n + (s[i] - '0');
		else if (s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + (s[i] - 'a' + 10);
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + (s[i] - 'A' + 10);
		else
			n = 0;
	return n;
}
