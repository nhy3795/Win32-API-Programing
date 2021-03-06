#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "resource.h"

#define AMAMI_HARUKA 0
#define CHIHAYA 1
#define GOKOU_RURI 2



LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
int BITMAP_DRAW(HDC hdc,HBITMAP MyBitMap);

HINSTANCE g_hinst;
LPCTSTR lpszClass = TEXT("Win32 API");


int APIENTRY WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hwnd;
	MSG message;
	WNDCLASS WndClass;
	g_hinst = hinstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDC_ICON);
	WndClass.hInstance = hinstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hwnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 740, 440, NULL, (HMENU)NULL, hinstance, NULL);
	ShowWindow(hwnd, nCmdShow);

	while (GetMessage(&message, NULL, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return (int)message.wParam;
}

void MyTextOut(HDC hdc, int x, int y, LPCSTR str)
{
	TextOut(hdc, x, y, str, lstrlen(str));
}

void CHRITER_SAY(HDC hdc, int WHOIS, int WhatSay)
{
	switch (WHOIS)
	{
	case AMAMI_HARUKA:
		switch (WhatSay)
		{
		case 0:
			MyTextOut(hdc, 100, 100, "프로듀서씨, 디버그에요! 디-버그!");
			MyTextOut(hdc, 100, 120, "포인터가 안드로메다를 가르키고 있어요!");
			MyTextOut(hdc, 100, 140, "By - 아마미 하루카");
			break;
		case 1:
			MyTextOut(hdc, 100, 100, "저는 아마미 하루카에요! 예이!");
			MyTextOut(hdc, 100, 120, "트레이드 마크는 빨간 리본!");
			MyTextOut(hdc, 100, 140, "밝고, 긍정적이고, 원거리 통근!");
			MyTextOut(hdc, 100, 160, "하루 한번 넘어져요! 예이!");
			MyTextOut(hdc, 100, 180, "By - 아마미 하루각카");
			break;
		case 2:
			MyTextOut(hdc, 100, 100, "제가 리더가 아니면 누가 리더인가요?");
			MyTextOut(hdc, 100, 120, "설마 호시이 미키..? 설마요. 프로듀서씨.");
			MyTextOut(hdc, 100, 140, "By - 아마미 하루캌");
			break;
		default:
			break;
		}
		break;
	case CHIHAYA:
		switch (WhatSay)
		{
		case 0:
			MyTextOut(hdc, 100, 100, "프로듀서씨, 오늘도 수고하십니다.");
			MyTextOut(hdc, 100, 120, "프로그래밍이 바빠도 레슨은 빼먹지 않으실거죠?");
			MyTextOut(hdc, 100, 140, "By - 키사라기 치하야");
			break;
		case 1:
			MyTextOut(hdc, 100, 100, "프로듀서씨, 혹시 말해 둡니다만.");
			MyTextOut(hdc, 100, 120, "가슴은 그저 지방덩어리에 불구합니다.");
			MyTextOut(hdc, 100, 140, "By - 납작-쿵");
			break;
		case 2:
			MyTextOut(hdc, 100, 100, "치햐는 우유를 많이 먹죠.");
			MyTextOut(hdc, 100, 120, "..그래도 체형은 저랑 비슷하더라고요.");
			MyTextOut(hdc, 100, 140, "By - 납작-쿵");
			break;
		default:
			break;
		}
		break;
	case GOKOU_RURI:
		switch (WhatSay)
		{
		case 0:
			MyTextOut(hdc, 100, 100, "쉬면서 하지? 나처럼 영원히 쉬진 말고.");
			MyTextOut(hdc, 100, 120, "프로그래밍, 화이팅.");
			MyTextOut(hdc, 100, 140, "By - 고코우 루리");
			break;
		case 1:
			MyTextOut(hdc, 100, 100, "하아, 옛날 일 생각나네.");
			MyTextOut(hdc, 100, 120, "뭐냐고? 어.. 미안. 말을 못하겠네.");
			MyTextOut(hdc, 100, 140, "By - 고코우 루리");
			break;
		case 2:
			MyTextOut(hdc, 100, 100, "사실 나의 진짜 이름은 \"쿠로네코\"라고 한다.");
			MyTextOut(hdc, 100, 120, "..역시 지금은 못해먹겠네.");
			MyTextOut(hdc, 100, 140, "By - 고코우 루리.");
			break;
		default:
			break;
		}
		break;
	}
}

HFONT MakeFont(int Height, int fnWeight, DWORD charset, LPCTSTR fontname)
{
	return CreateFont(Height, 0, 0, 0, 0, 0, 0, 0, charset, 0, 0, 0, 0, fontname);
}

int BITMAP_DRAW(HDC hdc, HBITMAP MyBitMap)
{
	HDC Memdc;
	PAINTSTRUCT ps;
	HBITMAP OldBitMap;                                          


	Memdc = CreateCompatibleDC(hdc); //메모리 DC를 만들려면 이 함수를 불러오세엿! 동일한 DC를 복사해 매모리에 저장합니다.
	//MyBitMap = LoadBitmap(g_hinst, MAKEINTRESOURCE(IDB_BITMAP2)); //불러온다.. 비트맵.. 하지만 PAINT 할때마다 로드하면 팀장한테 불려가서 멱살잡힐것이다.
	//인스탄스 핸들/비트맵이름
	OldBitMap = (HBITMAP)SelectObject(Memdc, MyBitMap); //삭제할려면 Old가 필요해요. 셀렉!
	BitBlt(hdc, 0, 0, 720, 405, Memdc, 0, 0, SRCCOPY); //DC간의 고속 복사를 수행합니다. 메모리 DC에 있는 비트맵을 로드합니다.

	//  출력할 DC/띄울 좌표 X,Y/비트맵의 넓이/불러올 메모리 DC/복사원의 좌표, 어디부터 불러올까요?/어떻게 띄울까요?

	//BLACKNESS 검은색 한가득
	//DSTINVERT 화면 반전!
	//MERGECOPY 화면 이랑 비트맵이랑 AND연산
	//MERGEPAINT OR연산
	//SRCCOPY   그냥 복사
	//WHITENESS  하얀색 한가득.

	//StretchBlt(HDC hdcDest, int nXOriginDest, int nYOringinDest, int nWidthDest, int nHeightDest, HDC hdcSrc, int nXOringinSrc,....);
	//Bilblt와 다르게 원본파일의 크기까지 지정할수 있음. 고로 확대 축소가 가능함.

	SelectObject(Memdc,OldBitMap);
	DeleteDC(Memdc);
	return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static HBITMAP MyBitMap;
	static int TodayCharter;
	static int WhatSay;
	HFONT hFont, OldFont;
	switch (iMessage)
	{
	case WM_CREATE:
		srand((int)time(NULL));
		WhatSay = rand() % 3;
		TodayCharter = rand() % 3;
		MyBitMap = LoadBitmap(g_hinst, MAKEINTRESOURCE(IDB_BITMAP1 + TodayCharter)); //킬때마다 바뀌는 캐릭터들!
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		BITMAP_DRAW(hdc,MyBitMap);
		hFont = MakeFont(15, 10, HANGEUL_CHARSET, TEXT("나눔바른고딕")); //폰트 설정.
		//이 4개 인수빼곤 별볼일 없다.
		OldFont = (HFONT)SelectObject(hdc, hFont);
		CHRITER_SAY(hdc, TodayCharter, WhatSay); //문자열 출력을 함수로 묶어놈.
		SelectObject(hdc, OldFont);
		DeleteObject(hFont);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		DeleteObject(MyBitMap);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);


}
