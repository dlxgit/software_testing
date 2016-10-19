#include <string>
#include <iostream>
#include <windows.h>

enum Result
{
	NOT_A_NUMBER = -1,	//некорректный ввод
	NOT_SHAPE = -2,		//неположительная длина
	NOT_TRIANGLE = -3,	//сумма двух сторон не больше чем другая сторона
	EQUILATERAL = 2,	//все стороны равны
	ISOSCELES = 1,		//две стороны равны
	SIMPLE = 0			//любой другой треугольник
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
		std::cout << "Некорректный пользовательский ввод (все параметры должны быть числами)";
	}
	else if (result == NOT_SHAPE)
	{
		std::cout << "Не фигура (Одна из сторон имеет неположительную длину)";
	}
	else if (result == NOT_TRIANGLE)
	{
		std::cout << "Не треугольник";
	}
	else if (result == SIMPLE)
	{
		std::cout << "Простой треугольник";
	}
	else if (result == ISOSCELES)
	{
		std::cout << "Равнобедренный треугольник";
	}
	else if (result == EQUILATERAL)
	{
		std::cout << "Равносторонний треугольник";
	}
}

int main(int argc, char * argv[])
{
	SetConsoleOutputCP(1251);
	if (argc != 4) 
	{
		std::cout << "Некоректный запуск программы.\nПример: triangle.exe <длина1> <длина2> <длина3>" << std::endl;
		return -4;
	}
	Result result = CheckShapeType(argv[1], argv[2], argv[3]);
	OutputResult(result);
	return result;
}