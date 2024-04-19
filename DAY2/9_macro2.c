#include <stdio.h>

// 멀티 라인 매크로 기술
//#define PRESS()	 printf("press enter"); getchar();  

// #define PRESS()	 { printf("press enter"); getchar(); }  

// 아래 기술이 멀티 라인 매크로 함수를 만들때 가장 안전하게 만드는 기술 입니다.
// => do ~ while(0) 매크로 기술
#define PRESS()	 do { printf("press enter"); getchar(); } while(0)

int main()
{
	int n = 0;


//	PRESS(); // ok

//	if ( n == 1 )
//		PRESS();	// { printf("press enter");
					//   getchar(); }

	// 아래 코드의 문제점과 해결책은
	if (n == 1)
		PRESS(); // { printf("press enter"); getchar(); };
				 // do { printf("press enter"); getchar(); } while(0);
	else
	{
	}

	printf("finish main\n");
}