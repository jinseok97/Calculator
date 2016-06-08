#include <stdio.h>
#include <stdlib.h>
int main () {
	FILE *save; // 포인터
	char a[10000][61] = {0};
	scanf("%s", a[0]);
	save = fopen("var_save.txt","w"); // var_save.txt를 쓰기 파일로 연다
	fprintf(save, "%s", a[0]); // var_save.txt에 문자열을 저장
	fclose(save); // var_save.txt 닫기
	return 0;
}
