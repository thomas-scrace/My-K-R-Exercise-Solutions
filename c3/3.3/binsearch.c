/*
 * binsearch()
 * K&R p. 58
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
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1;	/* no match */
}
