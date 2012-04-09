#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print all input lines; line.length > 80 */
/* note: it seems that the modern GNU C library includes a function called 'getline'.
 * This causes an incompatibility with this code ("error: conflicting types"). Therefore,
 * if you experience this error, use 'c89' instead of 'gcc'. This will invoke gcc in ANSI
 * compliant mode, which should enable this code to work correctly.
 */
main()
{
	int i;
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > 81)
			printf("%s\n", line);
	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

