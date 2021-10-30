#pragma once
#include <String>
#include "List.h"
class Figure
{
protected:
	std::string type;
	List<double> sizes;
	std::string picture; // например: "figure1.png"

public:
	virtual std::string getAllData() = 0;
};

