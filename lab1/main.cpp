#include <string>
#include <iostream>

enum Result
{
	NOT_A_NUMBER = -1,	//incorrect user input
	NOT_SHAPE = -2,		//any of lengths is not positive
	NOT_TRIANGLE = -3,	//sum of two sides is shorter than other one
	EQUILATERAL = 2,	//all sides are equal
	ISOSCELES = 1,		//two sides are equal
	SIMPLE = 0			//other triangle
};

Result CheckShapeType(const std::string & first, const std::string & second, const std::string & third)
{
	double a, b, c;
	try
	{
		a = std::stod(first);
		b = std::stod(second);
		c = std::stod(third);
	}
	catch (...)
	{
		return NOT_A_NUMBER;
	}

	if (a > 0 && b > 0 && c > 0)
	{
		if (a + b > c && a + c > b && b + c > a)
		{
			if (a == b && a == c)
			{
				return EQUILATERAL;
			}
			if (a == b || a == c || b == c)
			{
				return ISOSCELES;
			}
			return SIMPLE;
		}
		return NOT_TRIANGLE;
	}
	return NOT_SHAPE;
}

void OutputResult(Result result)
{
	if (result == NOT_A_NUMBER)
	{
		std::cout << "incorrect user input (all parameters must be numbers)";
	}
	else if (result == NOT_SHAPE)
	{
		std::cout << "not a shape (non-positive length detected)";
	}
	else if (result == NOT_TRIANGLE)
	{
		std::cout << "not a triangle";
	}
	else if (result == SIMPLE)
	{
		std::cout << "simple triangle";
	}
	else if (result == ISOSCELES)
	{
		std::cout << "isosceles triangle";
	}
	else if (result == EQUILATERAL)
	{
		std::cout << "equilateral triangle";
	}
}

int main(int argc, char * argv[])
{
	if (argc != 4) 
	{
		std::cout << "Incorrect program execution.\nExample: triangle.exe <length1> <length2> <length3>" << std::endl;
		return -4;
	}
	Result result = CheckShapeType(argv[1], argv[2], argv[3]);
	OutputResult(result);
	return result;
}