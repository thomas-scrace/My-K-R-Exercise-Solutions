#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 * function version
 */

float convert(float fahr);

main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */
	
	printf("  F      C\n");
	fahr = lower;
	while(fahr <= upper) {
		printf("%3.0f %6.1f\n", fahr, convert(fahr));
		fahr = fahr + step;
	}
}

float convert(float fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}
