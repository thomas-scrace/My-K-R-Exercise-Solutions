#include <stdio.h>

/* K&R exercise 1-9
 * copy input to output, replacing every string of one or more blanks with a single blank
 */

main()
{
	int c, blanks;

	while ((c = getchar()) != EOF){
		if (c == ' ')
			++blanks;
		if (c != ' '){
			if (blanks > 0)
				printf(" ");
				blanks = 0;
			putchar(c);
		}
	}
}
