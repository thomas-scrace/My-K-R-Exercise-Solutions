#include <stdio.h>

/* print a histogram of the frequency of characters input */
/* choose either vertical or horizontal orientation */

#define		VER	1	/* chart has vertical orientation */
#define		HOR	0	/* chart has horizontal orientation */

main()
{
	int i, j, c, orient, max;	
	int chars[25];

	orient = VER;
	for (i = 0; i <= 25; ++i)
		chars[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') {
			++chars[c - 'a'];
		}
		else
			;
	}
	if (orient == HOR) {
		for (i = 0; i <= 25; ++i) {
			putchar('a' + i);
			printf(": ");
			for (j = 1; j <= chars[i]; ++j)
				printf("|");
			printf("\n");
		}
	}
	else {
		max = 0;
		for (i = 0; i <=25; ++i)	/* determine the highest freq */
			if (chars[i] > max)
				max = chars[i];

		for (i = 0; i <= 25; ++i) {
			putchar('a' + i);
			printf("\t");
		}
		printf("\n");
		for (i = 1; i <= max; ++i) {
			for (j = 0; j <= 25; ++j) {
				if (chars[j] >= i)
					printf("-\t");
				else
					printf("\t");
			}
			printf("\n");
		}
	}		
} 
		
