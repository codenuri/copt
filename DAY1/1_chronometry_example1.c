#include "chronometry.h"

const unsigned long long count = 100000000;

// 정수를 사용해서 덧셈.
void ex1()
{
	long long s = 0;

	for (unsigned long long i = 0; i <= count; i++)
		s += i;
}

// 실수를 사용해서 덧셈.
void ex2()
{
	double s = 0;

	for (double i = 0; i <= count; i++)
		s += i;
}

int main()
{
	// 시간 측정 방법 #1.
/*
	CHECK(START);
	ex1();
	CHECK(LAB);
	ex2();
	CHECK(END);
*/
	
	// 시간 측정 방법 #2
	// CHRONOMETRY(함수이름, 함수 인자들..)
	CHRONOMETRY(ex1);
	CHRONOMETRY(ex2);
}






// DAY1.zip 압축 풀고, visual studio 에서 열어 보세요
// => DAY1.vcproj 파일 더블 클릭

// visual studio 버전 확인.
// => 프로젝트 메뉴, 속성 메뉴 선택후
// => 플랫폼 도구집합 버전 설정. 
// => Ctrl + F5 로 잘 빌드 되는지 확인해 보세요


// 소스파일을 빌드에 "포함/제거" 하는 방법
// => 소스 파일이름을 선택후, 속성메뉴 선택
// => 나타난 창에서 "빌드에 포함" 항목을 설정하면됩니다.

// 수업     : 45 ~ 50분
// 쉬는시간 : 10 ~ 15분