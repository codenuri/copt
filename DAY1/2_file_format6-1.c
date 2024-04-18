#include <stdio.h>

int main(void)
{
    char sa[] = "Hello"; 
    char* sp = "Hello";  

    // 아래 2줄에 대해서 생각해 봅시다.
    *sa = 'A'; // ok
    *sp = 'A'; // runtime error. read only memory
                // "정확히는 undefined 입니다."
                // 미정의 동작 발생.. 
    printf("AAAA\n");

    // 아래 한줄을 다시 생각해 봅시다.
    char* sp1 = "Hello"; // 읽기 전용 메모리를 const 가 아닌 포인터로
                        // 가리키는 것이 논리적으로 맞을까요 ??
                        // C 언어 : 허용,  C++ 언어 : 에러. 
}

