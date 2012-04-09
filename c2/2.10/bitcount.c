#include <stdio.h>
#include <limits.h>

int bitcount(unsigned long x);

int main()
{
	unsigned long x;
	int b;

	x = ULONG_MAX;
	b = bitcount(x);
	printf("%lu has %d 1-bit%c\n", x, b, (b > 1) ? 's' : 0);
	return 0;
}

/* bitcount: count 1-bits in x */
int bitcount(unsigned long x)
{
	int b;

	for (b = 0; x!= 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}
