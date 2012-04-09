#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

/* reverse input, one line at a time */
/* note: it seems that the modern GNU C library includes a function called 'getline'.
 * This causes an incompatibility with this code ("error: conflicting types"). Therefore,
 * if you experience this error, use 'c89' instead of 'gcc'. This will invoke gcc in ANSI
 * compliant mode, which should enable this code to work correctly.             
 */							
main()
{
	int i;

	int len;		/* line length */	
	char line[MAXLINE];	/* current input line */

	while ((len = getline(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
	}
	return 0;
}

/* reverse the string s */
void reverse(char s[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0' && s[i] != '\n'; ++i)
		;
	char t[i + 1];
	k = i - 1;
	for (j = 0; j <= k; ++j, --i) {
		t[j] = s[i - 1];
	}
	t[j] = '\0';
	copy(s, t);
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

void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}







