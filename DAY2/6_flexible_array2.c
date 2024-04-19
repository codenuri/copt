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
	// => 복습하실때 꼭 메모리 구조 그려 보세요
	// => s의 메모리와 s.pos 의 메모리는 별도의 공간입니다.
	//    n/w 로 전송등을 해야 한다면 불편합니다
	// => s 와 Point 배열을 같은 메모리에 한번에 담을수 없을까요 ?
	// => flexibile_array 기술(3번에서 구현)

	s.pos[0].x = 10;
	s.pos[0].y = 10;
	s.pos[1].x = 20;
}
