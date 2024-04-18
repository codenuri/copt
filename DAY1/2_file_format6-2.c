#include <stdio.h>

int main(void)
{
    char sa1[] = "Hello";
    char sa2[] = "Hello";
    char* sp1 = "Hello";
    char* sp2 = "Hello";

    // 아래 결과 예측해 보세요..
    // => 각각의 주소가 같은 주소인지 ? 다른 주소일지 ?
    printf("%p\n", sa1);
    printf("%p\n", sa2);
    printf("%p\n", sp1);
    printf("%p\n", sp2);
}

