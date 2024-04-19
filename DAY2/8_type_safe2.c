
typedef int HICON;
typedef int HBITMAP;


HICON CreateIcon()
{
	return 10;
}

void DrawBitmap(HBITMAP id) {}

int main()
{
	HICON icon_id = CreateIcon();

	// int 대신, HICON, HBITMAP 을 사용하므로 "코드 가독성"은 좋아 졌습니다.
	// 그런데, 아래 코드가 컴파일 에러일까요 ?
	DrawBitmap(icon_id);  // HICON, HBITMAP 은 다른 타입이 아니라 같은 타입입니다.
						  // 그래서 에러는 아닙니다.
						  // 역시 "타입 안전성 부족!!"
}