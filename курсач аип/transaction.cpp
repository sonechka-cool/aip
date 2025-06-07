#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include "transaction.h"
//class Transaction
Transaction::Transaction(string senderWalletId, string receiveWalletId, double amount, TxType type, double commission) {
    this->senderWalletId = senderWalletId;
    this->receiveWalletId = receiveWalletId;
    this->amount = amount;
    this->type = type;
    this->commission = commission;
}
const string& Transaction::getId() {
    return id;
}

string Transaction::getDetails() {
    return "Transaction " + id + ": " + to_string(amount) + " from " + senderWalletId +
        " to " + receiveWalletId + " (commission: " + to_string(commission) + ")";
}

string Transaction::getSenderWalletId() { return senderWalletId; }
string Transaction::getReceiveWalletId() { return receiveWalletId; }
double Transaction::getAmount() { return amount; }
double Transaction::getCommission() { return commission; }


//class TransactionList

void TransactionList::addTransaction(Transaction* tx) {
    TransactionNode* newNode = new TransactionNode(tx);
    if (!head) {
        head = tail = newNode;//���� ������ ����-����� ���� � ������, � �����
    }
    else {
        tail->next = newNode;// ��������� � ����� ������
        newNode->prev = tail;//������� ����� ��������
        tail = newNode;//������ ����� ���� - ����� ������
    }
    size++;//����������� ������ ������
}

bool TransactionList::removeTransaction(const string& id) {
    TransactionNode* current = head;//��������� ����, ����� ��� ������,���������� � ������ ������
    while (current) {
        if (current->data->getId() == id) { // ����� ���������� ��� ��������
            if (current->prev) {
                current->prev->next = current->next;//���� � �������� �������� ���� ����������, �� "��������� �� �����"
                //� ������������ ��������� �� ��������� �� �������� � ������
            }
            else {
                head = current->next;//����� ������� - ������ ������
            }
            if (current->next) {
                current->next->prev = current->prev;//���� � �������� ���� ���������, �� "��������� �� �����"
                //� ������������ ��������� �� ���������� ����� �������� � ������
            }
            else {
                tail = current->prev;//����� ������� - ����� ������
            }
            delete current;//������� ������� ������
            size--;//��������� ������ ������
            return true;
        }
        current = current->next;//��������� � ���������� ��������
    }
    return false;//������ ���� ������ � �� ����� - false
}

Transaction* TransactionList::getTransaction(const string& id) {
    TransactionNode* current = head;
    while (current) {
        if (current->data->getId() == id) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

void TransactionList::displayTransactions() {
    TransactionNode* current = head;
    while (current) {
        cout << current->data->getDetails() << endl;
        current = current->next;
    }
}

TransactionList::~TransactionList() {
    TransactionNode* current = head;
    while (current) {
        TransactionNode* next = current->next;
        delete current;
        current = next;
    }
}

//class ClientBST::

void ClientBST::insertHelper(ClientNode*& node, Client* client) {
    if (!node) {// ���� ������� ���� ������
        node = new ClientNode(client);// ������ ����� ���� � ��������
    }
    else if (client->getTotalBalance() < node->data->getTotalBalance()) {
        insertHelper(node->left, client);// ���� ������� ������ ������� ������ ���� �� �� ����� "�����"
    }
    else {
        insertHelper(node->right, client);//����� �� ������
    }
}

ClientNode* ClientBST::findMin(ClientNode* node) {
    while (node && node->left) {// ���� ���� ����� �������
        node = node->left;// ��� �����
    }
    return node;// ���������� ����� ����� ����
}

ClientNode* ClientBST::removeHelper(ClientNode* node, const string& id) {
    if (!node) return nullptr;// ���� �� ������

    if (node->data->getId() == id) { // ����� ���� ��� ��������
        if (!node->left) {//���� ����� ����� ���,
            ClientNode* right = node->right;
            delete node;
            return right;//���������� ������
        }
        else if (!node->right) {
            ClientNode* left = node->left;
            delete node;
            return left;
        }
        else {//���� ��� �����
            ClientNode* minRight = findMin(node->right);// ������� ������� ������
            node->data = minRight->data;// �������� ������
            node->right = removeHelper(node->right, minRight->data->getId()); // ������� ��������
        }
    }
    else if (id < node->data->getId()) {
        node->left = removeHelper(node->left, id);
    }
    else {
        node->right = removeHelper(node->right, id);
    }
    return node;
}

Client* ClientBST::findHelper(ClientNode* node, const string& id) const {
    if (!node) return nullptr;// ���� ������ � �� �����
    if (node->data->getId() == id) return node->data;// �����
    if (id < node->data->getId()) {
        return findHelper(node->left, id);//����������� �����, ���� �� ����� �����
    }
    else {
        return findHelper(node->right, id);//����������� �����, ���� �� ������ �����
    }
}

void ClientBST::displayInOrderHelper(ClientNode* node) const {
    if (node) {
        displayInOrderHelper(node->left);//����������� �����, ������� ������� ����� �����
        cout << "Client: " << node->data->getId() << ", ID: " << node->data->getId()
            << ", Balance: " << node->data->getTotalBalance() << endl;//������� �������� ����
        displayInOrderHelper(node->right);//��������, ������� ������ �����
    }
}

void ClientBST::clearHelper(ClientNode* node) {
    if (node) {
        clearHelper(node->left);
        clearHelper(node->right);
        delete node;
    }
}


void ClientBST::insert(Client* client) {
    insertHelper(root, client);
}

bool ClientBST::remove(const string& id) {
    if (!find(id)) return false;
    root = removeHelper(root, id);
    return true;
}

Client* ClientBST::find(const string& id) const {
    return findHelper(root, id);
}

void ClientBST::displayInOrder() const {
    displayInOrderHelper(root);
}

ClientBST::~ClientBST() {
    clearHelper(root);
}
