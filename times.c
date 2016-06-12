#include <stdio.h>
int times_equal(int i) ;
char pass_operand[10000][62], result[62] ;
int main()
{
	int j ;
	for(j = 61 ; j > 1 ; j--)
	{
		result[j] = result[j] * pass_operand[i + 1][j] - '0' ;
		if(result[j]>'9')
		{
			result[j - 1] = result[j] - result[j]%10 ;
			result[j] = result[j] % 10 ;
		}
