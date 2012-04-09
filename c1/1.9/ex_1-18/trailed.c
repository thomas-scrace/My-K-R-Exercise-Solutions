#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */
int getline(char line[], int maxline);
void copy(char to[], char from[]);
/* remove trailing blanks and tabs from each line of input, and delete blank lines*/
/* note: it seems that the modern GNU C library includes a function called 'getline'.
 * This causes an incompatibility with this code ("error: conflicting types"). Therefore,
 * if you experience this error, use 'c89' instead of 'gcc'. This will invoke gcc in ANSI
 * compliant mode, which should enable this code to work correctly.
 */
main()
{
	int i, j, start;
	start = 1;
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */
	while ((len = getline(line, MAXLINE)) > 0) {
		if (start != 1 && i >= 0)
			printf("\n");
		else
			start = 0;
		for (i = len-1; line[i] == ' ' || line[i] == '\t' || line[i] == '\0' || line[i] == '\n'; --i)
			;
		if (i >= 0)
			for (j = 0; j <= i; ++j)
				printf("%c", line[j]);
	}
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
