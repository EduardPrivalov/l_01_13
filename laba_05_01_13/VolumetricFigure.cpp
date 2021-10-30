#include "VolumetricFigure.h"

VolumetricFigure::VolumetricFigure(std::string type, std::string picture, List<double> sizes, double volume) :
	Figure(type, picture, sizes), volume(volume) {
	std::cout << "VolumetricFigure(std::string type, std::string picture, List<double> sizes, double volume)\n";
}

VolumetricFigure::~VolumetricFigure() { std::cout << "~VolumetricFigure()\n"; }

std::string VolumetricFigure::getAllData()
{
	std::string str = "VolumetricFigure\n" + type + "\n" + picture + "\n";
	str += std::to_string(sizes.size()) + "\n" + std::to_string(sizes[0]);
	for (size_t i = 1; i < sizes.size(); i++)
		str += " " + std::to_string(sizes[i]);
	str += "\n" + std::to_string(volume) + "\n";
	return str;
}

std::string VolumetricFigure::getAllDataForPrint()
{
	std::string str = "VolumetricFigure:\n\ttype: " + type + "\n\tpicture: " + picture + "\n\tsizes: ";
	str += std::to_string(sizes[0]);
	for (size_t i = 1; i < sizes.size(); i++)
		str += " - " + std::to_string(sizes[i]);
	str += "\n\tvolume: " + std::to_string(volume) + "\n";
	return str;
}
