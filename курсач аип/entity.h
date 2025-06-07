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
    virtual ~Entity() {} //// Виртуальный деструктор (обязательно!)
    virtual const string& getId() = 0;//// Чисто виртуальный const-метод
};

//Класс для управления вектором сущностей
class EntityVector {
private:
    Entity** entities;
    int count;// Текущее количество элементов в массиве
    int capacity;// Емкость массива (сколько памяти выделено)
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
