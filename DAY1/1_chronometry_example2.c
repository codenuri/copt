#include "chronometry.h"

const unsigned long long count = 10000000;

int add(int a, int b)
{
	return a + b;
}

extern inline int inline_add(int a, int b)
{
	return a + b;
}

void ex1()
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		int ret = add(1, 2);
	}
}

void ex2()
{
	for (unsigned long long i = 0; i <= count; i++)
	{
		int ret = inline_add(1, 2);
	}
}

int main()
{
	// 컴파일러 옵션에 따라 결과가 달라짐.
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);	
}

// 1. 윈도우 시작 버튼
// 2. visual studio 2022(또는 다른 버전) 폴더를 찾으세요
// 3. develop command prompt(개발자 명령 프롬프트) 선택

// 4. 나타나는 창에서 "cl" 입력후 엔터
// => 컴파일러 이름이 "cl.exe" 입니다.

// 5. 소스가 있는 곳으로 이동후

// cl 1_chronometry_example2.c   로 빌드후
// 1_chronometry_example2.exe 를 실행해 보세요 


// 아래 처럼 옵션을 지정해야 "인라인 치환"이 적용됩니다.
// cl 1_chronometry_example2.c -Ob1     


// 성능 측정은
// 컴파일러의 종류, 버전, Debug/Release 등에 따라 결과가 달라집니다.

// 가장 좋은 방법은 "컴파일러를 직접 사용하면서, 옵션을 다양하게 
//  변경해 보는 것이 좋습니다."

// gcc 는 "인라인만 활성화" 하는 옵션이 없습니다
// -O2 옵션(최적화)로 해보세요. 