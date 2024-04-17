#include "chronometry.h"

const unsigned long long count = 100000000;

void ex1()
{
	long long s = 0;

	for (unsigned long long i = 0; i <= count; i++)
		s += i;
}

void ex2()
{
	double s = 0;

	for (double i = 0; i <= count; i++)
		s += i;
}

int main()
{
	ex1();
	ex2();
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