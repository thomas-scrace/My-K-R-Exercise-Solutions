/* K&R Exercise 4-4
 * Add commands to print the top element of the stack without
 * popping, to duplicate it, and to swap the top two elements.
 * Add a command to clear the stack.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP	100	/* max size of operand of operator */
#define NUMBER	'0'	/* signal that a number was found */
#define ALPHA	'a'	/* signal that an alphabetic sequence was found */

int getop(char []);
void push(double);
double pop(void);
void printtop(void);
void dup(void);
void swap(void);
void clear(void);
int cmd(char []);

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch(type) {
		case ALPHA:
			if (cmd(s))
				break;
			else
				printf("command unknown\n");
				break;
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: division by zero\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int) pop() % (int) op2);
			else
				printf("error: division by zero\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error, unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

/* if command in s, execute, else, return 0 */
int cmd(char s[])
{
	if (strcmp(s, "printtop") == 0)
		printtop();
	else if (strcmp(s, "dup") == 0)
		dup();
	else if (strcmp(s, "swap") == 0)
		swap();
	else if (strcmp(s, "clear") == 0)
		clear();
	else
		return 0;
	return 1;
}

#define MAXVAL	100	/* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto the stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return the top value from the stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack is empty\n");
		return 0.0;
	}
}

/*printtop: print the top element of the stack without popping it */
void printtop(void)
{
	if (sp > 0)
		printf("%f\n", val[sp - 1]);
	else
		printf("error: stack is empty\n");
}

/* dup: duplicate the top element on the stack */
void dup(void)
{
	if (sp > 0)
		push(val[sp - 1]);
	else
		printf("error: stack is empty\n");
}

/* swap: swap the top two elements of the stack */
void swap(void)
{
	double op1, op2;

	if (sp > 1) {
		op2 = pop();
		op1 = pop();
		push(op2);
		push(op1);
	} else {
		printf("error, < 2 elements in stack\n");
	}
}

/* clear: clear the stack */
void clear(void)
{
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* get next operator or operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-')
		return c;	/* not a number */
	i = 0;
	if (isalpha(c))		/* collect alphas */
		while (isalpha(s[++i] = c = getch()))
			;
	if (isalpha(s[i - 1])) {
		s[i] = '\0';
		/* if (c != EOF)
			ungetch(c); */
		return ALPHA;
	}
	if (c == '-')
		if (!isdigit(s[++i] = c = getch())) {
			ungetch(c);
			return '-';
		}
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void)		/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
