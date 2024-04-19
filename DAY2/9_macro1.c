//#include <stdio.h>

// 매크로 관련 학습을 하실때는 -E -P 컴파일러 옵션을 잘 알아 두세요

// cl  소스.c -EP
// gcc 소스.c -E -P 


#define SQUARE(x) x * x
#define MAX 5

int main()
{
	int n = MAX;

	int ret = SQUARE(++n);

//	printf("%d\n", ret);
}