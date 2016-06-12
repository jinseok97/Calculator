#include <stdio.h>
char pass_operand[10000][62],result[62];
int minus_equal(int);
int minus_first(int);
int minus_second(int);
int minus_dif(int);
int main()
{	int i=1;
	pass_operand[i][0]='-';
	for(int j=0;j<62;j++)
		{pass_operand[i-1][j]='0';
		 pass_operand[i+1][j]='0';
		}
	pass_operand[i-1][1]=0;
	pass_operand[i-1][50]='0';
	pass_operand[i-1][51]='9';
	pass_operand[i-1][52]='.';
	pass_operand[i-1][53]='9';
	pass_operand[i+1][1]='-';
	pass_operand[i+1][50]='1';
	pass_operand[i+1][51]='1';
	pass_operand[i+1][52]='.';
	pass_operand[i+1][53]='1';
	if(pass_operand[i-1][1]==pass_operand[i+1][1])
			minus_equal(i);
	else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
			minus_dif(i);
	for(int j=0;j<62;j++)
		printf("result[%d]=%c\n",j,result[j]);	
	return 0;
}

int minus_equal(int i)
{
	for(int j=0;j<62;j++)
		result[j]='0';
	for(int j=2;j<62;j++)
		if(pass_operand[i-1][j]>pass_operand[i+1][j])
					{minus_first(i);
					 break;
				 	}	
		else if(pass_operand[i-1][j]<pass_operand[i+1][j])
					{minus_second(i);
					 break;
				 	}	
   	
	result[52]='.';
}
int minus_first(int i)															//앞 수가 뒤 수 보다 큰 경우
{
		for(int j=61;j>1;j--)
			{result[j]=result[j]+pass_operand[i-1][j]-pass_operand[i+1][j];		
		 	 if(j!=53)																
		 		if(result[j]<'0')														//덧셈 결과 자릿수가 9보다 큰 경우
		 			{result[j-1]--;			
				 	 result[j]=result[j]+10;	
					}
		 	 else
		 		if(result[j]<'0')														//소수점 아래 첫째 자리 덧셈 결과 자릿수가 9보다 큰 경우
		 			{result[j-2]--;			
				 	 result[j]=result[j]-10;	
					}

			
			}
		if(pass_operand[i-1][1]==0&&pass_operand[i+1][1]==0)
			result[1]=0;
		else if(pass_operand[i-1][1]=='-'&&pass_operand[i+1][1]=='-')
			result[1]='-';
		
}
int minus_second(int i)
{		printf("2\n");
		for(int j=61;j>1;j--)
			{result[j]=result[j]+pass_operand[i+1][j]-pass_operand[i-1][j];		//같은 자릿수 덧셈
		 	 if(j!=53)																//소수점 아래 첫째 자리의 합이 10보다 큰 경우
		 		if(result[j]<'0')														//덧셈 결과 자릿수가 9보다 큰 경우
		 			{result[j-1]--;			
				 	result[j]=result[j]+10;	
					}
		 	 else
		 		if(result[j]<'0')														//덧셈 결과 자릿수가 9보다 큰 경우
		 			{result[j-2]--;			
				 	 result[j]=result[j]+10;	
					}

			
			}
		if(pass_operand[i-1][1]==0&&pass_operand[i+1][1]==0)
			result[1]='-';
		else if(pass_operand[i-1][1]=='-'&&pass_operand[i+1][1]=='-')
			result[1]=0;
}

int minus_dif(int i)													//부호가 다를 때
{	for(int j=0;j<62;j++)
		result[j]='0';
	for(int j=61;j>1;j--)
		{result[j]=result[j]+pass_operand[i-1][j]+pass_operand[i+1][j]-'0'*2;
		 if(j!=53)
		 	{if(result[j]>'9')
				{result[j-1]=result[j-1]+1;
			 	 result[j]=result[j]-10;
		 		}	
			}
		 else if(j==53)
		 	{if(result[j]>'9')
				{result[j-2]=result[j-2]+1;
				 result[j]=result[j]-10;
				}
			}		
		}
	if(pass_operand[i-1][1]==0&&pass_operand[i+1][1]=='-')
		result[1]='0';
	else if(pass_operand[i-1][1]=='-'&&pass_operand[i+1][1]==0)
		result[1]='-';	
	result[52]='.';
}
