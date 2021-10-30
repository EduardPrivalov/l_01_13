#include "Keeper.h"

Keeper::Keeper()
{
	std::cout << "Keeper()\n";
}

Keeper::~Keeper()
{
	std::cout << "~Keeper()\n";
	if (figures.size())
		for (size_t i = 0; i < figures.size(); i++)
			delete figures[i];
}

void Keeper::deleteFigure(size_t position)
{
	delete figures.pop(position);
}

void Keeper::addFigure(Figure* newFigure)
{
	figures.push_back(newFigure);
}

size_t Keeper::size()
{
	return figures.size();
}

int Keeper::saveToFile(std::string file)
{
	std::ofstream fout(file);
	if (!fout) return 0;
	fout << to_string(figures.size()) << std::endl;
	for (size_t i = 0; i < figures.size(); ++i)
		fout << figures[i]->getAllData();

	fout.close();
	return 1;
}

int Keeper::loadFromFile(std::string file)
{
	std::ifstream fin(file);
	if (!fin) return 0;

	std::string mainType, type, picture;
	size_t figuresAmount, sizesAmount;
	double bufferSize, bufferNum;

	fin >> figuresAmount;
	for (size_t i = 0; i < figuresAmount; i++)
	{
		List<double> sizes;
		fin >> mainType;
		getline(fin, type);
		getline(fin, type);
		getline(fin, picture);
		fin >> sizesAmount;
		for (size_t j = 0; j < sizesAmount; j++)
		{
			fin >> bufferSize;
			sizes.push_back(bufferSize);
		}
		fin >> bufferNum;
		if (mainType == "FlatFigure")
			figures.push_back(new FlatFigure(type, picture, sizes, bufferNum));
		else if (mainType == "VolumetricFigure")
			figures.push_back(new VolumetricFigure(type, picture, sizes, bufferNum));
	}
	return 1;
}

void Keeper::printAll()
{
	for (size_t i = 0; i < figures.size(); i++)
		std::cout << "Фигура №" << i + 1 << ":\n" << figures[i]->getAllDataForPrint() << "\n";
}
