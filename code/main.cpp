#include <windows.h>
#include <time.h>

#include "SetProc.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LPSTR lpszClass = "Test";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	_CrtDumpMemoryLeaks(); //메모리 누수 출력
	return Message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) //원래는 콜백함수도 클래스화 하려했는데 구조가 복잡해서 잠시 연기..
{
	Proc proc;
	proc.Init(hWnd, iMsg);

	switch (iMsg) {

	case WM_CREATE:
		proc.Create();
		return 0;

	case WM_TIMER:
		proc.Timer(wParam);
		return 0;

	case WM_KEYDOWN:
		proc.InputKeyboard(wParam);
		return 0;

	case WM_PAINT:
		proc.Paint();
		return 0;

	case WM_DESTROY:
		proc.Destroy();
		return 0;

	}
	return(DefWindowProc(hWnd, iMsg, wParam, lParam));
}
