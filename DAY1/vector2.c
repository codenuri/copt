#include <stdio.h>

// 배열의 크기로 변수 사용
// C89 문법 : 안됨
// C99 문법 : 가능.. 
// 단, gcc 는 지원하는데, visual studio 지원 안됨.


int main()
{
	int cnt = 0;

	printf("학생수를 입력해 주세요 >> ");
	scanf_s("%d", &cnt);

	// 3. 실행시간에 입력된 학생수 만큼 다시 점수를 입력 받아야 합니다.
	// 아래 코드는 
	// 1. vs 에서는 에러, gcc 가능
	// 2. gcc 라고 cnt 가 크다면 스택 오버플로우 발생
// 	int score[cnt];  // ? 

	// 위 경우 "동적 메모리 할당" 을 사용하면
	// 1. 모든 컴파일러에 대해서 동작하고
	// 2. 원할때 지울수 있고
	// 3. cnt 값이 커져도 힙은 자동 증가 기능이 있어서 안전합니다.
	
	int* score = (int*)malloc(sizeof(int) * cnt);

	score[0] = 10;

	free(score);

}