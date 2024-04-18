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
