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
// => 핵심은 "재귀호출"이 함수의 마지막 부분에서 이루어 진다는 것
// => 재귀 호출이 종료되고 돌아와서는 하는 일이 없이 다시 반환만하게 됩니다.
// => 이경우 함수로 돌아오는 과정이 필요 없습니다.
//    따라서, 함수가 사용하던 지역변수등도 계속 보관될 필요도 없습니다.
// => 재귀 호출시, 새로운 스택을 사용하는 것이 아니라
//    현재 함수가 사용하던 스택을 다시 사용가능합니다.
// 
// => 컴파일러가 최적화해서 "현재 스택을 다시 사용하도록 하게 됩니다."
// => 컴파일러가 지원해야 합니다. 



// int ret = sum3(5)
//		     return sumTail(5, 1)
//				    return sumTail(4, 6)	
//						   return sumTail(3, 10)		
//						          return sumTail(2, 13)
//						                 return sumTail(1, 15)
//                                              return 15  <=== 재귀 종료

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
