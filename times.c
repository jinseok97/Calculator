#include <stdio.h>
int times_equal(int i) ;
char pass_operand[10000][62], result[62] ;
int main()
{
	int j ;
	int i = 1 ;
	for(j = 61 ; j > 1 ; j--)
	{
		result[j] = result[j] * pass_operand[i + 1][j] - '0' ;
		if(result[j]>'9')
		{
			result[j - 1] = result[j - 1] - result[j - 1]%10 ;
			result[j] = result[j] % 10 ;
		}
	}
	times_equal(i) ;
	for(j = 0 ; j < 62 ; j++)
	{
		printf("result[%d] = %c\n", result[j]) ;
	}
	return 0 ;
}
int times_equal(int i)
{
	int j ;
	for(j = 0 ; j < 62 ; j++)
	{
		pass_operand[i - 1][j] = '0' ;
		pass_operand[i + 1][j] = '0' ;
	}
	pass_operand[0][1] ;
	pass_operand[0][50] = '0' ;
	pass_operand[0][51] = '9' ;
	pass_operand[0][53] = '.' ;
	pass_operand[2][1] ;
	pass_operand[2][50] = '0' ;
	pass_operand[2][51] = '1' ;
	pass_operand[0][52] = '.' ;
	pass_operand[0][53] = '1' ;
	for(j = 61 ; j > 1 ; j--)
	{
		result[j] = result[j] + pass_operand[i - 1][j] + pass_operand[i + 1][j] - '0' * 2 ;
		if(j != 53)
		{
			if(result[j] > '9')
			{
				result[j - 1] = result[j - 1] - result[j - 1] % 10 ;
				result[j] = result[j] % 10 ;
			}
			else
			{
				if(result[j] > '9')
				{
					result[j - 2] = result[j - 2] - result[j - 2] % 10 ;
					result[j] = result[j] % 10 ;
				}
			}
		}
		result[52] = '1' ;
		if(pass_operand[i - 1][1] == '-' && pass_operand[i + 1][1] == '-')
		{
			result[1] = '-' ;
		}
	}
}
