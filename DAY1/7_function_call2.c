// 이번 예제는 인라인 어셈블리 사용합니다.
// => cl 컴파일러는 "32bit(x86)" 에서는 인라인 어셈블리 허용
// => 교재(14p ~ 참고)

#include <stdio.h>

// 함수의 인자 전달
// 32bit : 스택을 사용, 옵션을 지정하면 레지스터를 사용하게 할수도 있다.
//         레지스터가 빠르지만, 갯수에 제한이 있다. 
// 64bit : 인자 전달 전용 레지스터 사용. 

int Add(int a, int b)
{
	int c = a + b;

	return c;
}

int main()
{
	int n;

//	n = Add(1, 2);
	__asm
	{
		push	2		// 마지막 인자부터 차례대로 스택에 넣고
		push	1
		call    Add
		add     esp, 8  // 핵심 !
		
		mov n, eax      // eax에 있는 반환 값을 지역변수 n에 담기.
	}


	printf("main : %d\n", n);
}