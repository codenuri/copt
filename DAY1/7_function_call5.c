#include <stdio.h>

// C 언어의 인자 전달의 원리
// => 마지막 인자부터 차례대로 스택에 넣어 준다.

__declspec(naked) void f2()
{
	__asm
	{
		// 인자에 접근 하는 방법.
		// => ESP 레지스터를 사용해서 접근합니다.
		// => [ESP+4] 는 1번째 인자, [ESP+8] 이 2번째 인자 접근 입니다.
		// => 아래 코드는 "return 1번째인자 + 2번째 인자"
		// => eax 에 담으면 반환 값의 의미 이미로
		mov eax, dword ptr [esp+4]   // [] 가 *(esp-4)의 의미
		add eax, dword ptr [esp+8]
 
		ret   
	}
}

__declspec(naked) int f1()
{
	__asm
	{		
		push 2
		push 1 
		call f2  // f2(1, 2) 의 의미 

		add  esp, 8

		//===================================== 이 윗부분만 이해해 보세요.
//		mov   eax, 10
		ret
	}
}

int main()
{
	int ret;

	ret = f1();

	printf("main : %d\n", ret);
}