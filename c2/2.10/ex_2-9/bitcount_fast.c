/* K&R Exercise 2-9
 * In a two's complement number system, x &= (x-1) deletes the rightmost
 * 1-bit in x. Explain why. Use this observation to write a faster version
 * of bitcount.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

/* EXPLANATION
 * ***********
 *
 * When subtracting 1 from a two's complement number the rightmost 1-bit
 * will always be inverted because it represents the lowest value occupied
 * bit position in the number. Therefore, when n and n-1 are operands of
 * bitwise AND, the position occupied by the rightmost 1-bit in n will
 * be inverted (0) in the output of n & (n-1) (since it was a 1 in n, and a
 * 0 in n-1).
 *
 * Example:
 *
 * We start with the number 96: 01100000
 *
 * Subtract one to get 95: 01011111 (notice that the rightmost 1-bit is gone)
 *
 * Bitwise AND: 01100000 &
 *              01011111
 *              --------
 *              01000000
 *
 * We can exploit this in our bitcount function by repeatedly running the
 * output of this process into it again as input, and counting the number
 * of cycles it takes to reduce the number to 0 (00000000).
 *
 * For example, the next cycle of the 96 series will be:
 *
 * We start where we left off, with 64: 01000000
 *
 * Subtract 1, to get 63: 00111111
 *
 * Bitwise AND: 01000000 &
 *              00111111
 *              --------
 *              00000000
 *
 * We have hit zero. It took us two cycles through the algorithm to zero out,
 * which tells us that there were two 1-bits in the original number, which is
 * correct.
 */

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

/* bitcount: count 1-bits in x, FASTER! */
int bitcount(unsigned long x)
{
	int b;

	for (b = 0; x != 0; b++)
		x &= (x-1);
	return b;
}
