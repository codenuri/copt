#include "counter.h"
#include <stdlib.h>

// 스택 : 프로그램 실행시 "1M" 가 이미 할당되어 있습니다.
//	      => 순차적으로만 사용가능 합니다.
//        => 나중에 만든 변수가 먼저 파괴(?) 됩니다.
//        => 먼저 만든 변수를 먼저 파괴 할수 없습니다.
//        => 메모리 할당/해지는 아주 빠르게 동작합니다.

// 힙 : 실행시에 원하는 크기의 공간을 찾아야 합니다.
//       => 언제라도 할당/해지 할수 있는 자유가 있지만
//	     => 할당 해지 속도가 느립니다.


const int count = 10000000;

void use_stack()
{
	int x[1000];
	x[0] = 0;
}

void use_heap()
{
	int* x = (int*)malloc(sizeof(int) * 1000);

	x[0] = 0;

	free(x);
}



void ex1()
{
	for (int i = 0; i < count; i++)
	{
		use_stack();
	}
}

void ex2()
{
	for (int i = 0; i < count; i++)
	{
		use_heap();
	}
}

int main()
{

	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}




