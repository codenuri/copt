// 92 page
int main()
{
	int day = 30;
	int a = 0, b = 0, c = 0, d = 0, x = 0;

	// 1. 상수를 모아라.
	// => 상수끼리의 사칙 연산은 컴파일 시간에 수행합니다
	int cnt1 = 60 * day * 24 * 31;  // bad  => 단, 요즘 컴파일러는 컴파일러가 알아서
	int cnt2 = day * 60 * 24 * 31;  // good    이렇게 변경하기도 합니다.
		



	// 2. 표현식을 단순하게.
	// => 아래 2줄은 완전히 동일한 코드 입니다.
	// ax^3 + bx^2 + cx + d
	int y1 = a * x * x * x + b * x * x + c * x + d;  // 6번의 곱셈, 3번의 덧셈
	int y2 = (((a * x + b) * x + c) * x + d);		 // 3번의 곱셈, 3번의 덧셈




	// 3. increment 
	// => 항상 전위형이 빠릅니다. (임시변수를 만들 필요 없습니다.)
	int n1 = ++a; // a += 1; return a;
	int n2 = b++; // int temp = b; b += 1; return temp;


	// 결과를 받지 않고 단순하기 1만 증가 하려면 전위형이 좋습니다.
	// => 요즘 컴파일러는 결과를 받지 않은 경우, 아래 2줄은 동일한 
	//    기계어 코드 생성. 
	++n1;	// good
	n1++;	// bad  

	for (int i = 0; i < 10; ?? ) // i++ 보다는 ++i 좋지 않을까 ?
	{						
	}
}


// github.com/codenuri/copt 에서   

// DAY2.zip 받으시면 됩니다.