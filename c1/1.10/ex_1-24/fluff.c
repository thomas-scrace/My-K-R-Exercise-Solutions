#include <stdio.h>

#define OUT 0	/* not in a comment or a quote */
#define COM 1	/* in a comment */

/*
 * K&R Exercise 1-24
 *
 * Check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets
 * and braces. Don't forget about quotes, both
 * single and double, escape sequences, and
 * comments.
 *
 * It's pretty simple-minded, and won't tell
 * you *where* your errors are, but it will
 * tell you about them. Maybe revisit this
 * later.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

main()
{
	int c;
	int par, brk, brc;	/* track parens, brackets, braces */
	int status;		/* track whether in/out of comments/quotes
				 * OUT = not in either
				 * COM = in a comment
				 * '\'' = in a single quote
				 * '\"' = in a double quote
				 */
	int buf;		/* buffer to help track comments */

	par = brk = brc = buf = 0;
	status = OUT;

	while ((c=getchar()) != EOF) {
		if (status > OUT) {
			if (status == COM && buf == '*' && c == '/') {
				status = OUT;
				buf = c;
			} else if (c == status) {
				status = OUT;
				buf = c;
			}
			buf = c;
		} else if (c == '*' && buf == '/') {
			status = COM;
			buf = c;
		} else if (c == '\'' || c == '\"') {
			status = buf = c;
		} else if (c == '{') { 
			++brc;
			buf = c;
		} else if (c == '[') {
			++brk;
			buf = c;
		} else if (c == '(') {
			++par;
			buf = c;
		} else if (c == '}') {
			--brc;
			buf = c;
		} else if (c == ']') {
			--brk;
			buf = c;
		} else if (c == ')') {
			--par;
			buf = c;
		} else {
			buf = c;
		}
	}

	if (status == '\'') {
		printf("unmatched \'");
	} else if (status == '\"') {
		printf("unmatched \"");
	} else if (brc > 0) {
		printf("missing }");
	} else if (brc < 0) {
		printf("missing {");
	} else if (brk > 0) {
		printf("missing ]");
	} else if (brk < 0) {
		printf("missing [");
	} else if (par > 0) {
		printf("missing )");
	} else if (par < 0) {
		printf("missing (");
	} else {
		;	/* all good */
	}
	return 0;
}


