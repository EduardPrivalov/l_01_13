#include <iostream>
#include <fstream>
#include <String>
#include <Windows.h>
#include "Keeper.h"
#include "Figure.h"
#include "FlatFigure.h"
#include "VolumetricFigure.h"
#include "List.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Keeper kipper;
	int c;

	while (true)
	{
		cout << "\nМеню"
			<< "\n1.Восстановление из файла"
			<< "\n2.Добавить фигуру"
			<< "\n3.Вывод данных на экран"
			<< "\n4.Удалить фигуру"
			<< "\n5.Сохранение в файл"
			<< "\n0.Выход без сохранения\n->";
		cin >> c;

		switch (c)
		{
		case 1: {
			if (kipper.loadFromFile("save.txt"))
				cout << "\tДанные успешно загружены\n";
			else
				cout << "\tФайл не найден или повреждён\n";
			break; }
		case 2: {
			std::string type, picture;
			size_t sizesAmount, mainType;
			List<double> sizes;
			double bufferNum;
			cout << "\tВыбирите фигуру:\n"
				<< "\n\t1.Плоская"
				<< "\n\t2.Объемная\n\t->";
			cin >> mainType;
			switch (mainType)
			{
			case 1: {
				cout << "\tВведите тип: ";
				getline(cin, type);
				getline(cin, type);
				cout << "\tВведите файл рисунка: ";
				getline(cin, picture);
				cout << "\tВведите кол-во размеров: ";
				cin >> sizesAmount;
				for (size_t i = 0; i < sizesAmount; i++)
				{
					cout << "\tВведите размер №" << i <<" : ";
					cin >> bufferNum;
					sizes.push_back(bufferNum);
				}
				cout << "\tВведите площадь: ";
				cin >> bufferNum;
				kipper.addFigure(new FlatFigure(type, picture, sizes, bufferNum));
				cout << "\tФигура №" << kipper.size() << " успешно добавлена\n";
				break; }
			case 2: {
				cout << "\tВведите тип: ";
				getline(cin, type);
				getline(cin, type);
				cout << "\tВведите файл рисунка: ";
				getline(cin, picture);
				cout << "\tВведите кол-во размеров: ";
				cin >> sizesAmount;
				for (size_t i = 0; i < sizesAmount; i++)
				{
					cout << "\tВведите размер №" << i << " : ";
					cin >> bufferNum;
					sizes.push_back(bufferNum);
				}
				cout << "\tВведите объем: ";
				cin >> bufferNum;
				kipper.addFigure(new VolumetricFigure(type, picture, sizes, bufferNum));
				cout << "\tФигура №" << kipper.size() << " успешно добавлена\n";
				break; }
			default: cout << "\tВыбрано недопустимое значение!\n";
			}
			break; }
		case 3: {
			kipper.printAll();
			break; }
		case 4: {
			if (kipper.size() == 0)
				cout << "\tФигуры отсутствуют.\n";
			else
			{
				size_t position;
				cout << "\tВыбирите фигуру. Доступны: №"
					<< (kipper.size() == 1 ? "" : "1 - №")
					<< (kipper.size() == 1 ? 1 : kipper.size())
					<< "\n\t->";
				cin >> position;
				try
				{
					kipper.deleteFigure(position-1);
					cout << "\tДанные успешно удалены\n";
				}
				catch(int)
				{
					cout << "\tВыбрано недопустимое значение!\n";
				}
			}
			break; }
		case 5: {
			if (kipper.saveToFile("save.txt"))
				cout << "\tДанные успешно сохранены\n";
			else
				cout << "\tПри сохранении произошла ошибка\n";
			break; }
		case 0: {
			cout << "\t\t  Все несохраненные данные будут утеряны!"
				<< "\n\t\t  Продолжить?(1-Да / 0-Нет)\n\t\t->";
			cin >> c;
			if (c == 1) return 0; }
		}
	}
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