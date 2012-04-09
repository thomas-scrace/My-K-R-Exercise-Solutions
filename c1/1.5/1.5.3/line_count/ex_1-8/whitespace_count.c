#include <stdio.h>

/* K&R exercise 1-8
 * count blanks, tabs, and newlines in input
 */

main()
{
	int c, nl, b, t;

	nl = 0;
	b = 0;
	t = 0;

	while ((c = getchar()) != EOF){
		if (c == '\n')
			++nl;
		if (c == '\t')
			++t;
		if (c == ' ')
			++b;
	}
	printf("newlines = %d\n", nl);
	printf("tabs = %d\n", t);
	printf("blanks = %d\n", b);
}
