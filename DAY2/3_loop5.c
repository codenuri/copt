#include <string.h>
#include "counter.h"

// 반복문에서 함수 호출 제거

void bad()
{
	char s[] = "to be or not to be";

	// 아래 코드는 strlen() 함수가 문자열의 길이 만큼 호출됩니다.
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ' ')
			s[i] = '*';
	}
}

void good()
{
	char s[] = "to be or not to be";

	// 함수 호출을 먼저하고, 결과를 반복문에서 사용.
//	unsigned int sz = strlen(s);
	const unsigned int sz = strlen(s); // 변경되지 않는 다면 상수가 빠르고 안전
	
	for (int i = 0; i < sz; i++)
	{
		if (s[i] == ' ')
			s[i] = '*';
	}
	
}


int main()
{
	bad();
	good();
}
