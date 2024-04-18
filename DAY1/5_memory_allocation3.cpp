#include "chronometry.h"
#include <stdlib.h>
#include <vector>
#include <array>

// C에는 "배열" 을 많이 사용하지만
// C++에서는 "std::vector" 가 편리해서 많이 사용합니다.

// 배열과 std::vector 는 
// => 생성후 요소 접근 속도는 거의 동일합니다.
// => 하지만 "생성시간" 에서 차이가 많이 납니다.
//    std::vector 는 모든 요소를 힙에놓기 때문에 할당 속도의 차이. 



const int count = 10000000;

void use_stack()
{
	int x[1000];
	x[0] = 0;
}
 
void use_heap()
{
//	std::vector<int> v(1000);

	std::array<int, 1000> v;  // 모든 요소를 스택에 만드는 컨테이너
							  // 진짜 배열과 동일한 성능!!

	v[0] = 0;
}

void ex1()
{
	for (int i = 0; i < count; i++)
	{
		use_stack();
	}
}

void ex2()
{
	for (int i = 0; i < count; i++)
	{
		use_heap();
	}
}

int main()
{

	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}




