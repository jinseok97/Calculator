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
            for (i = 2; i <= 10000; i++)
            {
                for (j = 0; j <= 61; j++)
                {
                    if (a[i][j] >= '0' && a[i][j] <= '9' || a[i][0] >= 'A' && a[i][0] <= 'z' || a[i][j] == 0 || a[i][j] == '.') // 변수의 값에 입력되는 것이 특수문자가 아닐때
                    {
                        m = 0;
                    }
                    else
                    {
                        m = 1;
                        break;
                    }
                }
            }
            // 변수 저장
            if (m == 0)
            {
                k = 2;
                while (k == 10000)
                {
                    if (a[k][0] >= 'A' && a[k][0] <= 'z')
                        var_use(a[k][0]); // var_use 함수 사용
                }
                for (j = 0; j <= 9; j++)
                {
                    if (var[j][0] == 0)
                    {
                        var[j][0] = c;
                        for (i = 1; i <= 61; i++)
                        {
                            var[j][i] = a[2][i-1]; // a[2][i-1] 을 result로 바꿔야할듯 (b = a+2와 같은 경우때문에) result 는 연산을 끝낸 후 값
                        }
                        break;
                    }
                }

                // 입력된 변수의 값 출력
                printf("= ");
                for (i = 0; i <= 61; i++)
                    printf("%c", a[2][i]); // a[2][i] 를 result로 바꿔야핟슬(b = a + 2와 같은 경우때문에) result 는 연산을 끝낸 후 값
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
