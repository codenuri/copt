// 114 page. flexible_array
#include "chronometry.h"

typedef struct _point
{
	int x;
	int y;
} POINT;

typedef struct _shapes
{
	int count;		

	POINT pos[0];	// 핵심. 
					// 일반적인 코드에서는 크기가 0인 배열을 만들수 없습니다.
					// 하지만, 구조체의 마지막 멤버로는 만들수 있습니다.
} SHAPES;


int main()
{
//	int x[0]; // error

	SHAPES s;
	printf("%d\n", sizeof(s)); // 4

}
