// 7_array_name4.c

int main()
{
	// 변수 선언문에서 "변수 이름 제거"하면 타입이 됩니다.

	int n;		// n의 타입 : int
	double d;	// d의 타입 : double

	int x[3];	// x의 타입 : int[3]  <== 배열 타입 이라고 합니다.
//  int[3] x;  <== 이 표기가 더 좋지 않을까요 ? (java, C# 은 이렇게 !!)

	int* p1 = &n;		// p1 의 타입 : int*
	int(*p2)[3] = &x;	// p2 의 타입 : int(*)[3]
						//			  =>배열(int[3]) 을 가리키는 포인터 타입.
}