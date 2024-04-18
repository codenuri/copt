#include "chronometry.h"

// block 안에서는 지역변수 선언.

const unsigned long long count = 100000000;

void ex1()
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		int n = 10 + 20;
	}
}

void ex2()
{
	int n = 0;

	for (unsigned long long i = 0; i <= count; i++)
	{
		n = 10 + 20;
	}
}

int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
	
}
