#include <stdio.h>

__declspec(naked) void f2()
{
	__asm
	{
		// 스택에 있는 돌아갈 주소를 꺼내서 ebx 레지스터에 담습니다
		// 아무 레지스터나 사용해도 됩니다.
		pop  ebx 
		jmp  ebx // 결국 NEXT 위치로 이동
	}
}

__declspec(naked) int f1()
{
	__asm
	{
		// f2 함수 호출하기 #1. jmp 명령 사용
		// => 이 경우 반드시 돌아올 주소를 알려 주어야 합니다.
		// => C 언어는 돌아올 주소를 스택에 넣어서 알려 주게 됩니다.
		push    NEXT   // 스택에 "NEXT 레이블이 있는 곳의 주소" 넣기
		jmp f2 
	NEXT:


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