#include <stdio.h>
#include <string.h>

char input[1000][62], pass_operand[1000][62], dot[1000], result[62];

int input_f(void);
void pos_digit(int k);

int main()
{
	int i, k, end;
	char c;

    end = input_f(); //입력함수 호출 및 end 리턴값 저장
    
    for(k = 0; k <= end; k++) //각 배열(0~end) 자리배정함수 호출
        pos_digit(k);

    for(int i = 0; i <= end; i++)   //(확인작업)
        for(int j = 0; j < 62; j++)
            printf("pass_operand[%d][%d] = %c\n", i, j, pass_operand[i][j]);
    
    return 0;
}



//// 입 력 함 수 ////
int input_f(void)
{
	int i, end;
	char c;
	printf("(input) ");
	
	for(i = 0; i <= 1000; i++)
	{
    	scanf("%s", input[i]);
    	if((c = getchar()) == '\n')
        {
            end = i;
            break;
        }
	}
	return end;
}

//// 자 리 배 정 함 수 ////
void pos_digit(int k)
{
    int l, n, r, s, o, u;
    for(l = 0; l <= 62; l++)
    {
        if(input[k][l] == '.')
        {
            dot[k] = l;
            pass_operand[k][52] = input[k][dot[k]];
        }
    }
    if(pass_operand[k][52]=='.')						//입력된 값이 정수가 아닌 실수인 경우의 정수부 위치 배정
    {
        for(n = dot[k] - 1, o = 51; o >= 0; n--, o--)
        {
            if(n>=0 && input[k][n] != '-')
                pass_operand[k][o] = input[k][n];
            else if (n==0 && input[k][n] == '-')
                pass_operand[k][1] = input[k][n];
            else if (n < 0 && o > 1)
                pass_operand[k][o] = '0';
        }
        for(r = dot[k] + 1, s = 53; s <= 61; r++, s++)
        {
            if(input[k][r] >= '0' && input[k][r] <= '9')
                pass_operand[k][s] = input[k][r];
            else
                pass_operand[k][s] = '0';
        }
    }
    else if(pass_operand[k][52] != '.')					//입력된 값이 정수인 경우의 정수부 위치 배정
    {
        for(n = strlen(input[k]) - 1, o = 51;o >= 0; n--, o--)
        {
            if(input[k][n] == '+'||input[k][n] == '-'||input[k][n] == '*'||input[k][n] == '/'||input[k][n] == '%')
            {
                if(strlen(input[k]) > 1)					// 단항 연산자 - 저장
                {
                    pass_operand[k][1] = input[k][n];
                    pass_operand[k][51] = '0';
                }
                else if(strlen(input[k])==1)			// 이항 연산자 저장(+,-,*,/,%)
                    pass_operand[k][0] = input[k][n];
            }
            else
            {
                if(n >= 0 && o > 1)
                    pass_operand[k][o] = input[k][n];
                if(n < 0 && o > 1)
                    pass_operand[k][o] = '0';
            }
        }
        for(u = 53; u <= 61; u++)
            pass_operand[k][u] = '0';
    }
    pass_operand[k][52] = '.';
    
    return ;
}
