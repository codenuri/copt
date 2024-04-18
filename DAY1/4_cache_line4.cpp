// cache 와 reorder
// => 성능이야기는 아니고, "멀티스레드의 어려움을 알려주는 예제"
// => 참고로만 알아 두세요

#include <atomic>

int a = 0;
int b = 0;

// thread A
void foo()
{
    a = b + 1;

    std::atomic_thread_fence(std::memory_order_seq_cst);

    b = 1;
}

// thread B
void goo()
{
    if (b == 1)
    {
        // a == 1 을 보장할수 있을까 ? <<== 핵심
    }
}
// godbolt.org 에서 "C++" 언어로 설정하세요
// => 위 코드 넣어 보세요




