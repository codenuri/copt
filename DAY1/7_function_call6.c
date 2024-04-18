#include <stdio.h>

// 스택 : 스레드당 한개씩 생성됩니다.
//       스레드를 추가로 생성하지 않는 다면 스택은 한개 이고
//       모든 함수가 같이 사용합니다.

// 함수의 지역변수 만들기(26 p 참고)
//  

__declspec(naked) void f2()
{
	__asm
	{
		push ebp 
		mov  ebp, esp 	
		// 지역변수 만들기
		sub	 esp, 8		// 결국 int x, y 같은 의미

		mov  dword ptr[ebp - 4], 10
		mov  dword ptr[ebp - 8], 20

		// push 1000 
		mov eax, dword ptr[ebp + 8]
		add eax, dword ptr[ebp + 12]

		// 지역변수 파괴
	//	add  esp, 8	// 이렇게 해도 되지만
		mov  esp, ebp 
		pop ebp 
		ret
	}
}




__declspec(naked) int f1()
{
	__asm
	{
		push 2
		push 1
		call f2  

		add  esp, 8
		//===================================== 이 윗부분만 이해해 보세요.
		ret
	}
}
int main()
{
	int ret;

	ret = f1();

	printf("main : %d\n", ret);
}