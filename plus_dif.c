#include <Stdio.h>
char pass_operand[10000][62];
int result[62];
int minus_1(int);
int minus_2(int);
int sign_decision_1(int i);
int sign_decision_2(int i);
int main()
{	
	
	
	pass_operand[0][1]='-';	
	pass_operand[0][51]='1';	
	pass_operand[0][52]='.';	
	pass_operand[0][53]='9';	
	pass_operand[2][1]=0;	
	pass_operand[2][51]='8';	
	pass_operand[2][52]='.';	
	pass_operand[2][53]='9';	
	int i=1;
	for(int j=0;j<62;j++)
		result[j]='0';
	for(int j=2;j<62;j++)	
		{if(pass_operand[i-1][j]>pass_operand[i+1][j])
			{minus_1(i);
			 printf("1\n");	
			 sign_decision_1(i);
			 break;
			}
	 	 else if(pass_operand[i+1][j]>pass_operand[i-1][j])
		 	{minus_2(i);
			 printf("2\n");	
			 sign_decision_2(i);
		 	 break;
			}
		}
	result[52]='.';
	for(int j=0;j<62;j++)
		printf("result[%d]=%c\n",j,result[j]);
	return 0;
	
}
int minus_1(int i)													//부호가 다를 때 앞의 수가 뒤의 수보다 큰 경우 
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
int minus_2(int i)													//부호가 다를 때 앞의 수가 뒤의 수보다 작은 경우 
{	for(int j=61;j>1;j--)
		{result[j]=result[j]+pass_operand[i+1][j]-pass_operand[i-1][j];
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
}	
int sign_decision_1(int i)
{	printf("pass_operand[0][1]=%d\n",pass_operand[0][1]);
	printf("pass_operand[2][1]=%c\n",pass_operand[2][1]);

	if(pass_operand[i-1][1]=='-'&&pass_operand[i+1][1]==0)
		{result[1]='-';
		 printf("sign_decision_2_'1'\n");
		}
	if(pass_operand[i-1][1]==0&&pass_operand[i+1][1]=='-')
		{result[1]=0;
		 printf("sign_decision_2_'1'\n");
		}
}
int sign_decision_2(int i)
{	printf("pass_operand[0][1]=%d\n",pass_operand[0][1]);
	printf("pass_operand[2][1]=%c\n",pass_operand[2][1]);
	if(pass_operand[i+1][1]=='-' && pass_operand[i-1][1]==0)
		{result[1]='-';
		 printf("sign_decision_2_'1'\n");
		}
	if(pass_operand[i+1][1]==0 && pass_operand[i-1][1]=='-')
		{result[1]=0;
		 printf("sign_decision_2_'2'\n");
		} 

}
