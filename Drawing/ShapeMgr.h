#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

class ShapeMgr
{
private:
	vector<DrawingShape*> list;
public:
	ShapeMgr()
	{
		// I am useless
		// Nothing to initialize
	}

	//=========================================
	// Name: addShape
	// Purpose: add a shape to the list
	// Parameters: position, the shape, the color
	// Return: nothing
	//=========================================
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			list.push_back(new Circle(color, pos));
		}
		else
		{
			list.push_back(new Rectangle(color, pos));
		}
	}

	//=========================================
	// Name: writeToFile
	// Purpose: write the list of shapes to a file
	// Parameters: a file
	// Return: nothing
	//=========================================
	void writeToFile(fstream& file)
	{
		myShape temp;

		for (int i = 0; i < list.size(); i++)
		{
			temp = list[i]->getFileRecord();
			file.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
	}

	//=========================================
	// Name: readFromFile
	// Purpose: read the file into a list
	// Parameters: a file
	// Return: nothing
	//=========================================
	void readFromFile(fstream& file)
	{
		myShape temp;

		while(file.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			addShape(Vector2f(temp.posX, temp.posY), temp.shape, Color(temp.color));
		}
	}

	//=========================================
	// Name: getList
	// Purpose: return a list of shapes
	// Parameters: none
	// Return: a pointer to a DrawingShaoe object
	//=========================================
	const vector<DrawingShape*>& getList()
	{
		return list;
	}
};
