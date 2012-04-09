/*
 * K&R Exercise 2-3
 * Convert a string of hexadecimal digits (including an optional 0x or 0X) into
 * its equivalent integer value. The allowable digits are 0 through 9,
 * a through f, and A through F.
 *
 * We're not bothering with any error checking here. htoi() assumes you are
 * feeding it a well formed string of hexadecimal digits.
 *
 * In this version we use the character testing functions from <ctype.h>.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <ctype.h>

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
	for (i = 0; isxdigit(s[i]) || s[i] == 'x' || s[i] == 'X'; ++i)		
		if (s[i] == 'x' || s[i] == 'X')
			n = 0;
		else if (isdigit(s[i]))
			n = 16 * n + (s[i] - '0');
		else
			n = 16 * n + (tolower(s[i]) - 'a' + 10);
	return n;
}
