#include <stdio.h>


int Add(int a, int b)	
{						// push ebp
	int c = a + b;		// mov  ebp, esp
						// sup  esp, 4    // 필요한 지역변수 크기(좀더 크게 잡을수도있습니다)
						// 
						// mov  eax, dword ptr[ebp+8]  // eax = 1번째 인자
						// add  eax, dword ptr[ebp+12] // eax += 2번째 인자
						// mov  dword ptr[ebp-4], eax  // c = eax 

	return c;			// mov  eax, dword ptr[ebp-4]
						
						// mov  esp, ebp
						// pop  ebp
						// ret 
}

int main()
{
	int n;

	n = Add(1, 2);	// push	 2
					// push  1
					// call Add
					// add  esp, 8
					// mov  dword ptr[ebp-4],  eax


	printf("main : %d\n", n);
}