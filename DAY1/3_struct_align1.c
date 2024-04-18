#include <stdio.h>

// 현재 CPU 는 메모리를 읽어올때 주소를
// => 4의 배수로만 전달 가능합니다.
// => 설치 가능한 메모리의 용량을 최대한 늘리기 위한 선택!!
// => 아래 Packet1 에서 "padding" 이 없다면
//    packet.data 의 주소는 "1001" 같이 4의 배수가 아닙니다.
//    이 경우, 데이타를 읽어 올때 2번 메모리에 접근해야 합니다.
//   => 1000번지에서 읽고, 1004번지에서 읽어서 결합해야 합니다.

typedef struct _packet1
{
	char cmd;		// 1byte

//  char padding[3];// 컴파일러가 추가한것.
					// 각 멤버의 시작 주소를 4의 배수로 만들기 위해서

	int data;		// 4byte
} PACKET1;

#pragma pack(1)			// 구조체 멤버의 align 을 1바이트 단위로, 즉 padding 제거
typedef struct _packet2
{
	char cmd;
	int data;
} PACKET2;

int main()
{
	printf("%d\n", sizeof(PACKET1)); // 8byte
	printf("%d\n", sizeof(PACKET2));
}