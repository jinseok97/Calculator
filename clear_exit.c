#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
	char a[10000][61] = {0};
	scanf("%s", a[0]);
	if (strcmp(a[0], "clear") == 0) // 받은 문자열이 clear이면
		system("clear");
	if (strcmp(a[0], "end") == 0) // 받은 문자열이 end이면
		system("exit");
	return 0;
}
