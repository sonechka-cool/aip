#pragma once
#include<string>
#include<vector>
#include<cstring>
using namespace std;
class Entity {
protected:
    string id;
public:
    Entity() {};
    Entity(const string& id);
    Entity(const Entity& e);
    virtual ~Entity() {} //// ����������� ���������� (�����������!)
    virtual const string& getId() = 0;//// ����� ����������� const-�����
};

//����� ��� ���������� �������� ���������
class EntityVector {
private:
    Entity** entities;
    int count;// ������� ���������� ��������� � �������
    int capacity;// ������� ������� (������� ������ ��������)
    void resizeArray();

public:
    EntityVector() {};
    EntityVector(int initialCapacity);
    EntityVector(const EntityVector& ev);
    ~EntityVector();
    void addEntity(Entity* entity);
    bool removeEntity(const string& id);
    Entity* getEntity(const string& id);
    Entity** getAllEntities(int* outCount);
};
