#include <stdio.h>
#include <stdlib.h>

// 32bit 실행파일 : 포인터 크기가 4byte 
// 64bit 실행파일 : 포인터 크기가 8byte

// 아래 코드는 32bit 용
/*
typedef struct _bullet
{
	int x;
	union
	{
		int y;
		struct _bullet* next;
	};
} bullet;
*/
// 아래 코드는 64bit 용
typedef struct _bullet
{
	// 아래 공용체는
	// 1. x, y 로 사용하거나(이름 없는 구조체가 핵심, 이름이 없어야 .x 로 바로 접근)
	//												이름이 있으면 p->이름.x 로 해야 합니다.
	// 2. * next 로 사용하거나!
	union
	{
		struct
		{
			int x;
			int y;
		};
		struct _bullet* next;
	};
} bullet;


int main()
{
	printf("%d\n", sizeof(bullet));	// 32bit 일때와 64bit 일때 결과 확인해 보세요
}
