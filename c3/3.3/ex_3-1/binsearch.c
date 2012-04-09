/*
 * K&R Exercise 3-1
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run time.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

/* Timing results:
 *
 * Old binsearch:
 *
 * real	0m0.002s
 * user	0m0.000s
 * sys	0m0.001s
 *
 * New binsearch:
 *
 * real	0m0.001s
 * user	0m0.000s
 * sys	0m0.002s
 */


#include <stdio.h>

int binsearch(int x, int v[], int n);

/* main(): test out the binsearch() function. */
int main()
{
	int v[5];
	v[0] = 'a';
	v[1] = 'b';
	v[2] = 'c';
	v[3] = 'd';
	v[4] = '\0';
	printf("x is at position %d\n", binsearch('c', v, 4));
	return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low+high) / 2;
		if (x <= v[mid])
			high = mid -1;
		else
			low = mid + 1;
	}
	if (v[mid] == x)
		return mid;
	else if (v[high] == x)
		return high;
	else if (v[low] == x)
		return low;
	return -1;	/* no match */
}
