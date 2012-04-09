#include <stdio.h>

void swap(int *px, int *py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int main()
{
	int x = 2, y = 4;
	printf("Before swap, x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("After swap, x = %d, y = %d\n", x, y);
}
