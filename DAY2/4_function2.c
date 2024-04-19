#include <stdio.h>

#define SQUARE(x) (x) * (x)

int main()
{
	// 매크로 함수의 장점
	// 1. 빠르다
	// 2. Generic! => 모든 타입에 대해서 사용가능하다는 것.
	//               즉, 아래 처럼 int, double 에 대해서 모두 동작
	int    r1 = SQUARE(3);		// 3 * 3
	double r2 = SQUARE(3.4);    // 3.4 * 3.4

	// 단점 : 버그가 많다.
	// => 되도록 () 를 많이 사용하세요!
	// => () 가 있어도 "++" 등을 인자에 포함하면 잘못된 결과가 나옵니다
	//    해결책은 없습니다. 주의 해야 합니다.
	int n = 3;

//	int ret = SQUARE(n+1); // (n + 1) * (n + 1)
	int ret = SQUARE(++n); // (++n) * (++n)  <== 25가 나오는데, undefined 입니다.

	printf("%d\n", ret);
}

