
void foo(int a, double d)
{
}

int main()
{
	// 함수도 결국 코드 메모리에 있으므로
	// 주소 연산자를 사용하면 주소를 구할수 있습니다.

	void (*p1)(int, double) = &foo; // 이코드가 함수 주소를 구하는 코드
	void (*p2)(int, double) = foo; // function to pointer conversion 문법
									// 함수이름은 함수 주소로 암시적변환된다

	// 이름이 주소로 변경되는 2개의 문법
	// array    to pointer conversion : 배열의 이름은 배열의 첫번째 요소의 주소
	// function to pointer conversion : 함수이름은 함수 주소로 암시적변환된다
}
// cppreference.com  접속해 보세요
