#include <iostream>
#include "logist.h"
using namespace std;
int main()
{
	srand(time(NULL));//инициализируем генератор случайных чисел

	//создание объекта Warehouseс с заданными параметрами
	Warehouse wh1(WPOSITION_EAST, 127.4, 45.6, 60);

	//цикл,который повторяется,пока пользователь делает выбор
	int choice = 0;
	do {
		wh1.Open_menu(choice);
		switch (choice) {
		case 1://создание и добавление продукта
			wh1.Create_and_add_product();
			break;
		case 2://вывод всех продуктов
			wh1.Print_product();
			break;
		case 3://запрос описания и вывод продуктов с этим описанием
			char may[50];
			cout << "Enter description:" << endl;
			cin >> may;
			wh1.Print_product_by_descrp(may);
			break;
		case 4://запрос индекса и удаление продукта с этим индексом
			int gav;
			cout << "Enter index:" << endl;
			cin >> gav;
			wh1.Remove_product_at(gav);
			break;
		default:
			return 0;
		}
	} while (choice > 0);

	return 0;
}
