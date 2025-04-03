#pragma once
#include <iostream>
#include <ctime>//стандартная библиотека C++ для работы со значениями даты и времени
#include <random>//стандартная библиотека C++, для генерации случайных чисел.
#include <vector>
using namespace std;

class product {
private:
	char id[13];
	char descrp[50];
	float cost;
	int nPr;
	float longitude; // ЗАПАД-ВОСТОК
	float latitude; // СЕВЕР-ЮГ

	void _generate_id();

public:
	product(const char* descrp, float cost, int nPr, float longitude, float latitude);//конструктор по параметрам
	product(const product& p);//конструктор по копированию
	~product();

	//геттерс возвращают указанные параметры
	void Get_id(char* newID);
	void Get_descrp(char* newDescription);
	float Get_cost() { return cost; };
	int Get_nPr() { return nPr; };
	float Get_longitude() { return longitude; };
	float Get_latitude() { return latitude; };

	//сеттерс устанавливают указанные параметры
	void Set_id(const char* newDescription);
	void Set_descrp(const char* newDescription);
	void Set_cost(float cost) { this->cost = cost; };
	void Set_nPr(int nPr) { this->nPr = nPr; };
	void Set_longitude(float longitude) { this->longitude = longitude; };
	void Set_latitude(float latitude) { this->latitude = latitude; };

	void Print();
};


//ОПРЕДЕЛЕНИЕ ВОЗМОЖНЫХ КАТЕГОРИЙ СКЛАДОВ(ЗАПАД, ЦЕТР, ВОСТОК)
enum WPosition {
	WPOSITION_WEST,
	WPOSITION_CEN,
	WPOSITION_EAST
};

class Warehouse {
private:
	static int lID;
	
	char id[4];
	WPosition type;
	float longitude; // ВОСТОК-ЗАПАД
	float latitude; // СЕВЕР-ЮГ
	int maxPr;//максимальное количесвто продуктов,которое может хранить скалд
	int nPr;//текущее количество продуктов
	vector<product> products;

	void _generate_id();


public:
	Warehouse(WPosition type, float longitude, float latitude, int maxPr);
	Warehouse(const Warehouse& wh);
	~Warehouse();

	//геттерс
	void Get_id(char* newid);
	WPosition Get_type() { return type; };
	float Get_longitude() { return longitude; };
	float Get_latitude() { return latitude; };
	int Get_maxPr() { return maxPr; };
	int Get_nPr() { return nPr; };

	//сеттерс
	void Set_id(const char* newid);
	void Set_type(WPosition type) { this->type = type; };
	void Set_position(float longitude, float latitude) { this->longitude = longitude; this->latitude = latitude; };
	void Set_MaxNProducts(int maxPr) { this->maxPr = maxPr; };

	//вычислить манхэттенское расстояние до зданного продукта р
	float Manhatten_distance_to_product(product& p);
	void Add_product(product& p);
	void Create_and_add_product();
	product& Remove_last_product();//удаление послденего продукта
	product& Remove_product_at(int index);//удвление продукта по индексу

	void Print_id() { cout << id << endl; };
	void Open_menu(int& choice);//Открывает меню. Пользователь взаимодействовует с программой.
	void Print_product();//выводит инф о всех продуктах
	void Print_product_by_descrp(const char* description);//выводит инфо о продукте по заданному описанию
};




