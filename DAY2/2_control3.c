// branch precondition
// 파이프라인
// => CPU 는 하나의 명령을 실행하면서, 
// => 다음 실행할 명령을 가져 옵니다.(캐쉬에 대기)
// => 모든 명령이 순차적으로 실행된다면 아주 빠르게 실행됩니다.
// 
// => 그런데, 분기문(if)이 있다고 가정해 보세요..
// => 어떤 명령을 가져올지 모릅니다.

void bad()
{
	int a = 10;
	int b = 10;

	if (a == 10)
	{
		b = 0;
	}
	else
	{
		b = 30;
	}
}

void good()
{
	int a = 10;
	int b = 10;

	// 리눅스 커널 내부 코드 등에서 많이 볼수 있는 기술
	// => 조건문이 true 또는 false 될 확률이 높다는 것을 컴파일러에게 알려주는것
	// => likely(표현식), unlikely(표현식)

//	if ( likely(a == 10) )  // gcc 는 ok,  cl 컴파일러 안됨. 
	if ( a == 10 ) [[ likely ]]  // C++ 언어에서는 표준 attributes 문법으로 제공(C++20)
	{				
		b = 0;
	}
	else  [[ unlikely ]]
	{
		b = 30;
	}
}

int main()
{

}