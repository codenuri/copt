#include "chronometry.h"

const unsigned long long count = 10000000;

void ex1(int a, int b)
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		int n = a + b;
	}
}

void ex2(double a, double b)
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		double d = a + b;
	}
}

int main()
{
	// 인자가 있는 함수도 사용가능.
	CHRONOMETRY(ex1, 1,   2);
	CHRONOMETRY(ex2, 1.1, 2.2);	
}
