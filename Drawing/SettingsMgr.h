#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
	private:
		ShapeEnum curShape;
		Color curColor;
	public:
		// Constructor
		SettingsMgr(Color startingColor, ShapeEnum startingShape )
		{
			curShape = startingShape;
			curColor = startingColor;
		}

		//=========================================
		// Name: getCurColor
		// Purpose: get the shape's current color
		// Parameters: none
		// Return: color
		//=========================================
		Color getCurColor()
		{
			return curColor;
		}

		//=========================================
		// Name: getCurShape
		// Purpose: get the current shape
		// Parameters: none
		// Return: ShapeEnum
		//=========================================
		ShapeEnum getCurShape()
		{
			return curShape;
		}

		//=========================================
		// Name: setColor
		// Purpose: set the color of the shape
		// Parameters: a color
		// Return: nothing
		//=========================================
		void setColor(Color c)
		{
			curColor = c;
		}

		//=========================================
		// Name: setShape
		// Purpose: set the shape
		// Parameters: A ShapeEnum
		// Return: nothing
		//=========================================
		void setShape(ShapeEnum s)
		{
			curShape = s;
		}

		//=========================================
		// Name: writeToFile
		// Purpose: write the shape's information to a file
		// Parameters: a file
		// Return: nothing
		//=========================================
		void writeToFile(fstream& file)
		{
			unsigned int tempColor;

			tempColor = curColor.toInteger();
			file.write(reinterpret_cast<char*>(&tempColor), sizeof(tempColor));
			file.write(reinterpret_cast<char*>(&curShape), sizeof(curShape));
		}

		//=========================================
		// Name: readFromFile
		// Purpose: read information to an object from a file
		// Parameters: a file
		// Return: nothing
		//=========================================
		void readFromFile(fstream& file)
		{
			unsigned int tempColor;

			file.read(reinterpret_cast<char*>(&tempColor), sizeof(tempColor));
			file.read(reinterpret_cast<char*>(&curShape), sizeof(curShape));
			curColor = Color(tempColor);
		}
};
