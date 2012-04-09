/* K&R 4.10 - Recursion
 */

#include <stdio.h>

void printd(int n);

int main()
{
	printd(-10);
	putchar('\n');
	return 0;
}

/* printd: print n in decimal */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

