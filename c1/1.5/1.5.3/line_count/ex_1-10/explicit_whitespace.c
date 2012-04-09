#include <stdio.h>

/* K&R exercise 1-10
 * copy input to output, replacing each tab with \t, each backspace with \b, and each backslash with \\
 */

main()
{
	int c;

	while ((c = getchar()) != EOF){
		if (c == '\t')
			printf("\\t");
		if (c == '\b')
			printf("\\b");
		if (c == '\\')
			printf("\\\\");
		if (c != '\\')
			if (c != '\t')
				if (c != '\b')
					putchar(c);
	}
}
