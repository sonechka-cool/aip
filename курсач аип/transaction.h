#pragma once
#include<string>
#include<vector>
#include<cstring>
#include"entity.h"
#include"client.h"
enum TxType { TRANSFER };

// Класс Transaction
class Transaction : public Entity {
private:
    string senderWalletId;// ID кошелька отправителя
    string receiveWalletId;// ID кошелька получателя
    double amount;// Сумма перевода
    TxType type;//Тип транзакции
    double commission;//Комиссия за перевода
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

// Узел для списка транзакций
class TransactionNode {
public:
    Transaction* data; //Здесь хранится сама транзакция
    TransactionNode* prev;// Ссылка на предыдущий узел
    TransactionNode* next; // Ссылка на следующий узел

    TransactionNode(Transaction* data) : data(data), prev(nullptr), next(nullptr) {}
    ~TransactionNode() { delete data; }
};

// Двусвязный список транзакций
class TransactionList {
private:
    TransactionNode* head; // Первый элемент списка
    TransactionNode* tail; //// Последний элемент списка
    int size;// Количество транзакций
public:
    TransactionList() : head(nullptr), tail(nullptr), size(0) {}
    void addTransaction(Transaction* tx);
    bool removeTransaction(const string& id);
    Transaction* getTransaction(const string& id);
    void displayTransactions();
    ~TransactionList();
};

// Узел для двоичного дерева клиентов
class ClientNode {
public:
    Client* data;
    ClientNode* left;
    ClientNode* right;

    ClientNode(Client* data) : data(data), left(nullptr), right(nullptr) {}
    ~ClientNode() { delete data; }
};

// Двоичное дерево поиска клиентов
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