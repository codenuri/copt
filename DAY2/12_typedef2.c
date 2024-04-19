
int n;			// n 은 int 타입 변수
int a[2];		// a 는 int[2] 타입(배열) 변수
int b[2][2];	// b 는 이차원 배열 변수
int (*p)[2];	// int[2] 배열을 가리키는 포인터 변수
void (*f)();	// 함수 포인터 변수

// 변수위치의 심볼은 "변수" 가 아니라 "별명" 이다.
typedef int N;			// N 은 int 타입 별명
typedef int A[2];		// A 는 int[2] 타입(배열) 별명
typedef int B[2][2];	// B 는 이차원 배열 별명
typedef int(*P)[2];	    // int[2] 배열을 가리키는 포인터 별명
typedef void (*F)();	// 함수 포인터 별명


int main()
{
	N n1; // int n1
	A a1; // int a1[2]
	B b1; // int b1[2][2]
	P p1; // int(*p1)[2]
	F f1; // void(*f1)()
}

