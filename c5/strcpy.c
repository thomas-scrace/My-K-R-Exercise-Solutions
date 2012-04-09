#include <stdio.h>

int main()
{
	char s1[] = "Hello";
	char s2[] = "olleH";
	char *p1 = s1;
	char *p2 = s2;

	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	while (*p1++ = *p2++) {
		;
	}
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
}
