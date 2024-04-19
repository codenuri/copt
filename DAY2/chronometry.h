#include <windows.h>
#include <stdio.h>

const int START = 1;
const int END = 2;
const int LAB = 3;

void CHECK(const int check)
{
	static LARGE_INTEGER freq, start, end;

	if (check == START)
	{
		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&start); // GetTickCount()
	}
	else
	{
		QueryPerformanceCounter(&end);

		printf("%lf\n", (end.QuadPart - start.QuadPart) / (double)freq.QuadPart);

		if (check == LAB)
		{
			QueryPerformanceCounter(&start);
		}
	}
}


#define CHRONOMETRY(FUNC, ...)	do { CHECK(START); FUNC(__VA_ARGS__); printf("%s : ", #FUNC); CHECK(END); } while(0);

/*
CHECK(START); 
FUNC(__VA_ARGS__); 
printf("%s : ", #FUNC); // "ex1 : "
CHECK(END);             // 수행시간 출력

CHRONOMETRY(ex1, 1, 3.4);
*/