/*
 * Examples of enum from page 39 of K&R.
 */

#include <stdio.h>

main()
{
	int i;

	enum boolean { NO, YES };

	enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
			 NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

	enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL,
			 AUG, SEP, OCT, NOV, DEC }; /* FEB is 2, MAR is 3 etc */

	printf("\nNO = %d\n", NO);
	printf("YES = %d\n\n", YES);

	printf("January is month %d\n", JAN);	
	printf("February is month %d\n", FEB);	
	printf("March is month %d\n", MAR);
	printf("April is month %d\n", APR);
	printf("May is month %d\n", MAY);
	printf("June is month %d\n", JUN);
	printf("July is month %d\n", JUL);
	printf("August is month %d\n", AUG);
	printf("September is month %d\n", SEP);
	printf("October is month %d\n", OCT);
	printf("November is month %d\n", NOV);
	printf("December is month %d\n", DEC);
				
	return 0;
}

	

