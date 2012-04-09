/*
 * K&R Exercise 2-2
 *
 * Write a loop equivalent to:
 *
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 * 	s[i] = c;
 *
 * without using && or ||.
 */

#include <stdio.h>

main()
{
	int i;
	int lim;
	int c;
	char s[1000];
	lim = 1000;
	c = '\n';

	for (i = 0; i < lim-1; ++i)
		s[i] = 0;

	for (i = 0; i < lim - 1; ++i)
		if ((c = getchar()) != '\n')
			if (c != EOF)
				s[i] = c;
			else
				break;
		else
			break;
	printf("%s\n", s);

}
