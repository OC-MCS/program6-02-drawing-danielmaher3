#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"


//=========================================
// Name: die
// Purpose: display an error message
// Parameters: a string
// Return: nothing
//=========================================
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}

class SettingsUI
{
	private:
		SettingsMgr *mgr;
		CircleShape red;
		CircleShape blue;
		CircleShape green;
		CircleShape circ;
		RectangleShape squ;
	public:
		// Constructor
		SettingsUI(SettingsMgr *m)
		{
			mgr = m;
			red.setOutlineColor(Color::Red);
			red.setOutlineThickness(3);
			red.setRadius(17);
			red.setPosition(49, 35);
			blue.setOutlineColor(Color::Blue);
			blue.setOutlineThickness(3);
			blue.setRadius(17);
			blue.setPosition(49, 70);
			green.setOutlineColor(Color::Green);
			green.setOutlineThickness(3);
			green.setRadius(17);
			green.setPosition(49, 105);
			circ.setOutlineColor(Color::White);
			circ.setOutlineThickness(3);
			circ.setRadius(17);
			circ.setPosition(49, 175);
			squ.setOutlineColor(Color::White);
			squ.setOutlineThickness(3);
			squ.setSize(Vector2f(34, 34));
			squ.setPosition(49, 210);
		}

		//=========================================
		// Name: handleMouseUp
		// Purpose: handles when the mouse is clicked
		// Parameters: a mouse vector
		// Returns: nothing
		//=========================================
		void handleMouseUp(Vector2f mouse)
		{
			if (red.getGlobalBounds().contains(mouse))
			{
				mgr->setColor(Color::Red);
			}
			if (blue.getGlobalBounds().contains(mouse))
			{
				mgr->setColor(Color::Blue);
			}
			if (green.getGlobalBounds().contains(mouse))
			{
				mgr->setColor(Color::Green);
			}
			if (circ.getGlobalBounds().contains(mouse))
			{
				mgr->setShape(CIRCLE);
			}
			if (squ.getGlobalBounds().contains(mouse))
			{
				mgr->setShape(SQUARE);
			}
		}

		//=========================================
		// Name: draw
		// Purpose: draw buttons, display titles
		// Parameters: a window
		// Returns: nothing
		//=========================================
		void draw(RenderWindow& win)
		{
			Font font;
			if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			{
				die("DEATH FROM THE FONT!");
			}

			Text title("Colors of Colorfullness", font, 17);
			title.setPosition(11, 11);
			win.draw(title);

			Text otherTitle("Shapely Shapes", font, 17);
			otherTitle.setPosition(11, 140);
			win.draw(otherTitle);

			red.setFillColor(Color::Transparent);
			blue.setFillColor(Color::Transparent);
			green.setFillColor(Color::Transparent);
			circ.setFillColor(Color::Transparent);
			squ.setFillColor(Color::Transparent);

			if (mgr->getCurColor() == Color::Red)
			{
				red.setFillColor(Color::Red);
			}
			if (mgr->getCurColor() == Color::Blue)
			{
				blue.setFillColor(Color::Blue);
			}
			if (mgr->getCurColor() == Color::Green)
			{
				green.setFillColor(Color::Green);
			}
			if (mgr->getCurShape() == CIRCLE)
			{
				circ.setFillColor(Color::White);
			}
			if (mgr->getCurShape() == SQUARE)
			{
				squ.setFillColor(Color::White);
			}

			win.draw(red);
			win.draw(blue);
			win.draw(green);
			win.draw(circ);
			win.draw(squ);
		}

};
