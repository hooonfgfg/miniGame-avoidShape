#pragma once
#include <windows.h>
#include <vector>
#include "Object.h"

class Proc
{
private:
	HWND hWnd;
	UINT iMsg;
	WPARAM wParam;
	LPARAM lParam;
	static RECT rt;

	HDC hdc;
	PAINTSTRUCT ps;
	static HANDLE hTimer;
	
	static int count1;
	static int count2;

	static std::vector<Shape> shape;
public:
	void Init(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam){
		this->hWnd = hWnd;
		this->iMsg = iMsg;
		this->wParam = wParam;
		this->lParam = lParam;
	}

	void Create();

	void Timer();

	void Paint();

	void Destroy();

	void InputKeyboard(WPARAM _wParam);
};
