/*
 * K&R Exercise 2-1
 *
 * Determine the ranges of char, short, int,
 * and long variables, both signed and
 * unsigned, by printing appropriate values
 * from standard headers and by direct
 * computation. Harder if you compute them:
 * determine the ranges of the various
 * floating point types.
 *
 * Author: Thomas Scrace <tom@scrace.org>
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

signed char scmin();
signed short ssmin();
signed int simin();
signed long slmin();

main()
{
	unsigned char cmn, cmx;
	signed char scmn, scmx;
	unsigned short smx;
	short ssmn;
	unsigned int imx;
	int simn;
	unsigned long lmx;
	long slmn;

	cmx = -1;
	cmn = cmx + 1;
	scmn = scmin();
	scmx = scmn - 1;
	smx = -1;
	ssmn = ssmin();
	imx = -1;
	simn = simin();
	lmx = -1;
	slmn = slmin();

	printf("\n*****************INTEGRAL TYPES********************\n\n");

	printf("-----------values from standard headers-----------\n\n");

	printf("%21d :    char    : %d\n", 0, UCHAR_MAX);
	printf("%21d : signed char: %d\n", CHAR_MIN, CHAR_MAX);
	printf("%21d :    short   : %d\n", 0, USHRT_MAX);
	printf("%21d :signed short: %d\n", SHRT_MIN, SHRT_MAX);
	printf("%21d :     int    : %u\n", 0, UINT_MAX);
	printf("%21d : signed int : %d\n", INT_MIN, INT_MAX);
	printf("%21d :    long    : %lu\n", 0, ULONG_MAX);
        printf("%21ld :signed long : %ld\n", LONG_MIN, LONG_MAX);

	printf("\n-----------values by direct computation-----------\n\n");

        printf("%21d :    char    : %d\n", cmn, cmx);
       	printf("%21d : signed char: %d\n", scmn, scmx);
        printf("%21hd :    short   : %d\n", smx + 1, smx);
        printf("%21d :signed short: %hd\n", ssmn, ssmn - 1);
        printf("%21d :     int    : %u\n", imx + 1, imx);
        printf("%21d : signed int : %d\n", simn, simn - 1);
        printf("%21d :    long    : %lu\n", lmx + 1, lmx);
        printf("%21ld :signed long : %ld\n", slmn, slmn - 1);

        printf("\n**************FLOATING-POINT TYPES*****************\n\n");

	printf("-----------values from standard headers-------------\n\n");

        printf("%21.6e :    float    : %0.6e\n", FLT_MIN, FLT_MAX);
        printf("%21.10e :    double   : %0.10e\n", DBL_MIN, DBL_MAX);

	return 0;
}

/* scmin: return the minimum value of a signed char */
signed char scmin()
{
        signed char c, tmp;

        for (c = tmp = -2; c < 0; c = c * 2)
		tmp = c;
        return tmp;
}

/* ssmin: return the minimum value of a signed short */
signed short ssmin()
{
        signed short s, tmp;

        for (s = tmp = -2; s < 0; s = s * 2)
               tmp = s;
        return tmp;
}

/* simin: return the minimum value of a signed int */
signed int simin()
{
        signed int i, tmp;

        for (i = tmp = -2;i < 0; i = i * 2)
		tmp = i;
        return tmp;
}

/* slmin: return the minimum value of a signed long */
signed long slmin()
{
        signed long l, tmp;

        for (l = tmp = -2; l < 0; l = l * 2)
		tmp = l;
        return tmp;
}
