#include "chronometry.h"

#define LOOPCOUNT 100000

// 일반 함수의 호출
// 1. 인자를 약속된 장소에 넣고(32bit 스택, 64bit 레지스터)
// 2. 함수로 이동(call add1)
//     => 돌아올 주소를 스택에 넣고!
//     => jmp add1 
int add1(int a, int b)
{
	return a + b;
}

// 매크로 함수
// 1. 호출이 아닌 문자 치환 방식
#define add2(x, y)   ((x) + (y))

void bad()
{
	int n1 = 0;
	int x = 10, y = 20;

	for (int i = 0; i < LOOPCOUNT; i++)
	{
		n1 = add1(x, y);
	}
	printf("bad : %d\n", n1);
}

void good()
{
	int n1 = 0;
	int x = 10, y = 20;

	for (int i = 0; i < LOOPCOUNT; i++)
	{
		n1 = add2(x, y);
	}
	printf("good : %d\n", n1);
}

int main()
{
	CHRONOMETRY(bad);
	CHRONOMETRY(good);
}
