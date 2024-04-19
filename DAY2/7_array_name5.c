#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 아래 코드는 모두 동일한 코드 입니다.
	malloc(80);
	malloc(sizeof(int) * 20);

	malloc(sizeof(double) * 10);
	malloc(sizeof(int[5]) * 4);
	malloc(sizeof(int[2][5]) * 2);
}