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
		printf("skipped %c\n", c);
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);		/* it's not a number */
		printf("ungetched %c\n", c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	printf("sign = %d\n", sign);
	if (c == '-' || c == '+')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch()) {
		printf("getched %c\n", c);
		printf("*pn = %d\n", *pn);
		*pn = 10 * *pn + (c - '0');
		printf("*pn = %d\n", *pn);
	}
	printf("*pn = %d\n", *pn);
	*pn *= sign;
	printf("*pn = %d\n", *pn);
	if (c != EOF) {
		ungetch(c);
		printf("ungetched %c\n", c);
	}
	printf("returning %c\n", c);
	return c;
}

#define SIZE	10

int main()
{
	int n, array[SIZE];

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	for (n = 0; n < SIZE; n++)
		printf("%d:\t%d\n", n, array[n]);
	return 0;
}
