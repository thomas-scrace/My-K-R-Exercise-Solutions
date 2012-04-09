/* K&R Exercise 5-2
 * Write getfloat, the floating-point analog of getint. What type does getfloat
 * return as its function value?
 * 
 * A: getfloat's function return type is int.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *);

#define BUFSIZE 100

char buf[BUFSIZE];	/* buffer for ungetch() */
int bufp = 0;		/* next free position in buf */

/* get a (possibly pushed back character */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* getfloat: get next floating point number from input into *pn */
int getfloat(float *pn)
{
	int c, sign, point;
	float fpart, ipart;	/* float part, integer part */
	float i = 10.0;		/* keep track of decimal place */

	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);		/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+') {
		if (!isdigit(c = getch())) {
			ungetch(c);
			ungetch((sign == 1) ? '+' : '-');
			return 0;
		}
	}
	point = (c == '.') ? 1 : 0;
	if (c == '.') {
		if (!isdigit(c = getch())) {
			ungetch(c);
			ungetch('.');
			return 0;
		}
	}
	for (fpart = ipart = 0.0; isdigit(c) || c == '.'; c = getch()) {
		if (c == '.') {
			point = 1;
			continue;
		}
		if (!point) {
			ipart = 10.0 * ipart + (c - '0');
		} else {
			fpart = fpart + ((float) (c - '0') / i);
			i *= 10.0;
		}
	}
	*pn = fpart + ipart;
	*pn *= (float) sign;
	if (c != EOF) {
		ungetch(c);
	}
	return c;
}

#define SIZE	10

int main()
{
	int n;
	float array[SIZE];

	for (n = 0; n < SIZE; n++) {
		array[n] = 0;
	}
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;
	for (n = 0; n < SIZE; n++)
		printf("%d:\t%f\n", n, array[n]);
	return 0;
}
