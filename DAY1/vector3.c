#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define FACTOR 1.5
#define FACTOR 2

int main()
{
	// 4. 사용자가 -1을 입력할때 까지 계속 입력 받고 싶습니다.
	//    단, 입력된 모든 값은 보관되어 있어야 합니다.
//	int score[4]; // 지역변수, 스택에 놓이게 됩니다.
				  // 수명이 규칙대로만 사용가능합니다.
				  // 원할때 제거할수 없습니다.
				  // 스택 변수는 {} 을 벗어날때만 파괴 

	int size = 4;
	int* score = (int*)malloc(sizeof(int) * size);


	int count = 0; // 입력된 갯수

	int n = 0;

	while (1)
	{
		scanf_s("%d", &n);

		if (n == -1)
			break;

		score[count++] = n;



		if (count == size)
		{
			int* tmp = (int*)malloc(sizeof(int) * size * FACTOR);
			// 기존 버퍼내용 => 신규 버퍼에 복사
			memcpy(tmp, score, sizeof(int) * size);
			free(score);
			score = tmp;

			// 마지막 작업은 ?
			size = size * FACTOR;
		}
	}

	printf("입력된 갯수 : %d\n", count);
	printf("버퍼 크기   : %d\n", size );

	// 버퍼가 더이상 필요없다면 반드시 제거
	free(score); 
}

// 실행해서 1~9까지 입력후 -1 입력해 보세요
// C++ 사용하시는 분은 위 코드가 STL vector와 유사합니다.
// 위처럼 "크기를 키워 가면서 사용하는 배열을"  
// => 동적 배열 또는 vector 라고 합니다.


