#include <stdio.h>

#define TABSIZE 8       /* number of stops for tab */
#define MAXLINE 1000    /* maximum line length */

int gline(char s[], int lim);
int stopinrange(int l, int u);

/*
 *      K&R Exercise 1-21
 *      Replace strings of blanks with
 *      the minimum number of tabs and
 *      blanks to achieve the same
 *      spacing.
 */

main()
{
        int j, i, k, s;
        int len;
        char line[MAXLINE];
        k = 0;

        while((len = gline(line, MAXLINE)) > 0) {
                k = 0;
                for (i=1; i<=len; ++i) {
                        if (line[i-1] == ' ') {
                                ++k;
                        } else {
                                if (k > 0) {
                                        while ((s = stopinrange(i-k, i)) != -1 && (i-k) < i) {
                                                putchar('\t');
                                                k = k - TABSIZE;
                                        }
                                        for (; k > 0; --k)
                                                putchar(' ');
                                        k = 0;
                                }
                                putchar(line[i-1]);
                        }
                }
        }
}

/* stopinrange: if range defined by l->u contains a tab stop, return
 * the location of the first tab stop. Return -1 if no stop exists
 * in range.
 */
int stopinrange(int l, int u)
{
        int i;
        for (i=l; i < u; ++i) {
                if ((i % TABSIZE) == 0)
                        return i;
        }
        return -1;
}
/* gline: read a line into s, return length */
int gline(char s[], int lim)
{
        int c, i;

        for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}
