#include <stdio.h>

__declspec(naked) void f2()
{
	__asm
	{

	}
}

__declspec(naked) void f1()
{
	__asm
	{
		// f2 함수 호출하기 #1. jmp 명령 사용
		jmp f2 


		//===================================== 이 윗부분만 이해해 보세요.
		mov   eax, 10
		ret
	}
}

int main()
{
	int ret;

	ret = f1();

	printf("main : %d\n", ret);
}