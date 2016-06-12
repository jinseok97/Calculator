#include <stdio.h>
int main ()
{
    char a[10000][62] = {0};
    char var[10][62] = {0}; // 전역변수로
    char c;
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
    gap = 'A' - 'a';
    for (i = 0; i <= 61; i++)
        if (a[i][0] <= 'z' && a[i][0] >= 'A') // 수식에 알파벳이 있으면
            for (k = 0; k <= 9; k++)
                if (a[i][0] == var[k][0] || a[i][0] + gap == var[k][0] || a[i][0] - gap == var[k][0])
                    // 그 알파벳이 var의 0번째 배열과 같으면
                    // 그 값을 받은 수식의 변수부분에 넣는다
                    for (m = j; m <= 61; m++)
                    {
                        a[i][m] = var[k][m+1];
                    }
    return 0;
}
    // 입력된 배열이 알파벳이면 그 알파벳을 var 배열의 0번째와 비교해서 맞으면 var배열의 1번째 값부터 배열에 다시 넣는다
