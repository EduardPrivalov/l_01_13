#include "FlatFigure.h"

FlatFigure::FlatFigure(std::string type, std::string picture, List<double> sizes, double area) :
	Figure(type, picture, sizes), area(area) {
	std::cout << "FlatFigure(std::string type, std::string picture, List<double> sizes, double area)\n";
}

FlatFigure::~FlatFigure()
{
	std::cout << "~FlatFigure()\n";
}

std::string FlatFigure::getAllData()
{
	std::string str = "FlatFigure\n" + type + "\n" + picture + "\n";
	str += std::to_string(sizes.size()) + "\n" + std::to_string(sizes[0]);
	for (size_t i = 1; i < sizes.size(); i++)
		str += " " + std::to_string(sizes[i]);
	str += "\n" + std::to_string(area) + "\n";
	return str;
}

std::string FlatFigure::getAllDataForPrint()
{
	std::string str = "FlatFigure:\n\ttype: " + type + "\n\tpicture: " + picture + "\n\tsizes: ";
	str += std::to_string(sizes[0]);
	for (size_t i = 1; i < sizes.size(); i++)
		str += " - " + std::to_string(sizes[i]);
	str += "\n\tarea: " + std::to_string(area) + "\n";
	return str;
}
