#pragma once
#include <string>
#include "Figure.h"
#include "List.h"
class VolumetricFigure :
    public Figure
{
private:
    double volume;
public:
	VolumetricFigure(std::string type, std::string picture, List<double> sizes, double volume);
	~VolumetricFigure();
	std::string getAllData() override;
	std::string getAllDataForPrint() override;
};

