#include "logist.h"

//создаем объект nullPr с заданными параметрами, которые передаются в конструктор
const product nullPr("Null", 0.0, 0.0, 19.0, 41.0);

//конструктор копирования
product::product(const product& p) 

//тело конструктора
{
	_generate_id();//генерирует индефикатор для новошо объекта
	Set_descrp(p.descrp);//устанавливает описание для нового объекта
	cost = p.cost;//копируем значение цены
	nPr = p.nPr;//копируем количество
	longitude = p.longitude;//копируем долготу
	latitude = p.latitude;//копируем широту
}

//конструктор по парметрам
product::product(const char* descrp = "No info", float cost = 0.0, int nPr = 1, float longitude = 19.0, float latitude = 41.0)
//тело конструктора
{
	_generate_id();
	Set_descrp(descrp);
	this->cost = cost;
	this-> nPr = nPr;
	//проверка долготы и ширины 
	if (longitude >= 19.0 && longitude <= 169.0)
		this->longitude = longitude;
	else {
		if (longitude < 19.0)
			this->longitude = 19.0;
		else
			this->longitude = 169.0;
	}
	if (latitude >= 41.0 && latitude <= 82.0)
		this->latitude = latitude;
	else {
		if (latitude < 41.0)
			this->latitude = 41.0;
		else
			this->latitude = 82.0;
	}
}
//деконструктор
product::~product() {
}

//генерируем штрих-код
void product::_generate_id() {
	//штрих-код. Первые 3 цифры 460 для РФ
	id[0] = '4';	
	id[1] = '6';
	id[2] = '0';

	//следующие 4 цифры,которые случайно сгенерированы
	int m = rand() % 9 + 1;
	id[3] = m + '0';
	id[4] = '0';
	id[5] = '0';
	id[6] = '0';
	
	//следующие 6 цифр случайные
	for (int i = 7; i < 13; i++) {
		int k = rand() % 10;	
		id[i] = k + '0';
	}
}

//готовый штрих-код
void product::Get_id(char* newID) {
	newID = new char[13];
	for (int i = 0; i < 13; i++) {
		newID[i] = id[i];
	}
}

//описание продукта не более 50 символов
void product::Get_descrp(char* newDescription) 
{
	//newDescription = new char[50];
	for (int i = 0; i < 50; i++) {
		newDescription[i] = descrp[i];
	}
}

//функция Set_id заменяет текущее значение идентификатора на новое значение, переданное через newID. Это позволяет динамически обновлять идентификатор объекта Product.
void product::Set_id(const char* newID) {
	for (int i = 0; i < 13; i++) {
		id[i] = newID[i];
	}
}

//описание из 50 символов. Когда встречается символ окончания строки (/0) то цикл прекращается
//динамическое обновление описания объекта
void product::Set_descrp(const char* newDescription) {
	//
	for (int i = 0; i < 50; i++) {
		descrp[i] = newDescription[i];
		if (newDescription[i] == '\0')
			break;
	}
}

//выводим информацию о продукте
void product::Print() {
	//вывод id продукта
	cout << "id: ";
	for (int i = 0; i < 13; i++) {
		cout << id[i];
	}
	cout << endl;

	//вывод описания продукта
	cout << "Description: ";
	for (int i = 0; i < 50; i++) {
		cout << descrp[i];
		if (descrp[i] == '\0')
			break;
	}
	cout << endl;

	//вывод цены, количества, долготы и широты
	cout << "Cost: " << cost << endl;
	cout << "Number: " << nPr << endl;
	cout << "Longitude: " << longitude << endl;
	cout << "Latitude: " << latitude << endl;
}



//создаем индефикатор склада
//строка 4 символа. Первый-W, а остальные автоматически сгенерированы со 100
int Warehouse::lID = 100;
void Warehouse::_generate_id() {
	id[0] = 'W';//первый символ
	id[1] = (lID / 100) + '0';//сотые, а '/0' преобразует это в символ
	id[2] = ((lID % 100) / 10) + '0';//десятки
	id[3] = ((lID % 100) % 10) + '0';//еденицы
	lID++;//берем следующее значение 101
	//если превышаем 999, то сброс до 0
	if (lID > 999)
		lID = 0;
}

//конструктор по умолчанию с заданными параметрами
Warehouse::Warehouse(WPosition type = WPOSITION_WEST, float longitude = 19.0, float latitude = 41.0, int maxPr = 99) {
	//генерация индефикатора
	_generate_id();
	//установка местоположения склада
	this->type = type;
	//проверка широты и долготы
	if (longitude >= 19.0 && longitude <= 169.0)
		this->longitude = longitude;
	else {
		if (longitude < 19.0)
			this->longitude = 19.0;
		else
			this->longitude = 169.0;
	}
	if (latitude >= 41.0 && latitude <= 82.0)
		this->latitude = latitude;
	else {
		if (latitude < 41.0)
			this->latitude = 41.0;
		else
			this->latitude = 82.0;
	}
	//установка количества продуктов
	this->maxPr = maxPr;
	this->nPr = 0;
}

//конструктор копирования
Warehouse::Warehouse(const Warehouse& wh) {
	_generate_id();
	//инициализируем местоположение, долготу, широту, количество продуктов
	type = wh.type;
	longitude = wh.longitude;
	latitude = wh.latitude;
	maxPr = wh.maxPr;
}
//деконструктор
Warehouse::~Warehouse() {
}

//получение id склада
void Warehouse::Get_id(char* newid) {
	//удаление старого массива
	delete[] newid;
	//создание нового массива
	newid = new char[4];
	//копирование данных из newid в id
	for (int i = 0; i < 4; i++) {
		newid[i] = id[i];
	}
}

//вычисляем манхэттенское расстояние
float Warehouse::Manhatten_distance_to_product(product& p) {
	float result = abs(latitude - p.Get_latitude()) + abs(longitude - p.Get_longitude());
	//возвращаем результат
	return result;
}

//добавление продукта
void Warehouse::Add_product(product& p) {
	//проверка свободного места
	if (maxPr - nPr < p.Get_nPr()) {
		//если места нет, то сообщение об ошибке
		cout << "Can't add into warehouse"<< endl;
		return;
	}
	//если места достаточно, то добавляем
	products.push_back(p);
	//увеличиваем число продуктов на складе
	nPr += p.Get_nPr();
}

//создаем и добавляем продукт
void Warehouse::Create_and_add_product() {
	char descrp[50];
	float cost;
	int nPr;
	float longitude; // ЗАПАД-ВОСТОК
	float latitude; // СЕВЕР-ЮГ
	cout << "Enter description: ";
	cin >> descrp;
	cout << "Enter cost: ";
	cin >> cost;
	cout << "Enter number: ";
	cin >> nPr;
	cout << "Enter longitude: ";
	cin >> longitude;
	cout << "Enter latitude: ";
	cin >> latitude;
	//готовый продукт
	product myproduct(descrp, cost, nPr, longitude, latitude);
	//добавляем на склад
	Add_product(myproduct);
}

//удаление последнего продукта
product& Warehouse::Remove_last_product() {
	//склад пусто,нам нечего удалять
	if (products.size() == 0) {
		product out = nullPr;
		return out;
	}
	//удаляем продукт
	product output = products.back();
	products.pop_back();
	//обновление количества продуктов
	nPr -= output.Get_nPr();
}

//удаление продукта по индексу
product& Warehouse::Remove_product_at(int index) {
	//проверка на пустоту склада, если пустой, то вернет значение нулевого 
	if (products.size() == 0) {
		product output = nullPr;
		return output;
	}
	//извлекаем и удаляем продукт по указанному индексу
	product output = products.at(index);
	products.erase(products.begin() + index);
	//обновление количства
	nPr -= output.Get_nPr();
}

//вывод меню с доступными действиями 
void Warehouse::Open_menu(int& choice) {
	cout << "Menu:" << endl;
	cout << "1: Add product" << endl;
	cout << "2: Print all products" << endl;
	cout << "3: Search for product" << endl;
	cout << "4: Remove product" << endl;
	//чтение выбора пользователя через функцию choice
	cin >> choice;
}

//вывод на экран списка продуктов
void Warehouse::Print_product() {
	//пробегаемся по складу
	for (int i = 0; i < products.size(); i++) {
		cout << " " << i << ": " << endl;
		//для каждого продукта выводится индекс (i) и информауия о нём
		products.at(i).Print();
		cout << endl;
	}
}

//поиск и вывод информации о продукте по его описанию
void Warehouse::Print_product_by_descrp(const char* description) {
	//пробегаемся по всему складу
	for (int i = 0; i < products.size(); i++) {
		//создание временного динамического массива для хранения инф
		char* desi = new char[50];
		products.at(i).Get_descrp(desi);

		//проходимя по каждому элементу и сравниваем его с заданным параметром
		bool point = false;
		for (int j = 0; j < 50; j++) {
			if (desi[j] != description[j]) {
				point = true;
				break;
			}
			if (desi[j] == '\0') {
				j = 49;
				break;
			}
		}
		//освобождение памяти
		if (point) {
			delete[] desi;
			continue;
		}
		//вывод индекса и информации о продукте
		cout << i << ": " << endl;
		products.at(i).Print();
		return;
		delete[] desi;
	}
}