#include <stdio.h>

// visual studio
// Debug 빌드시   : _DEBUG 라는 매크로가 자동으로 정의 되고
// Release 빌드시 : _DEBUG 라는 매크로정의 안됨.

// 가변인자 매크로 기술
// 매크로함수 만들때 : ... 사용
// __VA_ARGS__ : ... 에 전달된 모든 내용을 그대로 적용해 달라는 것

#ifdef _DEBUG 
#define dprint(...) printf( __VA_ARGS__ )
#else 
#define dprint(...) 
#endif

int main()
{
	int n = 0;

	dprint("debug message : %d, %p\n", n, &n);
}