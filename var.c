#include <stdio.h>
#include <string.h>
int main ()
{
    char a[10000][62] = {0};
    char c;
    char var[10][62] = {0}; // 전역변수로
    char tmp[100] = {0};
    int i, j, k, m, end;
    int q, w;
    int gap = 'A' - 'a';
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

    if (strcmp(a[0],"VAR") == 0)
    {
        for (i = 0; i < 10; i++)
            if (var[i][0] >= 'A' && var[i][0] <= 'Z') // 대문자일때
            {
                printf("%c = ", var[i][0]);
                for (j  = 1; j <= 61; j++)
                    printf("%c", var[i][j]);
            }
            if (var[i][0] >= 'a' && var[i][0] <= 'z') // 소문자일때 대문자로 출력
            {
                    printf("%c = ", var[i][0] + gap);
                    for (j = 1; j <= 61; j++)
                        printf("%c", var[i][j]);
            }
    }
    return 0;
}
