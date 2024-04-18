#include "chronometry.h"

// 루프에서는 포인터를 "dereferencing" 사용하지 말라.

// [first ~ last] 구간의 합을 s 에 담는 함수. 

void bad(int first, int last, int* s)
{
	for (int i = first; i <= last; i++)
	{
		// s 가 가리키는 곳에 "가서" 값을 꺼내서 연산에 사용
		*s += i;
	}
}

void good(int first, int last, int* s)
{	
	// 지역변수를 사용해서 연산하고
	// 연산의 결과만 s 에 담으면 더 빠르다.
	int local = *s;

	for (int i = first; i <= last; i++)
	{
		local += i;  
	}
	*s = local;
}

const int count = 1000000;

void ex1()
{
	int s = 0;
	bad(1, count, &s);
}

void ex2()
{
	int s = 0;
	good(1, count, &s);
}

int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}
