// 이번 예제는 인라인 어셈블리 사용합니다.
// => cl 컴파일러는 "32bit(x86)" 에서는 인라인 어셈블리 허용
// => 교재(14p ~ 참고)

#include <stdio.h>

// 함수를 호출하는 것은
// 1. 약속된 방식으로 인자를 전달하고
// 2. 약속된 방식으로 반환값을 받는 것 => eax(32bit), rax(64bit)레지스터에 담아서 반환


int Add(int a, int b)
{
	int c = a + b;

	return c;
	/*
	__asm
	{
		mov  eax, c   // return c 의 의미, eax = c
	}
	*/
}

int main()
{
	int n;

//	n = Add(1, 2);
	Add(1, 2);

	// Add() 반환 값은 eax 레지스터에 있습니다. 인라인 어셈으로 직접 꺼내도 됩니다.
	__asm
	{
		mov  n, eax 
	}

	printf("main : %d\n", n);
}