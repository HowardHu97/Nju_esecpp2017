#include "stdafx.h" 

#include "FigureManager.h"
#include "BlackBoard.h"

using std::cout; 
using std::endl;

void FigureManager::input(std::istream &is)
{
	while (1)
	{
		int type; 

		cout << "input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)" << endl;
		is >> type; 

		switch (type)
		{	
		case 0:
			return; 
			break; 
		case 1: // Բ
			{
				Circle *pcircle = new Circle; 
				pcircle->input(is); 

				_figures.push_back(pcircle); 
			}
			break;
		case 2: // ��
			{
				Line *line = new Line; 
				line->input(is); 

				_figures.push_back(line); 
			}
			break;
		case 3: // ����
			{
				Rectangle *rectangle = new Rectangle; 
				rectangle->input(is); 
				_figures.push_back(rectangle);
			}
			break;
		}
	}
}

void FigureManager::display(BlackBoard &board)
{
	// ������input�������ͼ�����������λ���
	for (Figures::iterator iter = _figures.begin(); iter != _figures.end(); ++iter)
	{
		Figure *figure = *iter;
		switch (figure->type())
		{
		case 1:
			{
				Circle *circle = (Circle *)(figure);
				circle->display(board); 
			}
			break; 
		case 2: 
			{
				Line *line = (Line *)(figure);
				line->display(board); 
			}
			break; 
		case 3: 
			{
				Rectangle *rectangle = (Rectangle *)(figure);
				rectangle->display(board); 
			}
			break; 

		}
	}

}

FigureManager::~FigureManager()
{
	for (Figures::iterator iter = _figures.begin(); iter != _figures.end(); ++iter)
	{
		delete *iter;
	}
}



// ������ʵ����ҪһЩ��Ҫ�ĳ�ʼ�����ɷ�����������У�main���������
// ���û�У������
void InitiateFigureManager()
{

}


