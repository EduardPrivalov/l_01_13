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
	VolumetricFigure(std::string type, std::string picture, List<double> sizes, double volume) :
		Figure(type, picture, sizes), volume(volume) {};
	std::string getAllData() override;
};

