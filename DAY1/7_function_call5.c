#include <stdio.h>

// C 언어의 인자 전달의 원리
// => 마지막 인자부터 차례대로 스택에 넣어 준다.

__declspec(naked) void f2()
{
	__asm
	{


		ret   
	}
}

__declspec(naked) int f1()
{
	__asm
	{
		call f2  

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