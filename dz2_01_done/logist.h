#pragma once
#include <iostream>
#include <ctime>//����������� ���������� C++ ��� ������ �� ���������� ���� � �������
#include <random>//����������� ���������� C++, ��� ��������� ��������� �����.
#include <vector>
using namespace std;

class product {
private:
	char id[13];
	char descrp[50];
	float cost;
	int nPr;
	float longitude; // �����-������
	float latitude; // �����-��

	void _generate_id();

public:
	product(const char* descrp, float cost, int nPr, float longitude, float latitude);//����������� �� ����������
	product(const product& p);//����������� �� �����������
	~product();

	//������� ���������� ��������� ���������
	void Get_id(char* newID);
	void Get_descrp(char* newDescription);
	float Get_cost() { return cost; };
	int Get_nPr() { return nPr; };
	float Get_longitude() { return longitude; };
	float Get_latitude() { return latitude; };

	//������� ������������� ��������� ���������
	void Set_id(const char* newDescription);
	void Set_descrp(const char* newDescription);
	void Set_cost(float cost) { this->cost = cost; };
	void Set_nPr(int nPr) { this->nPr = nPr; };
	void Set_longitude(float longitude) { this->longitude = longitude; };
	void Set_latitude(float latitude) { this->latitude = latitude; };

	void Print();
};


//����������� ��������� ��������� �������(�����, ����, ������)
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
	float longitude; // ������-�����
	float latitude; // �����-��
	int maxPr;//������������ ���������� ���������,������� ����� ������� �����
	int nPr;//������� ���������� ���������
	vector<product> products;

	void _generate_id();


public:
	Warehouse(WPosition type, float longitude, float latitude, int maxPr);
	Warehouse(const Warehouse& wh);
	~Warehouse();

	//�������
	void Get_id(char* newid);
	WPosition Get_type() { return type; };
	float Get_longitude() { return longitude; };
	float Get_latitude() { return latitude; };
	int Get_maxPr() { return maxPr; };
	int Get_nPr() { return nPr; };

	//�������
	void Set_id(const char* newid);
	void Set_type(WPosition type) { this->type = type; };
	void Set_position(float longitude, float latitude) { this->longitude = longitude; this->latitude = latitude; };
	void Set_MaxNProducts(int maxPr) { this->maxPr = maxPr; };

	//��������� ������������� ���������� �� �������� �������� �
	float Manhatten_distance_to_product(product& p);
	void Add_product(product& p);
	void Create_and_add_product();
	product& Remove_last_product();//�������� ���������� ��������
	product& Remove_product_at(int index);//�������� �������� �� �������

	void Print_id() { cout << id << endl; };
	void Open_menu(int& choice);//��������� ����. ������������ ����������������� � ����������.
	void Print_product();//������� ��� � ���� ���������
	void Print_product_by_descrp(const char* description);//������� ���� � �������� �� ��������� ��������
};




