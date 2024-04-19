// 114 page. flexible_array
#include "chronometry.h"

typedef struct _point
{
	int x;
	int y;
} POINT;

// 방법 1. 배열이 아닌 포인터를 멤버로 하고
//         필요한 만큼 동적 메모리 할당.
typedef struct _shapes
{
	int count;		// 점의 갯수 
	POINT* pos;
} SHAPES;


int main()
{
	SHAPES s;
	s.count = 5;
	s.pos = (Point*)malloc(sizeof(Point) * s.count);
	
	// 사용하는 코드는 의도대로 되었습니다.
	// 그런데, 메모리 그림을 생각해 보세요. 선형 구조인가요 ??
	s.pos[0].x = 10;
	s.pos[0].y = 10;
	s.pos[1].x = 20;
}
