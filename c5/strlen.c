/* p. 99 */

#include <stdio.h>

int strln(char *s);

int main()
{
	int i;
	char array[100];
	char *ptr = "Hello, world!";

	for (i = 0; i < 100; i++) {
		array[i] = 32 + i;
	}
	printf("\"Hello, world!\" is %d chars long.\n", strln("Hello, world!"));
	printf("array[100] is  %d chars long.\n", strln(array));
	printf("ptr is %d chars long.\n", strln(ptr));
	for (i = 0; i < 100; i++) {
		printf("array[%d]\t%c\n", i, array[i]);
	}
}

/* strln: return length of string s */
int strln(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}
