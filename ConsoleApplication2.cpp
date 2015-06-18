// ConsoleApplication2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>

typedef enum LineComponent {
	elcShapeType,
	elcShapeName,
	elcXCoordinate,
	elcYCoordinate,

	elcNumLineComponents
};

class Vector2
{
	Vector2(float _x=0,float _y=0);
public:
	float x, y;
	~Vector2();
};
class Shape
{
	std::string name;
	Vector2 location;
};

class Circle
{
	float radius;
};

class Square
{
	float radius;
};
int _tmain(int argc, _TCHAR* argv[])
{
	


	std::ostringstream outputStream;
	//outputStream << "Circle" << "," << "AwesomeCircle" << "," << 1.3f << "," << -2.5f;
	//std::string builtCSVLine = outputStream.str();

	std::string shape;
	std::string name;
	float width;
	float height;

	std::cout << "Enter Circle/Square" << std::endl;
	std::cin >> shape;

	std::cout << "Enter Name" << std::endl;
	std::cin >> name;
	std::cout << "Enter Width/Radius (cm)" << std::endl;
	std::cin >> width;

	std::cout << "Enter Height/null (cm)" << std::endl;
	std::cin >> height;

	std::cout << "  " << std::endl;
	outputStream << shape << "," << name <<","<< width << "," << height;
	std::string builtCSVLine = outputStream.str();
	//ShapeType,ShapeName, X,Y
	std::string csvLine = "Circle,AwesomeCircle,1.3,-2.5";
	//setup an input stream and give it csvLine as initial data
	std::istringstream inputStream(builtCSVLine);

	LineComponent currentComponent = elcShapeType;

	std::string lineElement;

	//std::cout << name << std::endl;
	//std::cout << radius << std::endl;

	
	
	float widthOut;
	float heightOut;

	while (std::getline(inputStream, lineElement, ','))
	{
		std::cout << lineElement << std::endl;

		if ((currentComponent == elcXCoordinate) || (currentComponent == elcYCoordinate))
		{
			//atof is ascii to float, also atoi for int
			float lineElementAsFloat = std::atof(lineElement.c_str());
		}
		// this here is called a c styled cast this can be unsafe if used wrong.
		currentComponent = (LineComponent)(currentComponent + 1);
	}

	return 0;
}

