#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[10000][61]={0}, b[100]={0}, c[10]={0};
	int x, idx, j, k, i, d, dot[100];

	printf("Start . . .\n");
	printf("(Input) ");
	
	//scanf 문자열 입력
	for(i = 0; i<=3 ; i++)
		scanf("%s", &a[i]);

	//입력된 숫자의 자릿수
	idx = strlen(a[x]); 
	printf("자릿수 : %d\n", idx);	

	//점의 위치[인덱스]
	for(j = 0; j <= 30; j++)
	{
		for(i = 0; i <= idx; i++)
			if(a[j][i] == '.')
			{
				dot[i] = i;
				break;
			}
		if(dot[j] != 0) printf("점 위치[] : %d\n", dot[j]);
	}

	//입력받은  항목들
	for(j = 0; j <= idx; j++)
		printf("a[%d][~] : %s\n", j, &a[j]);
	return 0;
}
// 배열값 초기화 과정 필요
