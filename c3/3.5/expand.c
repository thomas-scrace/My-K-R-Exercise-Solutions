/* K&R Exercise 3-3
 * Write a function expand(s1,s2) that expands shorthand notations like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
 * taken literally.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>

int expand(char s1[], char s2[]);
int find_end(int i, char s1[]);
int insert(int i, int start, int end, char s2[]);

/* main just demos the functionality. We set up a test string and run
 * it through expand().
 */
int main()
{
	int i;
	char string[10];
	char copy[40];

	string[0] = ' ';
	string[1] = '-';
	string[2] = 'z';
	string[3] = 't';
	string[4] = 'o';
	string[5] = 'm';
	string[6] = 'G';
	string[7] = '-';
	string[8] = 'K';
	string[9] = '\0';
	for (i = 0; i < 39; i++)
		copy[i] = 0;
	copy[39] = '\0';
	printf("string[], before expand = %s\n", string);
	printf("copy[], before expand = %s\n", copy);
	if (expand(string, copy) == 0)
		printf("copy[], after expand = %s\n", copy);
	else
		printf("error during expand");
	return 0;
}

int expand(char s1[], char s2[])
{
	int i, j, l, m;
	int start, end;

	for (i = j = 0; s1[i] != '\0'; i++, j++) {
		if (s1[i] == '-') {
			start = s1[i-1];
			if (m = find_end(i, s1)) {
				end = s1[m];
			} else {
				return -1;
			}
			if (j = insert(j-1, start, end, s2)) {
				i = m;
			} else {
				return -1;
			}
		} else {
			s2[j] = s1[i];
		}
	}
	s2[j] = '\0';
	return 0;
}

/* find_end(): return the high bound of the group */
int find_end(int i, char s1[])
{
	int removed;

	for (removed = 0; removed != 2; i++) {
		if (s1[i] == '-')
			removed = 0;
		else
			removed++;
	}
	return i-2;
}

/* insert(): make sure we have a good range, then insert the range
 * into s2. Return new insert location in s2, -1 otherwise.
 */
int insert(int i, int start, int end, char s2[])
{
	printf("our start param is %c\n", start);
	printf("our end param is %c\n", end);
	int tmp;
	tmp = i;
	/* first, make sure we have at least one range limit */
	if (! isalnum(start) && ! isalnum(end))
		return -1;
	if (isalnum(start) && isalnum(end)) {
		/* make sure we have matching params */
		if (isdigit(start) && isdigit(end))
			;
		else if (islower(start) && islower(end))
			;
		else if (isupper(start) && isupper(end))
			;
		else
			return -1; /*mismatched range params */
	/* then we fill in any missing parameters */
	} else if (isalnum(start)) {
		if (isdigit(start))
			end = '9';
		else if (islower(start))
			end = 'z';
		else if (isupper(start))
			end = 'Z';
	} else if (isalnum(end)) {
		if (isdigit(end))
			start = '0';
		else if (islower(end))
			start = 'a';
		else if (isupper(end))
			start = 'A';
	} else {
		return -1;
	}
	printf("our start param is %c\n", start);
	printf("our end param is %c\n", end);
	/* finally, we have a good range, so let's iterate over it */
	for (; start <= end; i++, start++)
		s2[i] = start;
	return i - 1;
}
