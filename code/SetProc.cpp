#include "SetProc.h"
#include "Object.h"
#include <time.h>

HANDLE Proc::hTimer;
RECT Proc::rt;
int Proc::count1 = 0;
int Proc::count2 = 0;
std::vector<Shape> Proc::shape;
Player player; 
int Player::left = 0;
int Player::right = 0;

void Proc::Create()
{	
	srand((unsigned int)time(NULL));
	GetClientRect(hWnd, &rt);
	SetTimer(hWnd, 1, 300, NULL); //NULL자리 콜백함수미사용
	SetTimer(hWnd, 2, 100, NULL);
}

void Proc::Timer()
{
	InvalidateRect(hWnd, NULL, TRUE);
	int randnum;
	Shape p;

	switch (wParam)
	{

	case 1:
	{
		randnum = (rand() % 401) + 50;
		p.Set(randnum, 50, randnum + 50, 100);
		shape.push_back(p);
		randnum = shape.size();
		count1++;
		break;
	}
	case 2: 
	{
		for (int i = 0; i < shape.size(); i++)
		{
			shape[i].Fall(20);
			if (shape[i].GetTop() > 660) // 벽 아래
				shape.erase(shape.begin() + i);
			if (shape[i].collision())
			{
				;
			}
		}
		break;
	}

	}
}

void Proc::InputKeyboard(WPARAM _wParam)
{
	switch (_wParam)
	{
	case VK_LEFT:
		player.GoLeft();
		if (!player.checkPostition())
			player.GoRight();
		break;
	case VK_RIGHT:
		player.GoRight();
		if (!player.checkPostition())
			player.GoLeft();
		break;
	}
}

void Proc::Paint()
{	
	hdc = BeginPaint(hWnd, &ps);

	Rectangle(hdc, 50, 50, 500, 700); //게임판
	
	player.Paint(hdc);
	for (int i = 0; i < shape.size(); i++)
	{
		shape[i].Paint(hdc);
	}

	TextOut(hdc, rt.right / 2, rt.bottom / 2, "Center String", 13);

	EndPaint(hWnd, &ps);
}

void Proc::Destroy()
{
	shape.clear(); //데이터 삭제
	KillTimer(hWnd, 1);
	PostQuitMessage(0);
}
