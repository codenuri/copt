#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>  // 이 헤더에 offsetof  매크로가 있습니다.
#include "list.h"

typedef struct _People
{
	char name[12];
	int  age;

	NODE vipList;	
} People;


// 이번 예제의 핵심 : list 안에 있는 모든 People 출력하기
void show_vip_list(NODE* head)
{
	NODE* cur = head->next;

	for ( ; cur != head; cur = cur->next)
	{
		int ds = offsetof(People, vipList);
	
		People* p = (People*)((char*)cur - ds); 

		printf("%s(%d), ", p->name, p->age);

	}

}




int main()
{
	NODE* vip_head = (NODE*)malloc(sizeof(NODE));
	init_list(vip_head);

	for (int i = 1; i < 10; i++)
	{
		People* p = (People*)malloc(sizeof(People));
		p->age = i;
		sprintf_s(p->name, "lee %d", i);

		insert_back(&(p->vipList), vip_head);
	}
}
