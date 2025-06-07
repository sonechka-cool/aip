#pragma once
#include<string>
#include<vector>
#include<cstring>
#include"entity.h"
#include"client.h"
enum TxType { TRANSFER };

// ����� Transaction
class Transaction : public Entity {
private:
    string senderWalletId;// ID �������� �����������
    string receiveWalletId;// ID �������� ����������
    double amount;// ����� ��������
    TxType type;//��� ����������
    double commission;//�������� �� ��������
public:
    Transaction() {};
    Transaction(string senderWalletId, string receiveWalletId, double amount, TxType type, double commission);
    const string& getId();
    string getDetails();
    string getSenderWalletId();
    string getReceiveWalletId();
    double getAmount();
    double getCommission();
};

// ���� ��� ������ ����������
class TransactionNode {
public:
    Transaction* data; //����� �������� ���� ����������
    TransactionNode* prev;// ������ �� ���������� ����
    TransactionNode* next; // ������ �� ��������� ����

    TransactionNode(Transaction* data) : data(data), prev(nullptr), next(nullptr) {}
    ~TransactionNode() { delete data; }
};

// ���������� ������ ����������
class TransactionList {
private:
    TransactionNode* head; // ������ ������� ������
    TransactionNode* tail; //// ��������� ������� ������
    int size;// ���������� ����������
public:
    TransactionList() : head(nullptr), tail(nullptr), size(0) {}
    void addTransaction(Transaction* tx);
    bool removeTransaction(const string& id);
    Transaction* getTransaction(const string& id);
    void displayTransactions();
    ~TransactionList();
};

// ���� ��� ��������� ������ ��������
class ClientNode {
public:
    Client* data;
    ClientNode* left;
    ClientNode* right;

    ClientNode(Client* data) : data(data), left(nullptr), right(nullptr) {}
    ~ClientNode() { delete data; }
};

// �������� ������ ������ ��������
class ClientBST {
private:
    ClientNode* root;

    void insertHelper(ClientNode*& node, Client* client);
    ClientNode* findMin(ClientNode* node);
    ClientNode* removeHelper(ClientNode* node, const string& id);
    Client* findHelper(ClientNode* node, const string& id) const;
    void displayInOrderHelper(ClientNode* node) const;
    void clearHelper(ClientNode* node);
public:
    ClientBST() : root(nullptr) {}

    void insert(Client* client);
    bool remove(const string& id);
    Client* find(const string& id) const;
    void displayInOrder() const;
    ~ClientBST();
};