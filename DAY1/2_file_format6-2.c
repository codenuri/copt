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

    // 결론
    // 1. 읽기만 하는 문자열을 사용할때는 
    // => "문자열 배열" 을 사용하지 말고 "문자열 포인터" 를 사용하세요

    // 2. 문자열 포인터를 사용할때는 C언어라도
    // => "char*" 로 하지 말도 되도록 "const char*" 로 하세요.. 안전합니다.
}
// RUST 언어의 문자열, str/String
// str    : 문자열 포인터
// String : 문자열 배열과 유사

// C++언어의 string_view 가 문자열 포인터 입니다. 