#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_

#include <iostream>
#include <vector>

#include "Figure.h"

using std::vector; 

class BlackBoard; 

class FigureManager
{
public:
	typedef vector<Figure *> Figures; 
public:
	static FigureManager &handle()
	{
		static FigureManager manager; 
		return manager; 
	}
    
    // FigureManager类析构函数
    virtual ~FigureManager(); 
 
    // FigureManager类接口.
public:
	void input(std::istream &is); 
    void display(BlackBoard &board); 

private:
	Figures _figures; 

}; // class FigureManager类定义结束.

void InitiateFigureManager(); 

#endif // #ifndef _FIGUREMANAGER_H_
