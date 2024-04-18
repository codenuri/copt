// 106 page
#include "chronometry.h"
#include <thread>  



const int sz = 10000000;
 
long long n1 = 0;
long long n2 = 0;

// 해결책 3. 전역변수에 직접 연산하지 말고,
// => 지역변수로 연산후에
// => 결과만 전역변수에 담으면 된다.

void f1()
{
	int local1 = n1;

	for (int i = 0; i < sz; i++)
	{
		local1 += 1;
	}
	n1 = local1;
}

void f2()
{
	int local2 = n2;

	for (int i = 0; i < sz; i++)
	{
		local2 += 1;
	}
	n2 = local2;
}

void single_thread()
{
	f1();
	f2();
}


void multi__thread()
{
	std::thread t1(f1);
	std::thread t2(f2);
	t1.join();
	t2.join();
}

int main()
{
	CHRONOMETRY(single_thread);
	CHRONOMETRY(multi__thread);
}
