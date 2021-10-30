#pragma once
#include <string>
#include "Figure.h"
#include "List.h"
class FlatFigure :
	public Figure
{
private:
	double area;
public:
	FlatFigure(std::string type, std::string picture, List<double> sizes, double area) :
		Figure(type, picture, sizes), area(area) {};
	std::string getAllData() override;
};

