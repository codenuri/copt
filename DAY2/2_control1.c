// "binary breakdown" 이라는 이름을 가지는 기술 - 94 page
void bad()
{
    int i = 8;

	// 8번의 비교 발생
    if (i == 1) {}
    else if (i == 2) {}
    else if (i == 3) {}
    else if (i == 4) {}
    else if (i == 5) {}
    else if (i == 6) {}
    else if (i == 7) {}
    else if (i == 8) {}
}


// 1 ~ 100 사이에 숫자 하나를 골랐습니다.
// => 맞혀 보세요.!!

void good()
{
    int i = 8;
	
	if ( i <= 4)
	{
		if ( i <= 2)
		{
			if ( i == 2) 
			{}
			else
			{}
		}
		else 
		{
		}
	}
	else 
	{
		// 생략
	}
}

int main()
{
    bad();
    good();
}
