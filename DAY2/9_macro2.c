#include <stdio.h>

// 멀티 라인 매크로 기술
//#define PRESS()	 printf("press enter"); getchar();  

#define PRESS()	 { printf("press enter"); getchar(); }  

int main()
{
	int n = 0;


//	PRESS(); // ok


//	if ( n == 1 )
//		PRESS();	// { printf("press enter");
					//   getchar(); }

	// 아래 코드의 문제점과 해결책은
	if (n == 1)
		PRESS();
	else
	{
	}

	printf("finish main\n");
}