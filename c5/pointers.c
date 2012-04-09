#include <stdio.h>

int main()
{
	int x = 1, y = 2, z[10] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
	int *p;
	p = &x;
	printf("[pointer] p is at memory location %p,  contains %p,"
		"and points at value %d\n", &p, p, *p);
	y = *p;
	printf("y contains value %d\n", y);
	x = 10;
	printf("y contains value %d\n", y);
	p = &z[0];
	for(x=0; x < 10; x++) {
		printf("pointer p points at %d\n", *p);
		p++;
	}
	*p = x;
	printf("z[9] has a value of%d\n", z[9]);
	p = &x;
	printf("pointer p points to a value of %d\n", *p);
	*p = *p + 1;
	printf("pointer p points to a value of %d\n", *p);
	printf("x = %d\n", x);
	
}
