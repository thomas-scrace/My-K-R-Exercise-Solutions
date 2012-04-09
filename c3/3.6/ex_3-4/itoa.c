/* K&R Exercise 3-4
 * In a two's complement number representation, our version of itoa does
 * not handle the largest negative number, that is, the value of n equal
 * to -(2^wordsize-1). Explain why not. Modify it to print that value
 * correctly, regardless of the machine on which it runs.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

/* RATIONALE
 * *********
 *
 * In a two's complement arithmetic system, a number is negated by
 * computing its "two's complement", which is calculated by subtracting
 * the number from 2^n, where n is the wordsize. This is usually
 * accomplished by inverting all the bits in the number, and then
 * adding one.
 *
 * For example, suppose we want to find the negation of 4 in an
 * eight-bit system (for simplicity):
 *
 * 4 = 00000100
 *
 * We flip all the bits:
 *
 * 11111011
 *
 * And add one:
 *
 * 11111100
 *
 * Simple enough. But, when we are at the lower bound (in this case, -128)
 * we encounter a problem. Suppose we wanted to find the negation of -128:
 *
 * -128 = 10000000
 *
 * Invert: 01111111
 *
 * Add 1: 10000000
 *
 * D'oh! We're back where we started. Therefore, on the line in itoa()
 * where we try to 'make n positive', we don't. Because of this, all
 * our calculations to find the correct character from then on will
 * be incorrect, and we'll most likely end up with garbage. Furthermore,
 * because the test in the do-while loop is for positivity, we only go
 * through the loop once. All in all, it's a clusterfuck.
 *
 * So, to fix this in the code below, we don't attempt to negate n.
 * Rather, we just have branching behaviour in the loop based on the
 * sign of n. So, if n is negative we compensate in such as way as to
 * get the same behaviour as if we were dealing with a positive number.
 *
 * The two relevant lines are the statement inside the do-while loop, and
 * the loop's termination condition.
 *
 * For the statement, we simply negate the result of the modulus operation
 * if we have a negative number. At the end of the loop, we check for
 * n < 0 if the n is negative, and vice versa.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	int n;
	char s[22];

	n = INT_MIN;
	itoa(n, s);
	printf("%d = %s\n", n, s);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;

	i = 0;
	sign = n;
	do {
		s[i++] = (sign > 0) ? n % 10 + '0' : -(n % 10) + '0';
	} while (((sign > 0) && ((n /= 10) > 0)) || ((sign < 0) && ((n /= 10)
								< 0)));
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
