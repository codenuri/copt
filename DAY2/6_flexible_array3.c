// 114 page. flexible_array
#include <stdio.h>
#include <stdlib.h>

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
					// 구조체의 크기에 포함되지 않지만, pos 라는 이름은 사용가능합니다.
} SHAPES;


int main()
{
//	int x[0]; // error
//	SHAPES s;
//	printf("%d\n", sizeof(s)); // 4

	// 핵심 : flexible array 기술로 만든 구조체는 반드시 동적 메모리 할당으로 사용해야 합니다
	SHAPES* s = (SHAPES*)malloc(sizeof(SHAPES) + sizeof(POINT) * 5);

	// 위 코드의 결과는 count 와 5개의 배열이 선형적으로 (하나의 메모리)로 할당.
	// => 그리고, POINT 배열 부분에 접근할때 pos 이름을 사용하면 됩니다.
	s->count = 5;
	s->pos[0].x = 10;
	s->pos[0].y = 10;

	s->pos[1].x = 20;
	s->pos[1].y = 20;


	free(s);

}
