// 105 page
#include "chronometry.h"


// 핵심 : 메모리 접근하는 코드는 "항상 캐쉬" 를 고려해서 작성하세요
// => 순차 접근이 빠른 이유는 "캐쉬에 올라온 데이타를 차례대로 사용가능하기 때문입니다.
// => 임의 접근하는 경우, 캐쉬가 계속 update 되어야 합니다.

#define count 10000

int arr[count][count]; // 10000*10000 2차원 배열

void ex1()
{
	// 2차원 배열의 각 요소를 메모리에 놓인 순서대로 차례로 접근
	// => 순차 접근(sequence access)
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			arr[i][j] = 0;
		}
	}
}
void ex2()
{
	// 2차원 배열의 각 요소를 메모리에 놓인 순서가 아닌 임의 접근
	// => 배열의 인덱스를 참고하세요.
	for (int i = 0; i < count; i++)
	{ 
		for (int j = 0; j < count; j++)
		{
			arr[j][i] = 0;
		}
	}
}

int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}
