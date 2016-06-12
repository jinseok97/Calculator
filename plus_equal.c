#include <stdio.h>
int plus_equal(int i);
char pass_operand[10000][62], result[62];
int main()
{
	int i=1;

	plus_equal(i);
	for(int j=0;j<62;j++)
		printf("result[%d]=%c\n",j,result[j]);
	return 0;
}
int plus_equal(int i)																//부호가 같은 경우 덧셈
{
	for(int j=0;j<62;j++)
		{pass_operand[i-1][j]='0';
		 pass_operand[i+1][j]='0';
		}
	pass_operand[0][1];
	pass_operand[0][50]='0';
	pass_operand[0][51]='9';
	pass_operand[0][52]='.';
	pass_operand[0][53]='9';
	pass_operand[2][1];
	pass_operand[2][50]='0';
	pass_operand[2][51]='1';
	pass_operand[0][52]='.';
	pass_operand[0][53]='1';
	for(int j=0;j<62;j++)
		result[j]='0';
	for(int j=61;j>1;j--)
		{result[j]=result[j]+pass_operand[i-1][j]+pass_operand[i+1][j]-'0'*2;		//같은 자릿수 덧셈
		 if(j!=53)																//소수점 아래 첫째 자리의 합이 10보다 큰 경우
		 	if(result[j]>'9')														//덧셈 결과 자릿수가 9보다 큰 경우
		 		{result[j-1]++;			
				 result[j]=result[j]-10;	
				}
		 else
		 	if(result[j]>'9')														//덧셈 결과 자릿수가 9보다 큰 경우
		 		{result[j-2]++;			
				 result[j]=result[j]-10;	
				}

			
		}
	result[52]='.';
	if(pass_operand[i-1][1]=='-'&&pass_operand[i+1][1]=='-')
		result[1]='-';
	//오류 코드 보내기 코딩 필요 
	//중간 결과 값 저장 코딩 필요 
}

