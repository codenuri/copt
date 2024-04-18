#include <stdio.h>

// 루프 안에서는 변수를 만들지 말라

void bad()
{
	while (1)
	{
		int num = 0;
		scanf_s("%d", &num);
		if (num == -1) break;
	}
}

void good()
{
	// 루프 안에서 변수를 만들지 말고, 루프밖에서 만든후에 사용하세요
	// => 1. 요즘에는 num 처럼 primitive 타입이면 위와 아래는 유사합니다.
	// => 2. 단, 객체지향 언어에는 아주 차이가 큽니다.(소멸자 호출!!!)
	int num = 0;
	while (1)
	{
		scanf_s("%d", &num);
		if (num == -1) break;
	}
}

int main()
{
	bad();
	good();
}
