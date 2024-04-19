// 108 page
#include "chronometry.h"

const int count = 100000;
  
// 재귀 호출을 사용하면
// 1. 성능이 좋지 않습니다
// => push ebp 등의 prologue 실행
// => 인자를 스택에 넣고
// => 돌아올 주소도 스택에 넣고
// => 다시 함수 호출.. 

// 2. 재귀의 횟수가 많아지만 stack overflow
// => 호출시, "인자, 돌아올주소, 지역변수" 등이 계속 스택에 생성
// => 스택 크기는 디폴트로 1MB
// => 링크 옵션으로 변경은 가능.



// 0 ~ n 까지의 합을 구해서 반환하는 함수 만들기

// 1. 반복문 사용
int sum1(int n)
{
	int s = 0;
	for (int i = 0; i <= n; i++)
		s += i;
	return s;
}

// 2. 재귀 호출 사용.
int sum2(int n)
{
	if (n == 1) return 1;
	return n + sum2(n - 1);
}

void ex1()
{
	int ret = sum1(count);
	printf("%d\n", ret);
}

void ex2()
{
	int ret = sum2(count);
	printf("%d\n", ret);
}

int main()
{
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}
