#include "chronometry.h"

// 반복문 관련 조언들...
// loop1. 루프를 적게 사용하라 - 98 page

void foo(int n) {n = 10;}

void bad()
{
	int i;

	// 3번의 호출을 위해 loop 를 사용하는 것은 좋지 않다.
	for (i = 0; i < 3; i++)
	{
		foo(i);
	}
}

void good()
{
	foo(0); // call 할때 2~3 줄 정도의 기계어 코드 생성
	foo(1);
	foo(2);
}

int main()
{
	bad();
	good();
}
