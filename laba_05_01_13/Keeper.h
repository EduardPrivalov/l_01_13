#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Figure.h"
#include "List.h"
#include "FlatFigure.h"
#include "VolumetricFigure.h"
class Keeper
{
private:
	List<Figure*> figures;

public:
	~Keeper();
	void deleteFigure(size_t position);
	void addFigure(Figure* newFigure);
	int saveToFile(std::string file);
	int loadFromFile(std::string file);
	void printAll();
};

