// 106 page
#include "chronometry.h"
#include <thread>  

// 이번 예제는 "스레드 생성을 편리하게 하기 위해, .cpp" 로 했습니다.


const int sz = 10000000; 


// f1 은 "n1만 접근", f2는 "n2만 접근" 합니다.
// => 서로 관여하지는 않습니다.
// => 하지만, n1, n2 가 나란히 선언되었기 때문에
// => 2개의 CPU 캐쉬에 모두 존재 합니다.
// => CPUA 는 n1 만 사용하지만, CPUB가 n2 변경시, 
//    CPUA 의 캐쉬를 다시 UPDATE 해야 합니다.
//    현재 코드는 캐쉬 UPDATE 때문에 너무 오버헤드가 큽니다.

// 그럼  cpu에서 캐시의 n1, n2 값과 메모리의 n1, n2 값을 계속 비교하고 있나요?
// =>

// 나쁜 코드, 
// long long n1 = 0;
// long long n2 = 0;


// 방법 1. 2개의 변수 사이에 padding 넣기
// long long n1 = 0;
// char padding[64]; // 64 바이트 만틈 떨어지도록!!
// long long n2 = 0;

// 방법 2. C/C++ 표준 문법으로 변수의 시작 주소를 64바이트 단위로 설정하면 됩니다.
// C언어   : _Alignas  (C11 부터)
// C++언어 : alignas   (C++11부터)

#ifdef __cplusplus 
	alignas(64) long long n1 = 0;
	alignas(64) long long n2 = 0;
#else 
	_Alignas(64) long long n1 = 0;
	_Alignas(64) long long n2 = 0;
#endif 

// printf("%p\n", &n1);  출력되는 주소가 64의 배수로 나오게 됩니다.
// => 복습 할때 align 이 있을때와 없을때 n1, n2 주소를 출력해 보세요


void f1()
{
	for (int i = 0; i < sz; i++)
	{
		n1 += 1;
	}
}

void f2()
{
	for (int i = 0; i < sz; i++)
	{
		n2 += 1;
	}
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
