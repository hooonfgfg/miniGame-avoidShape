#pragma once
#include <windows.h>

class Shape
{
private:
	int left = 0, top = 0, right = 0, bottom = 0;
public:
	void Set(int _left, int _top, int _right, int _bottom);

	void Fall(int godown);

	void Paint(HDC &hdc);

	int GetLeft();
	int GetTop(); 
	int GetRight();
	int GetBottom();

	bool collision();
};


class Player
{
private:
	static int left , right ;

public:
	Player();

	void Paint(HDC &hdc);

	void GoLeft();
	
	void GoRight();
	
	bool checkPostition();
};