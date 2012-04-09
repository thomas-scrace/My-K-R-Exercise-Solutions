/* K&R 4.10 - Recursion
 */

#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

/* main: demo qsort */
int main()
{
	int v[] = { 0, 4, 9, 2, 5, 1, 12, 4, 90 };
	int left = 0;
	int right = 8;
	int i;
	for (i = 0; i <= 8; i++)
		printf("%d\n", v[i]);
	qsort(v, left, right);
	for (i = 0; i <= 8; i++)
		printf("%d\n", v[i]);
}
	

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(int v[], int left, int right)
{
	int i, last;

	if (left >= right)					/* if array contains < 2 elements... */
		return;							/* ...do nothing */
	swap(v, left, (left + right) / 2);	/* move partition element... */
	last = left;						/* ...to v[0] */
	for (i = left + 1; i <= right; i++)	/* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);				/* restore partition element */
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}	