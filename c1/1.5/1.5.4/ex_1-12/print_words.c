#include <stdio.h>

#define		IN	1	/* inside a word */
#define		OUT	0	/* outside a word */

/* K&R exercise 1-12
 * print output to input, one word per line
 */

main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			printf("\n");
			putchar(c);
		}
		else if (state == IN)
			putchar(c);
		
	}
}
