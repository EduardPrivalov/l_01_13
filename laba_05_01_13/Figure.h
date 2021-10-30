#pragma once
#include <string>
#include "List.h"
class Figure
{
protected:
	std::string type, picture; // например: "figure1.png"
	List<double> sizes;

public:
	Figure(std::string type, std::string picture, List<double> sizes) :
		type(type), picture(picture), sizes(sizes) {}
	virtual std::string getAllData() = 0;
};

