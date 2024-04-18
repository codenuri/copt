// if-else if 보다 switch 가 더 잘 최적화 된다.
// => 기계어가 좀더 작습니다.
// => godbolt.org 에 접속해 보세요..

void bad()
{
    int num = 0;
    int i = 8;

    if (i == 1) { num = 1; }
    else if (i == 2) { num = 2; }
    else if (i == 3) { num = 3; }
    else if (i == 4) { num = 4; }
    else if (i == 5) { num = 5; }
    else if (i == 6) { num = 6; }
    else if (i == 7) { num = 7; }
    else if (i == 8) { num = 8; }
}

void good()
{
    int num = 0;
    int i = 8;
    switch (i)
    {
    case 1: num = 1; break;
    case 2: num = 2; break;
    case 3: num = 3; break;
    case 4: num = 4; break;
    case 5: num = 5; break;
    case 6: num = 6; break;
    case 7: num = 7; break;
    case 8: num = 8; break;
    }
}

int main()
{
    bad();
    good();
}
