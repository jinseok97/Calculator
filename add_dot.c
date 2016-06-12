#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *add_dot(double val, char *buf, int round);
char *add_dot(double val, char *buf, int round)
{
	static char *result ;
	char *nmr ;
	int dp, sign ;
	result = buf ;
	if (round < 0)
	{
		round = -round ;
	}
	nmr = fcvt(val, round, &dp, &sign) ;
	if (sign)
	{
		*buf++ = '-' ;
	}
	if (dp <= 0)
	{
		if (dp < -round)
		{
			dp = -round ;
		}
		*buf++ = '0' ;
		*buf++ = '.' ;
		while(dp++)
		{
			*buf++ = '0' ;
		}
	}
	else
	{
		while (dp--)
		{
			*buf++ = *nmr++ ;
			if (dp % 3 == 0)
			{
				*buf++ = dp ? ',' : '.' ;
			}
		}
	}
	strcpy(buf, nmr) ;
	return result ;
}
int main()
{
	char buf[50] ;
	printf("%s\n", add_dot(1234567890, buf, 2)) ;
	printf("%s\n", add_dot(-1234567890, buf, 2)) ;
	return 0 ;
}
