/* K&R Exercise 5-1
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the input.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

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

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
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
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
	}
	*pn *= sign;
	if (c != EOF) {
		ungetch(c);
	}
	return c;
}

#define SIZE	10

int main()
{
	int n, array[SIZE];

	for (n = 0; n < SIZE; n++) {
		array[n] = 0;
	}
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	for (n = 0; n < SIZE; n++)
		printf("%d:\t%d\n", n, array[n]);
	return 0;
}
