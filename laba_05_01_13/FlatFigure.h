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
	FlatFigure(std::string type, std::string picture, List<double> sizes, double area);
	~FlatFigure();
	std::string getAllData() override;
	std::string getAllDataForPrint() override;
};

