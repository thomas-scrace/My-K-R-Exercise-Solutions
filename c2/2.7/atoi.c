#include <stdio.h>

int atoi(char s[]);

int main()
{
	int i;
	char s[4];

	s[0] = '1';
	s[1] = '0';
	s[2] = '1';
	s[3] = '\0';

	i = atoi(s);
	printf("%d\n", i);
	return 0;	
}

/* atoi: convert s to integer */
int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
	return n;
}
