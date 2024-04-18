#include <stdio.h>

// 아래 코드를 godbolt.org 에 넣어 보세요
// 아무일도 하지 않은 함수를 만들어도
// => C 컴파일러가 반드시 필요한 최소의 기계어 코드 생성
// => prolog, epilog 라고 합니다.

// __declspec(naked) : prolog, epilog 를 만들지 말라.
//					  즉, 어떠한 코드도 자동생성하지 말라는 것
//					  개발자가 직접 inline 어셈으로 만들겠다는 의도
//					  주로, 디바이스 드라이버 개발에서 사용


__declspec(naked) void f1()
{
	
}

int main()
{
	f1();
}

