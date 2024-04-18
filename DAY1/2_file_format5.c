#include <stdio.h>
#include <stdlib.h>

int g = 10;

int main()
{
	static int s = 10;
	int n = 10;

	// 아래 코드의 결과로 나오는 주소들의 생각해 보세요.
	printf("main 주소      : %p\n", &main);  // .text 섹션
	printf("전역변수 주소   : %p\n", &g);		//  .data 섹션
	printf("static지역 주소:%p\n", &s);		//  .data 섹션
	printf("지역 주소      :%p\n", &n);		//  "stack 메모리"

	int* p = (int*)malloc(4);
	printf("힙 할당 주소    : %p\n", p);		// "힙메모리"
	printf("포인터변수 p주소 : %p\n", &p);	// "stack 메모리"

	free(p);
}
