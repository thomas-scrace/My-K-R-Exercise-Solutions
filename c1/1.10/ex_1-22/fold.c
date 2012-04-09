#include <stdio.h>

#define MAXLINE 1000    /* maximum line length */
#define FOLD 80		/* point at which we will fold the line */
#define TAB 8		/* tab length */

int gline(char s[], int lim);
int lastwhite(int i, int j, char l[]);
void fold(char l[], int len);
int iswhite(char c);
void printr(int i, char l[]);

/*
 *      K&R Exercise 1-22
 *      Fold long lines of input into
 *	2 or more shoter lines after
 *	the last non-blank character.
 *
 *	This is a pretty inelegant
 *	solution. Revisit later.
 */

main()
{
        int len;
        char line[MAXLINE];

        while((len = gline(line, MAXLINE)) > 0) {
		if (len > FOLD) {
			fold(line, len);
		} else {
			printf("%s", line);
		}
	}
}

/* fold: fold the line into two or more
 * lines at the last whitespace before the
 * FOLD. If no whitespace, fold at FOLD.
 */
void fold(char l[], int len)
{
	int i, j, k, w, last;
	for (i = j = k = w = last = 0; l[i] != '\0'; ++i, ++k) {
		if (j == 0 && len-k <= FOLD) {
			printr(i, l);
			return;
		} else if (j == FOLD-1) {
			putchar(l[i]);
			putchar('\n');
			j = 0;
		} else if ((w = iswhite(l[i])) > 0) {
			if ((last = lastwhite(i+1, j+1, l)) == 1) {
				putchar(l[i]);
				putchar('\n');
				j = 0;
				k = k + w - 1;
			} else {
				putchar(l[i]);
				j = j + w;
				k = k + w - 1;
			}
		} else {
			putchar(l[i]);
			++j;
		}
	}
}

/* printr: print the rest of the line */
void printr(int i, char l[])
{
	for (; l[i] != '\0'; ++i) {
		putchar(l[i]);
	}
}

/* iswhite: return 1 if ' ', return
 * TAB if '\t', return 0 if neither.
 */
int iswhite(char c)
{
	if (c == ' ') {
		return 1;
	} else if (c == '\t') {
		return TAB;
	} else {
		return 0;
	}

}

/* lastwhite: determine if the given character is the last
 * whitespace on the line. If so, return 1, else return 0.
 */
int lastwhite(int i, int j, char l[])
{
	int k;
	for (k = 0; k <= FOLD-j && l[i] != '\0'; ++k, ++i) {
		if (l[i] == ' ' || l[i] == '\t') {
			return 0;
		}
	}
	return 1;
}
/* gline: read a line into s, return length */
int gline(char s[], int lim)
{
        int c, i, t;

        for (i=t=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i) {
                s[i] = c;
		if (c == '\t') {
			++t;
		}
	}
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
	i = i + (TAB-1)*t;
        return i;
}


