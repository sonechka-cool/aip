#include "logist.h"

//������� ������ nullPr � ��������� �����������, ������� ���������� � �����������
const product nullPr("Null", 0.0, 0.0, 19.0, 41.0);

//����������� �����������
product::product(const product& p) 

//���� ������������
{
	_generate_id();//���������� ����������� ��� ������ �������
	Set_descrp(p.descrp);//������������� �������� ��� ������ �������
	cost = p.cost;//�������� �������� ����
	nPr = p.nPr;//�������� ����������
	longitude = p.longitude;//�������� �������
	latitude = p.latitude;//�������� ������
}

//����������� �� ���������
product::product(const char* descrp = "No info", float cost = 0.0, int nPr = 1, float longitude = 19.0, float latitude = 41.0)
//���� ������������
{
	_generate_id();
	Set_descrp(descrp);
	this->cost = cost;
	this-> nPr = nPr;
	//�������� ������� � ������ 
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
//�������������
product::~product() {
}

//���������� �����-���
void product::_generate_id() {
	//�����-���. ������ 3 ����� 460 ��� ��
	id[0] = '4';	
	id[1] = '6';
	id[2] = '0';

	//��������� 4 �����,������� �������� �������������
	int m = rand() % 9 + 1;
	id[3] = m + '0';
	id[4] = '0';
	id[5] = '0';
	id[6] = '0';
	
	//��������� 6 ���� ���������
	for (int i = 7; i < 13; i++) {
		int k = rand() % 10;	
		id[i] = k + '0';
	}
}

//������� �����-���
void product::Get_id(char* newID) {
	newID = new char[13];
	for (int i = 0; i < 13; i++) {
		newID[i] = id[i];
	}
}

//�������� �������� �� ����� 50 ��������
void product::Get_descrp(char* newDescription) 
{
	//newDescription = new char[50];
	for (int i = 0; i < 50; i++) {
		newDescription[i] = descrp[i];
	}
}

//������� Set_id �������� ������� �������� �������������� �� ����� ��������, ���������� ����� newID. ��� ��������� ����������� ��������� ������������� ������� Product.
void product::Set_id(const char* newID) {
	for (int i = 0; i < 13; i++) {
		id[i] = newID[i];
	}
}

//�������� �� 50 ��������. ����� ����������� ������ ��������� ������ (/0) �� ���� ������������
//������������ ���������� �������� �������
void product::Set_descrp(const char* newDescription) {
	//
	for (int i = 0; i < 50; i++) {
		descrp[i] = newDescription[i];
		if (newDescription[i] == '\0')
			break;
	}
}

//������� ���������� � ��������
void product::Print() {
	//����� id ��������
	cout << "id: ";
	for (int i = 0; i < 13; i++) {
		cout << id[i];
	}
	cout << endl;

	//����� �������� ��������
	cout << "Description: ";
	for (int i = 0; i < 50; i++) {
		cout << descrp[i];
		if (descrp[i] == '\0')
			break;
	}
	cout << endl;

	//����� ����, ����������, ������� � ������
	cout << "Cost: " << cost << endl;
	cout << "Number: " << nPr << endl;
	cout << "Longitude: " << longitude << endl;
	cout << "Latitude: " << latitude << endl;
}



//������� ����������� ������
//������ 4 �������. ������-W, � ��������� ������������� ������������� �� 100
int Warehouse::lID = 100;
void Warehouse::_generate_id() {
	id[0] = 'W';//������ ������
	id[1] = (lID / 100) + '0';//�����, � '/0' ����������� ��� � ������
	id[2] = ((lID % 100) / 10) + '0';//�������
	id[3] = ((lID % 100) % 10) + '0';//�������
	lID++;//����� ��������� �������� 101
	//���� ��������� 999, �� ����� �� 0
	if (lID > 999)
		lID = 0;
}

//����������� �� ��������� � ��������� �����������
Warehouse::Warehouse(WPosition type = WPOSITION_WEST, float longitude = 19.0, float latitude = 41.0, int maxPr = 99) {
	//��������� ������������
	_generate_id();
	//��������� �������������� ������
	this->type = type;
	//�������� ������ � �������
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
	//��������� ���������� ���������
	this->maxPr = maxPr;
	this->nPr = 0;
}

//����������� �����������
Warehouse::Warehouse(const Warehouse& wh) {
	_generate_id();
	//�������������� ��������������, �������, ������, ���������� ���������
	type = wh.type;
	longitude = wh.longitude;
	latitude = wh.latitude;
	maxPr = wh.maxPr;
}
//�������������
Warehouse::~Warehouse() {
}

//��������� id ������
void Warehouse::Get_id(char* newid) {
	//�������� ������� �������
	delete[] newid;
	//�������� ������ �������
	newid = new char[4];
	//����������� ������ �� newid � id
	for (int i = 0; i < 4; i++) {
		newid[i] = id[i];
	}
}

//��������� ������������� ����������
float Warehouse::Manhatten_distance_to_product(product& p) {
	float result = abs(latitude - p.Get_latitude()) + abs(longitude - p.Get_longitude());
	//���������� ���������
	return result;
}

//���������� ��������
void Warehouse::Add_product(product& p) {
	//�������� ���������� �����
	if (maxPr - nPr < p.Get_nPr()) {
		//���� ����� ���, �� ��������� �� ������
		cout << "Can't add into warehouse"<< endl;
		return;
	}
	//���� ����� ����������, �� ���������
	products.push_back(p);
	//����������� ����� ��������� �� ������
	nPr += p.Get_nPr();
}

//������� � ��������� �������
void Warehouse::Create_and_add_product() {
	char descrp[50];
	float cost;
	int nPr;
	float longitude; // �����-������
	float latitude; // �����-��
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
	//������� �������
	product myproduct(descrp, cost, nPr, longitude, latitude);
	//��������� �� �����
	Add_product(myproduct);
}

//�������� ���������� ��������
product& Warehouse::Remove_last_product() {
	//����� �����,��� ������ �������
	if (products.size() == 0) {
		product out = nullPr;
		return out;
	}
	//������� �������
	product output = products.back();
	products.pop_back();
	//���������� ���������� ���������
	nPr -= output.Get_nPr();
}

//�������� �������� �� �������
product& Warehouse::Remove_product_at(int index) {
	//�������� �� ������� ������, ���� ������, �� ������ �������� �������� 
	if (products.size() == 0) {
		product output = nullPr;
		return output;
	}
	//��������� � ������� ������� �� ���������� �������
	product output = products.at(index);
	products.erase(products.begin() + index);
	//���������� ���������
	nPr -= output.Get_nPr();
}

//����� ���� � ���������� ���������� 
void Warehouse::Open_menu(int& choice) {
	cout << "Menu:" << endl;
	cout << "1: Add product" << endl;
	cout << "2: Print all products" << endl;
	cout << "3: Search for product" << endl;
	cout << "4: Remove product" << endl;
	//������ ������ ������������ ����� ������� choice
	cin >> choice;
}

//����� �� ����� ������ ���������
void Warehouse::Print_product() {
	//����������� �� ������
	for (int i = 0; i < products.size(); i++) {
		cout << " " << i << ": " << endl;
		//��� ������� �������� ��������� ������ (i) � ���������� � ��
		products.at(i).Print();
		cout << endl;
	}
}

//����� � ����� ���������� � �������� �� ��� ��������
void Warehouse::Print_product_by_descrp(const char* description) {
	//����������� �� ����� ������
	for (int i = 0; i < products.size(); i++) {
		//�������� ���������� ������������� ������� ��� �������� ���
		char* desi = new char[50];
		products.at(i).Get_descrp(desi);

		//��������� �� ������� �������� � ���������� ��� � �������� ����������
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
		//������������ ������
		if (point) {
			delete[] desi;
			continue;
		}
		//����� ������� � ���������� � ��������
		cout << i << ": " << endl;
		products.at(i).Print();
		return;
		delete[] desi;
	}
}