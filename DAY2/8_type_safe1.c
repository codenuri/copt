// 113 page. 코드 안정성을 위한 기술.
// 
// 아이콘, 커서, 비트맵 등을 ID를 부여해서 관리하려고 합니다.


// 아이콘을 생성해서 아이콘의 번호를 반환
int CreateIcon() 
{
	 return 10; 
} 

// 비트맵의 ID 를 받아서 그림을 그리는 함수. 
void DrawBitmap(int id) {}

int main()
{
	int icon_id = CreateIcon();

	DrawBitmap(icon_id); // 실수로 비트맵 번호가 아닌 아이콘 번호 전달 ??
						 // 컴파일 에러 날까요 ??
						// ID 를 모두 int 로 관리하므로 에러가 아닙니다.
						// 이런 것을 "타입 안정성이 부족하다" 라고 표현합니다.
}