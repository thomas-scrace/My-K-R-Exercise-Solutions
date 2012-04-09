#include <stdio.h>

#define IN 1	/* in a comment/quote */
#define OUT 0	/* not in a comment/quote */

/*
 * K&R Exercise 1-23
 * Remove all comments from .c files.
 *
 * Author: Thomas Scrace
 *
 */

main()
{
	int c, buf;
	int com;	/* store "comment" status, IN/OUT */
	int quo;	/* store quote status, "/'/OUT */

	com = OUT;
	quo = OUT;
	buf = 0;
	
	if (0) {
		printf("/* this is not a comment */");	/* testing */
	}

	while ((c=getchar()) != EOF) {
		if (quo > OUT) {
			if (c == quo) {
				putchar(c);
				quo = OUT;
			} else {
				putchar(c);
			}
		} else if (com == IN) {
			if (buf == '*' && c == '/') {
				com = OUT;
			} else {
				buf = c;
			}
		} else {
			if (buf == '/' && c == '*') {
				com = IN;
			} else if (buf == '/') {
				putchar('/');
				putchar(c);
				buf = c;
			} else if (c == '/') {
				buf = c;
			} else if (c == '\'' || c == '\"') {
				putchar(c);
				quo = c;
			} else {
				putchar(c);
			}
		}
	}
	return 0;
}
