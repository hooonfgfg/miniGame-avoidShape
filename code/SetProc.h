#pragma once

// 메모리 누수 점검
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

#include <windows.h>
#include <vector>
#include "Object.h"

class Proc
{
private:
	HWND hWnd;
	UINT iMsg;

private:
	HDC hdc;
	PAINTSTRUCT ps;
	static RECT rt;
	static HANDLE hTimer;
	static std::vector<Shape> shape;

public:
	void Init(HWND hWnd, UINT iMsg){
		this->hWnd = hWnd;
		this->iMsg = iMsg;
	}

	void Create();

	void Timer(WPARAM _wParam);

	void Paint();

	void Destroy();

	void InputKeyboard(WPARAM _wParam);
};
