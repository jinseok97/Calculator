#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
    FILE *save; // 포인터
    char a[10000][62] = {0};
    char var[10][62] = {"123"}; // 전역변수로
    char c;
    int i, j, end;
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
    if (strcmp(a[0], "save") == 0)
    {
        save = fopen("var_save.txt","w"); // var_save.txt를 쓰기 파일로 연다
        for (i = 0; i <= 9; i++)
            for (j = 0; j <= 61; j++)
            {
                fprintf(save, "%c", var[i][j]); // var_save.txt에 문자열을 저장
            }
        fclose(save); // var_save.txt 닫기
    }
    return 0;

