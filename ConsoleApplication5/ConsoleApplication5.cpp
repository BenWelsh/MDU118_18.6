
// ConsoleApplication2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

typedef enum LineComponent {
	elcShapeType,
	elcShapeName,
	elcXCoordinate,
	elcYCoordinate,

	elcNumLineComponents
};

typedef std::string string;

struct Vector2
{
	Vector2(float _x=0, float _y=0)
	{
		x = _x;
		y = _y;
	}

	float x, y;
	~Vector2();
};
class ShapeInfo
{
	ShapeInfo(string _name ="null",string _shape="null",float _height =0,float _width =0,Vector2 _location=(0,0) )
	{
		name = _name;
		shape = _shape;
		height = _height;
		width = _width;
		location = _location;
	}
public:
	string name;
	string shape;
	float height;
	float width;
	Vector2 location;

	~ShapeInfo();
};

typedef std::vector<ShapeInfo> ShapeInfos;

std::ostream& operator << (std::ostream& os, const ShapeInfo& shapeInfo)
{
	return os << shapeInfo.name << ","
		<< shapeInfo.shape << ","
		<< shapeInfo.height << ","
		<< shapeInfo.width << ","
		<< shapeInfo.location;
}



int _tmain(int argc, _TCHAR* argv[])
{



	std::ostringstream outputStream;
	//outputStream << "Circle" << "," << "AwesomeCircle" << "," << 1.3f << "," << -2.5f;
	//std::string builtCSVLine = outputStream.str();


	std::string nameInput;
	std::string shapeInput;
	float heightInput;
	float widthInput;
	Vector2 locationInput;


	std::cout << "Enter Name" << std::endl;
	std::cin >> nameInput;

	std::cout << "Enter Circle/Square" << std::endl;
	std::cin >> shapeInput;

	std::cout << "Enter Height/null (cm)" << std::endl;
	std::cin >> heightInput;

	std::cout << "Enter Width/Radius (cm)" << std::endl;
	std::cin >> widthInput;

	std::cout << "Enter Width/Radius (cm)" << std::endl;
	std::cin >> locationInput;

	std::cout << "  " << std::endl;
	outputStream <<  nameInput << "," << shapeInput << "," << heightInput << "," << widthInput <<"," << locationInput;
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

	std::ofstream meshCSV("mesh.csv");
	std::ofstream meshBinary("mesh.bin", std::ios::binary);

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


//	meshCSV << builtCSVLine << std::endl;
	return 0;
}

