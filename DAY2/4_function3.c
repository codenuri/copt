// 107 page
// call by value vs call by pointer

struct big
{
	int arr[1000];
	char str[1000];
};

// 함수 인자로 크기가 큰 타입을 받을때는
// call by value 는 복사본의 오버헤드가 있습니다.
void bad(struct big arg)	
{
}

// 이경우, call by pointer 가 좋습니다.
// 또한, 인자를 읽기만 하려면, const 를 붙이는 것이 안전합니다.
void good(const struct big* arg)	
{

}

int main()
{
	struct big b = { 0 };

	bad(b);
	good(&b);
}

