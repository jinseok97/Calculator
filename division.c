#include <stdio.h>
int pass_operand[10000][62]={0};
char result[62], result_share[62];
int first_1, first_2, last_2;
int move(int i,int share);
void move_left(int i, int first_1,int first_2, int last_2);
void move_right(int i, int first_1, int first_2, int last_2);
int minus(int);
int minus_equal(int);
int minus_first(int);
int minus_second(int);
int minus_dif(int);
int plus(int i);
int plus_equal(int i);																//부호가 같은 경우 덧셈
int plus_dif_1(int i);													//부호가 다를 때 앞의 수가 뒤의 수보다 큰 경우 
int plus_dif_2(int i);													//부호가 다를 때 앞의 수가 뒤의 수보다 작은 경우 
int sign_decision_1(int i);
int sign_decision_2(int i);
int main()
{	int i=1,k;
	int share=0;
	int start_end_1=1;
	int start_end_2=1;
	int end;
	for(int j=0;j<62;j++)
	{
		pass_operand[i-1][j]='0';
		pass_operand[i+1][j]='0';
		result[j]='0';
		result_share[j]='0';
	}
	pass_operand[i-1][51]='0';
	pass_operand[i-1][50]='0';
	pass_operand[i-1][49]='1';
	pass_operand[i+1][51]='0';
	pass_operand[i+1][50]='1';
	while(start_end_1)
	{	
		printf("start_end_1 시작\n");
		printf("pre move\n");
		printf("share=%d",share);
		move(i,share);							//자리수 맞추기
		printf("after move\n");
		start_end_2=1;
		while(start_end_2)	
		{	printf("start_end_2 시작\n");
			printf("pre minus\n");
			minus(i);							//pass_operand[i-1][j]에서 pass_operand[i+1][j]빼기
			printf("after minus\n");
			for(int j=1;j<62;j++)
				pass_operand[i-1][j]=result[j];
			if(result[1]=='0')	  				//뺀 결과가 0이상의 실수인 경우
				for(k=2;k<62;k++)
				{
					if(result[k]>'0')			//뺀 결과가 양수인 경우
					{result_share[share]++;
						break;
					}
					if(result[k]=='0')	 		//뺀 결과가 0인 경우
					{end++;
					}
				}
			else if(result[1]=='-')			//뺀 결과가 음수 인경우
			{	printf("plus 시작\n");
				plus(i);
				printf("plus 끝\n");
			 	for(int j=1;j<62;j++)
					pass_operand[i-1][j]=result[j];
				start_end_2--;	 
				printf("start_end_2 끝\n");
			}
			if(end>=59)
			{start_end_2--;
				result_share[share]=result_share[share]+1;
				end=0;
				printf("start_end_2 끝");
			}
		}
		printf("share=%d\n",share);
		if(share==61) 
			{start_end_1--;
			 printf("start_end_1 끝");
			}
	}  
	for(int i=0;i<62;i++)		 
		printf("%d",result_share[i]);
	return 0;
}
int move(int i, int share)
{ 	
	printf("move 시작");
	printf("share(move)=%d",share);
	int j;
	if(share==0)
	{
		for(int j=2;j<62;j++)											//나눠 지는 수의 첫째 자리의 자리수 구하기 
			if(pass_operand[i-1][j]>'0'&&pass_operand[i-1][j]<='9'&&pass_operand[i-1][j]!='.')
			{first_1=j;
				break;
			}	 
		for(int j=2;j<62;j++)											//나누는 수의 첫째 자리의 자리수 구하기 
			if(pass_operand[i+1][j]>'0'&&pass_operand[i+1][j]<='9'&&pass_operand[i+1][j]!='.')
			{first_2=j;
				break;
			}	 
		for(int j=61; j>=first_2;j--)									//나누는 수의 마지막 자리수 구하기 
		{if(j==51&&pass_operand[i+1][j]=='0')
			{last_2=j;
				break;
			}
			if(pass_operand[i+1][j]>'0'&&pass_operand[i+1][j]<='9'&&pass_operand[i+1][j]!='.')
			{last_2=j;
				break;
			}
		}

		for(;;)
		{
			if(first_1<first_2)												//나눠지는 수 < 나누는 수 일 때의 자리 배정
			{	move_left(i, first_1, first_2, last_2);
				if(first_2!=53)
					first_2--;
				else if(first_2==53)
					first_2=first_2-2;
				if(last_2!=53)
					last_2--;
				else if(last_2==53)
					last_2=last_2-2;
			} 
			else if(first_1==first_2)
				break;
			if(first_1>first_2)											//나눠지는 수 > 나누는 수 일 때의 자리 배정
			{move_right(i, first_1, first_2, last_2);
				if(first_2!=51)
					first_2++;
				else if(first_2==51)
					first_2=first_2+2;
				if(last_2!=51)
					last_2++;
				else if(last_2==51)
					last_2=last_2+2;
			} 
			else if(first_1==first_2)
				break;
		}	
	}
	else if(share!=0)
	{
		move_right(i,first_1,first_2,last_2);
		if(first_2!=51)
			first_2++;
		else if(first_2==51)
			first_2=first_2+2;
		if(last_2!=51)
			last_2++;
		else if(last_2==51)
			last_2=last_2+2;
	}
	share=last_2;
	return last_2;
}
void move_left(int i, int first_1,int first_2, int last_2)
{
	for(int j=first_2;j<62;)
	{
		if(pass_operand[i+1][j]!='.')
		{
			if(j!=53)
			{
				pass_operand[i+1][j-1]=pass_operand[i+1][j];
				pass_operand[i+1][j]='0';
				j++;
			}
			else if(j==53)	
			{
				pass_operand[i+1][j-2]=pass_operand[i+1][j];
				pass_operand[i+1][j]='0';
			}
		}

		else if(pass_operand[i+1][first_2]=='.')		
			j++;
	}
	return ;

}
void move_right(int i, int first_1, int first_2, int last_2)
{		
	for(int j=last_2;j>=first_2;)
	{if(pass_operand[i+1][j]!='.')
		{
			if(pass_operand[i+1][j+1]!='.')
			{pass_operand[i+1][j+1]=pass_operand[i+1][j];
				pass_operand[i+1][j]='0';	
				j--;
			}
			else if(pass_operand[i+1][j+1]=='.')
			{
				pass_operand[i+1][j+2]=pass_operand[i+1][j]	;
				pass_operand[i+1][j]='0';
				j--;
			}
		}
		else if(pass_operand[i+1][j]=='.')	
			j--;

	}
	return;
}


int minus(int i)
{
	for(int j=0;j<62;j++)
		result[j]='0';
	if(pass_operand[i-1][1]==pass_operand[i+1][1])
		minus_equal(i);
	else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
		minus_dif(i);
	return 0;
}

int minus_equal(int i)
{
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
		{if(result[j]<'0')														//덧셈 결과 자릿수가 9보다 큰 경우
			{result[j-1]--;			
				result[j]=result[j]+10;	
			}
		}
		else
			if(result[j]<'0')														//소수점 아래 첫째 자리 덧셈 결과 자릿수가 9보다 큰 경우
			{result[j-2]--;			
				result[j]=result[j]-10;	
			}


	}
	if(pass_operand[i-1][1]==0&&pass_operand[i+1][1]==0)
		result[1]='0';
	else if(pass_operand[i-1][1]=='-'&&pass_operand[i+1][1]=='-')
		result[1]='0';
	else if(pass_operand[i-1][1]=='-'&&pass_operand[i+1][1]=='-')
		result[1]='-';
	for(int j=0;j<62;j++)
		printf("result[%d]=%c",j,result[j]);

}
int minus_second(int i)
{		
	for(int j=61;j>1;j--)
	{result[j]=result[j]+pass_operand[i+1][j]-pass_operand[i-1][j];		//같은 자릿수 덧셈
		if(j!=53)																//소수점 아래 첫째 자리의 합이 10보다 큰 경우
		{if(result[j]<'0')														//덧셈 결과 자릿수가 9보다 큰 경우
			{result[j-1]--;			
				result[j]=result[j]+10;	
			}
		}
		else
			if(result[j]<'0')														//덧셈 결과 자릿수가 9보다 큰 경우
			{
				result[j-2]--;			
				result[j]=result[j]+10;	
			}


	}
	if(pass_operand[i-1][1]==0&&pass_operand[i+1][1]==0)
		result[1]='-';
	else if(pass_operand[i-1][1]=='-'&&pass_operand[i+1][1]=='-')
		result[1]='0';
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
int plus(int i)
{	

	for(int j=0;j<62;j++)
		result[j]='0';
	if(pass_operand[i-1][1]==pass_operand[i+1][1])
		plus_equal(i);
	else if(pass_operand[i-1][1]!=pass_operand[i+1][1])
		for(int j=2;j<62;j++)	
		{
			if(pass_operand[i-1][j]>pass_operand[i+1][j])
			{
				plus_dif_1(i);
				sign_decision_1(i);
				break;
			}
			else if(pass_operand[i+1][j]>pass_operand[i-1][j])
			{
				plus_dif_2(i);
				sign_decision_2(i);
				break;
			}
		}
	result[52]='.';
	return 0;

}
int plus_equal(int i)																//부호가 같은 경우 덧셈
{
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
}
int plus_dif_1(int i)													//부호가 다를 때 앞의 수가 뒤의 수보다 큰 경우 
{	for(int j=61;j>1;j--)
	{result[j]=result[j]+pass_operand[i-1][j]-pass_operand[i+1][j];
		if(j!=53)
		{if(result[j]<'0')
			{result[j-1]=result[j-1]-1;
				result[j]=result[j]+10;
			}	
		}   	
		else if(j==53)
			if(result[j]<'0')
			{result[j-2]=result[j-2]-1;
				result[j]=result[j]+10;
			}	

	}
	result[1]=0;
}
int plus_dif_2(int i)													//부호가 다를 때 앞의 수가 뒤의 수보다 작은 경우 
{	for(int j=61;j>1;j--)
	{result[j]=result[j]+pass_operand[i+1][j]-pass_operand[i-1][j];
		if(j!=53)
		{if(result[j]<'0')
			{
				result[j-1]=result[j-1]-1;
				result[j]=result[j]+10;
			}	
		}   	
		else if(j==53)
			if(result[j]<'0')
			{
				result[j-2]=result[j-2]-1;
				result[j]=result[j]+10;
			}	
	}
}	
int sign_decision_1(int i)
{
	if(pass_operand[i-1][1]=='-'&&pass_operand[i+1][1]==0)
	{result[1]='-';
	}
	if(pass_operand[i-1][1]==0&&pass_operand[i+1][1]=='-')
	{result[1]='0';
	}
}
int sign_decision_2(int i)
{	
	if(pass_operand[i+1][1]=='-' && pass_operand[i-1][1]==0)
	{result[1]='-';
	}
	if(pass_operand[i+1][1]==0 && pass_operand[i-1][1]=='-')
	{
		result[1]='0';
	} 
}
