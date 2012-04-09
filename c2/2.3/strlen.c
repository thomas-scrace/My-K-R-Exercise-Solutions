/*
 * Examples of strlen() from pages 38-39 of K&R
 */

#include <stdio.h>
#include <string.h>

int kr_strlen(char s[]);

main()
{
	printf("String length using strlen(): %d\n", strlen("This is"
						 "a string constant"));
	printf("String length using kr_strlen(): %d\n", kr_strlen("This is"
						 "a string constant"));
	return 0;
}

/* kr_strlen: The K&R version of strlen() */
int kr_strlen(char s[])
{
	int i;

	i = 0;
	while(s[i] != '\0')
		++i;
	return i;
}

