// 11 page 그림
// PEView - 32bit
#include <stdio.h>
#include <stdlib.h>

// 아래 코드를 컴파일 했을때의 실행파일의 모양
// => 메모리 그림을 완벽히 이해 해 보세요
// => 11 page 참고

int  g1 = 0x11223344; 
char g2[] = "abcdefg";

void foo(void)
{
    static int sx = 0xAABBCCDD;
    int lx = 0x55667788;
    printf("hello world\n");

    int* p = (int*)malloc(sizeof(int) * 10);
    free(p);
}

int main(void)
{
    foo();
}
