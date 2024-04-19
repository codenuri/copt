// offset_of  : 87 page
// list 소스  : 116 page
#include <stdio.h>

// offset of 매크로 기술

typedef struct _point
{
	int x;
	int y;
} POINT;

int main()
{
	POINT* p = 0; // p는 null pointer!!

	// p가 0(null pointer) 이므로 메모리에 접근하면 안됩니다.
//	p->x = 10;		// runtime error
//	Point pt = *p;	// runtime error


	// p 가 0 일때
	// "p->x = 10" 처럼 값을 넣을수는 없지만
	// "&(p->x)" 처럼 주소를 구할수 있습니다.

	//							p : 1000		p : 0
	printf("%p\n", &(p->x)); // 1000			0
	printf("%p\n", &(p->y)); // 1004			4

	// 위 코드는 x, y 멤버가 POINT 구조체에서 얼마나 떨어져 있는지 offset을 구하는코드

	// 아래 매크로를 이해해 보세요
#define OFFSET_OF(TYPE, MEMBER)  (int)&(((TYPE*)0)->MEMBER)

	printf("%d\n", OFFSET_OF(POINT, y));
}