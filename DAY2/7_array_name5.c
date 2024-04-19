#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 아래 코드는 모두 동일한 코드 입니다.
	// => 모두 80 바이트를 동적할당 한것. 
	// => sizeof()는 컴파일 시간에 계산되는 연산자
	malloc(80);
	malloc(sizeof(int) * 20);
	malloc(sizeof(double) * 10);
	malloc(sizeof(int[5]) * 4);
	malloc(sizeof(int[2][5]) * 2);

	// malloc(크기) : 크기 만큼의 메모리를 할당하는 것.
	//                해당 메모리를 어떻게 사용할것인지는 반환된 주소를
	//                "어떤 타입의 포인터"에 담는가가 결정

	// int[N] 처럼 사용하려면 1차배열의 요소의 포인터(int*)에 저장

	int* p1 = (int*)malloc(80); // int p1[20] 처럼 사용하겠다는것.

	double* p2 = (double*)malloc(80); // double p2[10];


	// 핵심 : 동적할당된 메모리를 2차 배열처럼 사용하려면
	//       "이차배열의 요소의 포인터( 결국 1차 배열을 가리키는 포인터)" 에 담으세요

	int(*p3)[5] = (int(*)[5])malloc(80); // int p3[4][5]; 처럼 사용하겠다는것
	
	p3[0][0] = 10;
	p3[0][1] = 20;

}