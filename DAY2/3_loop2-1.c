// 5_loop2-1.c

// 인자를 읽기만 하려고 합니다.
// 다음중 좋은 것은 ?

void good(int n)
{
	int a = n;
}

void bad(const int* p) 	// C++ : void f2(const int& r) 
{	
	int a = *p;			
}
int main()
{
	int x = 10;
	f1(x);
	f2(&x);
}