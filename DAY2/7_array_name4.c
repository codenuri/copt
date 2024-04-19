// 7_array_name4.c

int main()
{
	// 변수 선언문에서 "변수이름제거"하면 타입이 됩니다.
	int n;
	double d;
	int x[3];

	int* p1 = &n;
	int(*p2)[3] = &x;
}