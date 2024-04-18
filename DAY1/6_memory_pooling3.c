#include <stdio.h>
#include <stdlib.h>
#include "chronometry.h"

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

void pool_free(bullet* p)
{
	p->next = pool_head;
	pool_head = p;
}

const int count = 10000;

void ex1()
{
	for (int i = 0; i < count; i++)
	{
		bullet* p1 = (bullet*)malloc(sizeof(bullet));
		bullet* p2 = (bullet*)malloc(sizeof(bullet));

		free(p1);

		bullet* p3 = (bullet*)malloc(sizeof(bullet));

		free(p2);
		free(p3);
	}
}

void ex2()
{
	init_pool();

	for (int i = 0; i < count; i++)
	{
		bullet* p1 = pool_alloc();
		bullet* p2 = pool_alloc();
		pool_free(p1);

		bullet* p3 = pool_alloc();
		pool_free(p2);
		pool_free(p3);
	}
}

int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}
