// 108 page
#include "chronometry.h"

const int count = 1000000;

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

// 3. 꼬리 재귀
int sumTail(int n, int result)
{
	if (n == 1) return result;
	return sumTail(n - 1, result + n);
}

int sum3(int n)
{
	return sumTail(n, 1);
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

void ex3()
{
	int ret = sum3(count);
	printf("%d\n", ret);
}

int main()
{
	CHRONOMETRY(ex1); // 반복문
//	CHRONOMETRY(ex2); // 재귀 호출
	CHRONOMETRY(ex3); // 꼬리 재귀
}

// 꼬리 재귀(tale recursion)
// => 재귀 호출을 사용하지만
// => 호출의 오버헤드도 없고, stack overflow 도 발생하지 않음.
// => 반복문과 동일한 성능.
// => "함수형 언어" 의 내부 원리..
//    (함수형 언어는 재귀 호출을 많이 사용하지만, 느리지 않은 이유)

// 왜 재귀를 사용하나요 ? 반복문을 사용하면 되는데,, 
// => 일부 알고리즘은 재귀를 사용하면 간단하게 구현할수 있습니다.
// => tree 순회등의 기술.