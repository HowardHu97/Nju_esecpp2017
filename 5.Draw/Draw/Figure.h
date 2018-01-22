#ifndef __FIGURE__
#define __FIGURE__

#include <iostream>

#include "BlackBoard.h"

class Figure
{
public:
	Figure(int id) : _type(id) { }

	int type() { return _type; }

	virtual ~Figure() { }

	void input(std::istream &is); 
	void display(BlackBoard &board); 

protected:
private:
	int _type; 
};

class Circle : public Figure
{
public:
	Circle() : Figure(1) { }

	void input(std::istream &is)
	{
		std::cout << "Center X: "; 
		is >> _x; 

		std::cout << "Center Y: "; 
		is >> _y; 

		std::cout << "Radius: "; 
		is >> _radius;  
	}
	void display(BlackBoard &board)
	{
		board.DrawCircle(_x, _y, _radius); 
	}

	int _x; 
	int _y; 
	int _radius;  
}; 

class Line : public Figure
{
public:
	Line() : Figure(2) { }

	void input(std::istream &is)
	{
		std::cout << "X1: "; 
		is >> _x1; 
		std::cout << "Y1: "; 
		is >> _y1; 

		std::cout << "X2: "; 
		is >> _x2; 
		std::cout << "Y2: "; 
		is >> _y2; 
	}

	void display(BlackBoard &board)
	{
		board.DrawLine(_x1, _y1, _x2, _y2); 
	}

	int _x1; 
	int _y1; 
	int _x2; 
	int _y2; 
};

class Rectangle : public Figure
{
public:
	Rectangle() : Figure(3) { }

	void input(std::istream &is)
	{
		std::cout << "Left: "; 
		is >> _left; 
		std::cout << "Top: "; 
		is >> _top; 

		std::cout << "Right: "; 
		is >> _right; 
		std::cout << "Bottom: "; 
		is >> _bottom; 
	}

	void display(BlackBoard &board)
	{
		board.DrawLine(_left, _top, _right, _top); 
		board.DrawLine(_left, _bottom, _right, _bottom); 
		board.DrawLine(_left, _top, _left, _bottom); 
		board.DrawLine(_right, _top, _right, _bottom); 
	}
	
	int _left; 
	int _top; 
	int _right; 
	int _bottom; 
};



#endif // #ifndef __FIGURE__

