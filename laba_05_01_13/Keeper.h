#pragma once
#include "Figure.h"
#include <String>
#include "List.h"
class Keeper
{
private:
	List<Figure*> figures;

public:
	void deleteFigure(size_t position);
	void addFigure(Figure* newFigure);
	int saveToFile(std::string file);
	int loadFromFile(std::string file);
	void printAll();
};

