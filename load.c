#include <stdio.h>
#include <stdlib.h>
int main () {
	FILE *save; // 포인터
	char a[10000][61] = {0};
	save = fopen("var_save.txt","r"); // var_save.txt를 읽기파일로 연다
	fscanf(save, "%s", a[0]); // var_save.txt 파일 읽어 저장
	fclose(save); // var_save.txt 닫기
	printf("%s", a[0]); // 확인용
	return 0;
}
