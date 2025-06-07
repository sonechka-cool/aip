#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include "entity.h"

using namespace std;
Entity::Entity(const string& id) {
    this->id = id;
}
Entity::Entity(const Entity& e) {
    this->id = e.id;
};

EntityVector::EntityVector(int initialCapacity) {
    this->entities = new Entity * [initialCapacity];
    this->count = 0;
    this->capacity = initialCapacity;

};

EntityVector::EntityVector(const EntityVector& ev){
    this->count = ev.count;
    this->capacity = ev.capacity;
    this->entities = new Entity * [this->capacity];
    for (int i = 0; i < this->count; i++) {
        this->entities[i] = ev.entities[i];
    }
};

void EntityVector:: resizeArray() {
    int newCapacity = (capacity == 0) ? 2 : capacity * 2;// ��������� ����� ������� (������ ����������� � 2 ����)
    Entity** newArray = new Entity * [newCapacity];// ������� ����� ������ �������� �������

    for (int i = 0; i < count; i++) {
        newArray[i] = entities[i];
    }
    delete[] entities;

    // ����������� ����� ��������
    entities = newArray;
    capacity = newCapacity;
}
EntityVector::~EntityVector() {
    delete[] entities;// ������� ������ ���������� (�� �� ���� ������� Entity!)
}
void EntityVector::addEntity(Entity* entity) {
    if (entity == nullptr) return;

    if (count >= capacity) {  // ���� ������ ��������, ����������� ��� ������
        resizeArray();
    }
    entities[count] = entity;//��������� ����� �������
    count++;
}
bool EntityVector::removeEntity(const string& id) {
    // ���� �������� � �������� ID
    for (int i = 0; i < count; i++) {
        string currentId = entities[i]->getId();// ���������� ID
        bool found = true;

        for (int j = 0; ; j++) {
            if (id[j] != currentId[j]) {
                found = false;
                break;
            }
            if (id[j] == '\0') break;  // �������� ����� ������
        }

        if (found) {
            // �������� ��� ����������� �������� �� 1 ������� �����
            for (int j = i; j < count - 1; j++) {
                entities[j] = entities[j + 1];
            }

            count--;  // ��������� ������� ���������
            return true;
        }
    }
    return false;
}

//����� �������� �� id
Entity* EntityVector::getEntity(const string& id) {
    // �������� ����� �� �������
    for (int i = 0; i < count; i++) {
        if (entities[i]->getId() == id) {
            return entities[i];
        }
    }
    return nullptr;
}

//
Entity** EntityVector::getAllEntities(int* outCount) {
    *outCount = count;  // ���������� ���������� ���������
    return entities;    // ���������� ��� ������
}
