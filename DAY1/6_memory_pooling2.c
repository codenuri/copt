#include <stdio.h>
#include <stdlib.h>

typedef struct _bullet
{
	int x;
	union
	{
		int y;
		struct _bullet* next;
	};
} bullet;

bullet* pool_head = 0;

#define SIZE 200

void init_pool()
{
	// 총알 200개를 한번에 할당!
	pool_head = (bullet*)malloc(sizeof(bullet) * SIZE);

	// pool 안에 있는 200개의 총알을 list 형태로 연결
	for (int i = 0; i < SIZE - 1; i++)
	{
		pool_head[i].next = &pool_head[i + 1];
	}
}
void destroy_pool()
{
	free(pool_head);
	pool_head = 0;
}
// 이제 총알이 필요하면 pool 에 요청하면 됩니다.
bullet* pool_alloc()
{
	bullet* tmp = pool_head;
	pool_head = pool_head->next;

	return tmp;
}

// 아래 코드는
// 가장 최근 반납한 총알이 pool 의 처음에 놓이게 됩니다.(pool_head)
// => 이 경우, 다음에 요청시 "가장 최근에 사용한 메모리를 다시 할당" 하게 됩니다.
// => 가장 최근에 사용한 메모리는 "캐쉬등에 남아 있을확율이 높습니다."
// => 즉, 가장 빠르게 동작할수 있습니다.

void pool_free(bullet* p)
{
	p->next = pool_head;
	pool_head = p;
}



int main()
{
	init_pool();

	bullet* p1 = pool_alloc();
	bullet* p2 = pool_alloc();
	printf("p1 주소 : %p\n", p1);
	pool_free(p1);

	bullet* p3 = pool_alloc();
	printf("p3 주소 : %p\n", p3);
	pool_free(p2);
	pool_free(p3);
}
