#include <stdio.h>

// 전역변수
// => 실행중에 생성/파괴 되지 않고
// => 프로그램 실행시 생성되어서 계속 사용 가능

// 전역변수의 초기값 : 실행파일 안에 포함되어 있습니다.
int x = 0x99999999;
int y = 0x10203040;
int z = 0x90807060;

int main()
{
	printf("%x, %x, %x\n", x, y, z);
}

// Debug,
// 32bit(x86) 으로 빌드
// => 실행파일 만들어 두세요. Debug 폴더 아래 있습니다.

// 구글에서 PEView 검색 해서 1번째 링크에 있는것 다운 받으세요
// PEView.zip 압축 풀고, 
// 현재 실행파일 열어 보세요
