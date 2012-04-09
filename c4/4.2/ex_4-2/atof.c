/* K&R Exercise 4-2
 * Extend atof to handle scientific notation of the form
 *	123.45e-6
 * where a floating-point number may be followed by e or E and an optionally
 * signed exponent.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

/* demo atof */
int main()
{
	char s[] = "2.56e2";

	printf("%s = %f\n", s, atof(s));
	return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power, sci;
	int i, sign, esign, exp;

	for (i = 0; isspace(s[i]); i++)	/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0;  isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	esign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] - '0');
	sci = 1;
	if (esign == 1)
		while (exp > 0) {
			sci *= 10;
			exp--;
		}
	else
		while (exp > 0) {
			sci /= 10;
			exp--;
		}
	return (sign * val / power) * sci;
}
