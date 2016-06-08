#include <stdio.h>
#include <string.h>
char input[10000][62], pass_operand[10000][62], dot[10000];
int main()
{
	int i, j, k,l,m,n,o,p,q,r,s,t,u,end;
	char c;
	printf("Input:");
	for(i=0;i<=10000;i++)
		{scanf("%s",input[i]);
		 if((c=getchar())=='\n')
			 end=i;
			 break;
		}
	for(k=0;k<=end;k++)				//소수점의 위치 찾기 + 소수점의 위치 배정 (소수점이 있는경우 >> 입력된 숫자가 정수가 아닌 실수인 경우)
		for(l = 0;l<= 62;l++)
			{if(input[k][l] == '.') 
				{dot[k] = l;
			 	 pass_operand[k][52] = input[k][dot[k]];
				}
			}
	for(m=0;m<=end;m++)
		{if(pass_operand[m][52]=='.')						//입력된 값이 정수가 아닌 실수인 경우의 정수부 위치 배정
			{for(n = dot[m] - 1, o = 51; o >= 0; n--, o--)
				{if(n>=0&&input[m][n]!='-')
				 	pass_operand[m][o] = input[m][n];
				 else if (n==0&&input[m][n]=='-')
					 pass_operand[m][1] = input[m][n];
				 else if (n < 0 && o>1)
				 			pass_operand[m][o] = '0';	 
			
				}
			for(r = dot[m] + 1, s = 53; s <= 61; r++, s++)
					{if(input[m][r] >= '0' && input[m][r] <= '9')
					 	pass_operand[m][s] = input[m][r];
		 	 	 	 else 
					 	pass_operand[m][s] = '0';
					}
			}
		else if(pass_operand[m][52]!='.')					//입력된 값이 정수인 경우의 정수부 위치 배정
			{for(n=strlen(input[m])-1, o=51;o>=0;n--,o--)
				{if( input[m][n]=='+'||input[m][n]=='-'||input[m][n]=='*'||input[m][n]=='/'||input[m][n]=='%')
					{if(strlen(input[m])>1)
						pass_operand[m][1]=input[m][n];
					 else if(strlen(input[m])==1)
						pass_operand[m][0]=input[m][n];
					}
				 else 
				 	{if(n>=0&&o>1)	
				 	    pass_operand[m][o] = input[m][n];
				  	if(n<0&&o>1)
				 		pass_operand[m][o] = '0';	 
					}
				}
			 pass_operand[m][52]='.';
			 for(u=53;u<=61;u++)
				 pass_operand[m][u]='0';
			}
		}
	for(int i=0;i<= end;i++)							//왜 전체 숫자가 출력? 
		for(int j=0;j<=61;j++)
			printf("pass_operand[%2d][%2d]:%c\n",i,j,pass_operand[i][j]);
	return 0;
}
