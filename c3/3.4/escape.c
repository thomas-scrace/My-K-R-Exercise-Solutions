/* K&R Exercise 3-2
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible esape sequences like \n and \t as it copies the string t to
 * s. Use a switch. Write a function for the other direction as well,
 * converting escape sequences into real characters.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>

void escape(char t[], char s[]);
void re_escape(char t[], char s[]);

int main()
{
	int i;
	char string[10];
	char copy[12];

	string[0] = 'a';
	string[1] = 'b';
	string[2] = 'c';
	string[3] = '\t';
	string[4] = 'd';
	string[5] = 'e';
	string[6] = 'f';
	string[7] = '\n';
	string[8] = '1';
	string[9] = '\0';
	for (i = 0; i < 11; i++)
		copy[i] = 0;
	copy[11] = '\0';
	printf("copy[], before escape = %s", copy);
	escape(string, copy);
	printf("copy[], after escape = %s", copy);
	re_escape(string, copy);
	printf("copy[], after re_escape = %s", copy);
	return 0;
}

void escape(char t[], char s[])
{
	int i, j;
	for (i = 0; i < 11; i++)
		s[i] = 0;

	for (i = j = 0; t[i] != '\0'; i++, j++) {
		switch (t[i]) {
		case '\t':
			s[j] = '\\';
			s[++j] = 't';
			break;
		case '\n':
			s[j] = '\\';
			s[++j] = 'n';
			break;
		default:
			s[j] = t[i];
			break;
		}
	}
}

void re_escape(char t[], char s[])
{
	int i, j;
	int in_escape;
	for (i = 0; i < 11; i++)
		s[i] = 0;
	in_escape = 0;
	for (i = j = 0; t[i] != '\0'; i++, j++) {
		switch (t[i]) {
		case '\\':
			in_escape = 1;
			j--;
			break;
		case 't':
			s[j] = (in_escape) ? '\t' : 't';
			in_escape = 0;
			break;
		case 'n':
			s[j] = (in_escape) ? '\n' : 'n';
			in_escape = 0;
			break;
		default:
			in_escape = 0;
			s[j] = t[i];
			break;
		}
	}
}
