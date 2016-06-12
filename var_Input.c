#include <stdio.h>
#include <string.h>
void cal()
{
        char a[10000][62] = {0}, input[10000][62]={0};
        char b[10000][62] = {0};
        char c;
        char var[10][62] = {0}; // 전역변수로
        char tmp[100] = {0};
        int i, j, k, m, end;
        int gap;
        // 수식 받기
        for(i=0;i<=10000;i++)
        {
                scanf("%s",a[i]);
                if((c=getchar())=='\n')
                {
                        end=i;
                        break;
                }
        }

        // 변수를 받는 식인지 구분
        for(c = 'A'; c<='z'; c++)
        {
                strcpy(tmp,"? = ");
                tmp[0] = c; // tmp의 첫번째 배열이 a부터 z까지 바뀜
                if (a[0][0] == c && a[1][0] == '=')
                {
                        for (k = 0; k <= 61; k++)
                        {
                                if (a[2][k] >= '0' && a[2][k] <= '9' || a[2][k] == 0) // 변수의 값에 입력되는 것이 특수문자가 아닐때
                                {
                                        m = 0;
                                }
                                else
                                {
                                        m = 1;
                                        break;
                                }
                        }
                        // 변수 저장
                        if (m == 0)
                        {
                                for (j = 0; j <= 9; j++)
                                {
                                        if (var[j][0] == 0)
                                        {
                                                var[j][0] = c;
                                                for (i = 1; i <= 61; i++)
                                                {
                                                        var[j][i] = a[2][i-1];
                                                }
                                                break;
                                        }
                                }

                                // 입력된 변수의 값 출력
                                printf("= ");
                                for (i = 0; i <= 61; i++)
                                        printf("%c", a[2][i]);
                                printf("\n");
                        }
                        else if (m == 1)
                                printf("= error\n");
                }
        }
        return;
}
int main ()
{
        cal();
        main ();
        return 0;
}
