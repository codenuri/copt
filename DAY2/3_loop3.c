#include "chronometry.h"

// 한번의 루프로 해결해라.
void bad()
{
    int cnt = 0;

    int n = 0b01110000111100001111000011110000;

    // 4바이트 변수에서 "1 인 비트의 갯수" 파악 
    // => 단, MSB 는 0 이어야 합니다.
	// => 32번의 루프 수행
    while (n != 0)
    {
        if (n & 1) cnt++;
        n >>= 1;
    }
    printf("%d\n", cnt);
}

void good()
{
    int cnt = 0;

    int n = 0b01110000111100001111000011110000;

    // 한번의 루프에서 "보다 많은 일을 수행" 하는 것이 유리할수 있다.
	// => 32번 => 8 번의 루프 수행
    while (n != 0)
    {
        if (n & 1) cnt++;
		if (n & 2) cnt++;
		if (n & 4) cnt++;
		if (n & 8) cnt++;
        n >>= 4;
    }
    printf("%d\n", cnt);
	
}


int main()
{
    CHECK(START);
    bad();
    CHECK(LAB);
    good();
    CHECK(END);
}
 
