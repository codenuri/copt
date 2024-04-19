
// 아래 구조체는 구조체 자체를 사용하려고 만든 것이 아닙니다.
// => 구조체의 포인터 타입만 사용하려고 만든것 입니다.
// C++ : 멤버가 없는 구조체를 만들수 있다.(empty class 라고 합니다.)
// C   : 구조체는 반드시 멤버가 한개 이상 있어야 한다.
struct ICON   { int nonused; };
struct BITMAP { int nonused; };


typedef struct ICON   *HICON;   // HICON   은 ICON*   타입
typedef struct BITMAP *HBITMAP; // HBITMAP 은 BITMAP* 타입
		
// 포인터는 주소를 보관하는데, 주소도 결국 정수 입니다.!!
// ID 값을 포인터 변수에 저장해도 문제되지 않습니다.
// 서로 다른 구조체의 포인터 타입은 다른 타입 입니다.
// HICON, HBITMAP, HMENU, HCURSOR 등을 모두 다른 타입으로 설계한것


HICON CreateIcon()
{
	return (HICON)10;
}

void DrawBitmap(HBITMAP id) {}

int main()
{
	HICON icon_id = CreateIcon();

//	DrawBitmap(icon_id); // error.
						 // 타입 안전성이 좋아 졌습니다.
}

// 리눅스에서 "pthread_t" 타입이 위처럼 설계되었습니다.
// windows api 에서 HICON, HBITMAP 등이 모두 위처럼 설계 되었습니다.
