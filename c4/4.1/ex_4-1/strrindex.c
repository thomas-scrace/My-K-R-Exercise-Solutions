/* K&R Exercise 4-1
 * Write the function strrindex(s,t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000    /* maximum input line length */

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);
int printfrom(char line[], int i);

char pattern[] = "ould";        /* pattern to search for */

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0;
	int i = -1;

	while (getline(line, MAXLINE) > 0)
		if ((i = strrindex(line, pattern)) >= 0) {
			printfrom(line, i);
			found++;
		}
	return found;
}

/* strrindex: return index of the rightmost t in s, -1 if none */
int strrindex(char s[], char t[])
{
	int i, j, k;

	for (i = strlen(s)-1; i >= 0; i--) {
		for (j = i, k = strlen(t)-1; k >= 0 && s[j] == t[k]; j--, k--)
			;
		if (k == -1)
			return j+1;
	}
	return -1;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* printfrom: print line from i to end */
int printfrom(char line[], int i)
{
	while(line[i] != '\0')
		printf("%c", line[i++]);
	return 0;
}
