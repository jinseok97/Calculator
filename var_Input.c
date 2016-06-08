#include <stdio.h>
#include <string.h>
int main () {
	char a[10000][61] = {0};
	char c = 'a';
	char tmp[100] = {0};
	scanf("%[^\n]", a[0]); // 개행 되기 전까지 scanf로 받음
	for(;c<='z'; c++)
        {
		strcpy(tmp,"? = ");
		tmp[0] = c; // tmp의 첫번째 배열이 a부터 z까지 바뀜
		if (strncasecmp(a[0], tmp, 3) == 0) // 배열 a와 tmp가 앞으ㅔ 3자리가 같으면 strncasecmp의 값음 0
		{
			for (int i = 4; i<=61; i++) // 이경우에 면수는 자릴수 57자리까지 받음 수정해야할듯
			{
				printf("%c", a[0][i]);
			 }
			// 저 배열값을 변수에저장해야함
		}
	}
	return 0;
}	
