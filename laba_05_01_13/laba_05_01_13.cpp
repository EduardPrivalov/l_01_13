#include <iostream>
#include <fstream>
#include <String>
#include "Keeper.h"
#include "Figure.h"
#include "FlatFigure.h"
#include "VolumetricFigure.h"
#include "List.h"

int main()
{
	std::cout << "Hello World!\n";
}


/*


Разработать класс Keeper, который реализует контейнер для хранения и 			[Keeper.h]
обработки объектов. Класс Keeper должен обеспечивать следующие функции: 
	▪ добавление и удаление производных объектов абстрактного класса Base		[deleteFigure(size_t)] [addFigure()]
	▪ полное сохранение себя в файле;											[saveToFile(string)]
	▪ полное восстановление себя из файла.										[loadFromFile(string)]

Класс Фигур содержит данные о плоских и объемных фигур. 						[Figure.h]
Для плоской:  тип, размеры, площадь, рисунок на экране.							[FlatFigure.h]
Для объемной: тип, размеры, объем,   рисунок на экране в виде плоской фигуры.	[VolumetricFigure.h]

*/