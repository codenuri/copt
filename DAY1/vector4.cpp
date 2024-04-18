#include "chronometry.h"
#include <vector>
#include <list>
#include <stdlib.h>
#include <string.h>

// C++ 코드입니다.
// std::vector : 연속된 메모리를 사용하는 자료구조 ( vector3.c 소스의 원리와유사)
// std::list   : 더블 linked list, 모든 요소가 떨어진 메모리

// 10만개의 데이타를 계속 추가할때 누가 빠를까요 ?

#define INPUT_COUNT 100000

// 1,2,3,4 ... 순차적으로 반환.. 사용자 입력 시뮬레이션
int get_input()
{
	static int num = 0;
	++num;
	if (num == INPUT_COUNT)
	{
		num = 0;
		return -1;
	}
	return num;
}

void f1()
{
	int n = 0;
	std::vector<int> c;
	
	while (1)
	{
		n = get_input();

		if (n == -1)
			break;

		c.push_back(n);
	}
}

void f2()
{
	int n = 0;
	std::list<int> c; // 더블링크드 리스트 

	while (1)
	{
		n = get_input();

		if (n == -1)
			break;

		c.push_back(n);
	}
}

int x[INPUT_COUNT]; // 커다란 정적 배열

void f3()
{
	int n = 0;
	int i = 0;

	while (1)
	{
		n = get_input();

		if (n == -1)
			break;

		x[i++] = n;
	}
}

// C++ STL std::vector 는
// g++ 은 기존 크기의 2배 증가, visual studio 는 1.5 배 입니다.

// 따라서 아래 값을 2.0 으로 하면 visual studo 에서는
// => std::vector 보다 아래 코드가 더빠르게 나옵니다.

//#define FACTOR	1.5
#define FACTOR	2.0

void f4()
{
	int size = 4; 
	int* score = (int*)malloc(sizeof(int)*size);

	int count = 0;
	int n = 0;

	while (1)
	{
		n = get_input();

		if (n == -1)
			break;

		score[count++] = n;

		if ( size == count )
		{			
			int* tmp = (int*)malloc(sizeof(int) * size * FACTOR );

			memcpy(tmp, score, sizeof(int)* size);

			free(score);
			score = tmp;
			size = size * FACTOR;
		}
	}
}

int main()
{
	CHRONOMETRY(f1);
	CHRONOMETRY(f2);
	CHRONOMETRY(f3);
	CHRONOMETRY(f4);
}

