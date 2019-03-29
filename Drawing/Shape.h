#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// Struct for a writable shape
struct myShape
{
	int color;
	float posX;
	float posY;
	ShapeEnum shape;
};

// Class DrawingShape
class DrawingShape 
{
	public:
		virtual void drawShape(RenderWindow& win) = 0;
		virtual myShape getFileRecord() = 0;
};

// Circle Class
class Circle : public DrawingShape
{
	private:
		CircleShape circle;
	public:
		// Constructor
		Circle(Color c, Vector2f pos)	
		{
			circle.setFillColor(c);
			circle.setPosition(pos);
			circle.setRadius(7);
		}
		// Inherited Functions
		//=========================================
		// Name: drawShape
		// Purpose: draw a circle
		// Parameters: a window variable
		// Return: nothing
		//=========================================
		void drawShape(RenderWindow& win)
		{
			win.draw(circle);
		}

		//=========================================
		// Name: getFileRecord
		// Purpose: get the shapes from the file
		// Parameters: None
		// Return: a circle
		//=========================================
		myShape getFileRecord()
		{
			myShape myCircle;
			myCircle.color = circle.getFillColor().toInteger();
			myCircle.posX = circle.getPosition().x;
			myCircle.posY = circle.getPosition().y;
			myCircle.shape = CIRCLE;
			return myCircle;
		}
};

// Rectangle Class
class Rectangle : public DrawingShape
{
private:
	RectangleShape rec;
public:
	// Constructor
	Rectangle(Color c, Vector2f pos)
	{
		rec.setFillColor(c);
		rec.setPosition(pos);
		rec.setSize(Vector2f(14, 14));
	}
	// Inherited Functions
	//=========================================
	// Name: drawShape
	// Purpose: Draw a rectangle
	// Parameters: a window
	// Return: nothing
	//=========================================
	void drawShape(RenderWindow& win)
	{
		win.draw(rec);
	}

	//=========================================
	// Name: myShape 
	// Purpose: Design a rectagnle/square
	// Parameters: None
	// Return: a square
	//=========================================
	myShape getFileRecord()
	{
		myShape myRec;
		myRec.color = rec.getFillColor().toInteger();
		myRec.posX = rec.getPosition().x;
		myRec.posY = rec.getPosition().y;
		myRec.shape = SQUARE;
		return myRec;
	}
};


