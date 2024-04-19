#include "chronometry.h"

// 1. 재귀 호출 사용.
// => 아래 재귀 호출은 "재귀호출" 부분이 함수의 마지막이 아닙니다.
// => 호출을 마치고 return 되어 왔을때, 추가로 해야할일이 있습니다.
// => 그래서 돌아오는 과정이 생략될수 없습니다.(최적화 될수 없다는것)

// int ret = sum2(5)
//           return 5 + sum2(4)
//					    return 4 + sum2(3)
//								   return 3 + sum2(2)
//										      return 2 + sum2(1)
//														 return 1; <<== 재귀종료
//														 


int sum2(int n)
{
	if (n == 1) return 1;
	return n + sum2(n - 1);
}




// 2. 꼬리 재귀(Tale Recursion)

int sumTail(int n, int result)
{
	if (n == 1) return result;
	return sumTail(n - 1, result + n);
}

int sum3(int n)
{
	return sumTail(n, 1);
}



int main()
{
	int cnt = 10000;
	int ret1 = sum2(cnt);
	int ret2 = sum3(cnt);
}
