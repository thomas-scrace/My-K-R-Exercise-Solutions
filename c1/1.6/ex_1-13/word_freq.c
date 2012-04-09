#include <stdio.h>

/* print a histogram of the lenghts of words input */
/* choose either vertical or horizontal orientation */

#define		IN	1	/* in a word */
#define		OUT	0	/* not in a word */
#define		VER	1	/* chart has vertical orientation */
#define		HOR	0	/* chart has horizontal orientation */

main()
{
	int i, j, c, state, word_length, orient, max;	
	int flengths[10];

	orient = 1;
	state = OUT;
	word_length = 0;
	for (i = 0; i <= 10; ++i)
		flengths[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c =='\n') {
			if (state == IN) {
				++flengths[word_length];
				word_length = 0;
			}
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			++word_length;
		}
		else if (state == IN)
			++word_length;
	}
	if (orient == HOR) {
		for (i = 1; i <= 9; ++i) {
			printf("%d: ", i);
			for (j = 1; j <= flengths[i]; ++j)
				printf("|");
			printf("\n");
		}
	}
	else {
		max = 0;
		for (i = 1; i <=9; ++i)		/* determine the highest freq */
			if (flengths[i] > max)
				max = flengths[i];

		for (i = 1; i <= 9; ++i)
			printf("%d\t", i);
		printf("\n");
		for (i = 1; i <= max; ++i) {
			for (j = 1; j <= max; ++j) {
				if (flengths[j] >= i)
					printf("-\t");
				else
					printf("\t");
			}
			printf("\n");
		}
	}		
} 
		
