#include "Object.h"

/* ��ֹ� Ŭ���� */

void Shape::Set(int _left, int _top, int _right, int _bottom)
{
	this->left = _left;
	this->top = _top;
	this->right = _right;
	this->bottom = _bottom;
}

void Shape::Fall(int godown)
{
	this->top += godown;
	this->bottom += godown;
}

void Shape::Paint(HDC & hdc)
{
	Rectangle(hdc, left, top, right, bottom);
}

int Shape::GetLeft()
{
	return left;
}

int Shape::GetTop()
{
	return top;
}

int Shape::GetRight()
{
	return right;
}

int Shape::GetBottom()
{
	return bottom;
}

bool Shape::collision()
{
	Player p;
	
	return true;
}

/* Player Ŭ���� */


Player::Player()
{
	left = 250, right = 300;
}

void Player::Paint(HDC & hdc)
{
	Rectangle(hdc, left, 650, right, 700);
}

void Player::GoLeft()
{
	left -= 20;
	right -= 20;
}

void Player::GoRight()
{
	left += 20;
	right += 20;
}

bool Player::checkPostition()
{
	if (left >= 50 && right <= 500)
		return true;
	else
		return false;
}

