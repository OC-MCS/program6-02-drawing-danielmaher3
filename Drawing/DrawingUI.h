#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"


class DrawingUI
{
	private:
		RectangleShape canvas;
	public:
		// Constructor
		DrawingUI(Vector2f p)
		{
			canvas.setPosition(p);
			canvas.setSize(Vector2f(600, 550));
			canvas.setOutlineColor(Color::Cyan);
			canvas.setOutlineThickness(7);
		}

		//=========================================
		// Name: draw
		// Purpose: load the previous drawing
		// Parameters: window, and a pointer to a list
		// Returns: nothing
		//=========================================
		void draw(RenderWindow& win, ShapeMgr *mgr)
		{
			win.draw(canvas);

			vector<DrawingShape*> list = mgr->getList();
			for (int t = 0; t < list.size(); t++)
			{
				list[t]->drawShape(win);
			}
		}
		
		//=========================================
		// Name: isMouseOnCanvas
		// Purpose: check if the mouse is on the canvas or not
		// Parameters: the mouse position
		// Returns: a boolean
		//=========================================
		bool isMouseInCanvas(Vector2f mousePos)
		{
			return canvas.getGlobalBounds().contains(mousePos);
		}

};

