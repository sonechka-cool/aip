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
        head = tail = newNode;//Если список пуст-новый узел и начало, и конец
    }
    else {
        tail->next = newNode;// Добавляем в конец списка
        newNode->prev = tail;//Прошлый конец сдвигаем
        tail = newNode;//Теперь новый узел - конец списка
    }
    size++;//Увеличиваем размер списка
}

bool TransactionList::removeTransaction(const string& id) {
    TransactionNode* current = head;//Временный узел, нужен для поиска,перебираем с начала списка
    while (current) {
        if (current->data->getId() == id) { // Нашли транзакцию для удаления
            if (current->prev) {
                current->prev->next = current->next;//Если у текущего элемента есть предыдущий, то "разрываем их связь"
                //и переставляем указатель на следующий за удалемым в списке
            }
            else {
                head = current->next;//Иначе текущий - начало списка
            }
            if (current->next) {
                current->next->prev = current->prev;//Если у текущего есть следующий, то "разрываем их связь"
                //и переставляем указатель на предыдущий перед удалемым в списке
            }
            else {
                tail = current->prev;//Иначе текущий - конец списка
            }
            delete current;//удаляем текущий объект
            size--;//уменьшаем размер списка
            return true;
        }
        current = current->next;//переходим к следующему элементу
    }
    return false;//Прошли весь список и не нашли - false
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
    if (!node) {// Если текущий узел пустой
        node = new ClientNode(client);// Создаём новый узел с клиентом
    }
    else if (client->getTotalBalance() < node->data->getTotalBalance()) {
        insertHelper(node->left, client);// Если баланас нового клиента меньше идем на на левую "ветку"
    }
    else {
        insertHelper(node->right, client);//Иначе на правую
    }
}

ClientNode* ClientBST::findMin(ClientNode* node) {
    while (node && node->left) {// Пока есть левый потомок
        node = node->left;// Идём влево
    }
    return node;// Возвращаем самый левый узел
}

ClientNode* ClientBST::removeHelper(ClientNode* node, const string& id) {
    if (!node) return nullptr;// Узел не найден

    if (node->data->getId() == id) { // Нашли узел для удаления
        if (!node->left) {//Если ветки слева нет,
            ClientNode* right = node->right;
            delete node;
            return right;//Возвращаем правую
        }
        else if (!node->right) {
            ClientNode* left = node->left;
            delete node;
            return left;
        }
        else {//Есть обе ветки
            ClientNode* minRight = findMin(node->right);// Находим минимум справа
            node->data = minRight->data;// Копируем данные
            node->right = removeHelper(node->right, minRight->data->getId()); // Удаляем дубликат
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
    if (!node) return nullptr;// Узел пустой — не нашли
    if (node->data->getId() == id) return node->data;// Нашли
    if (id < node->data->getId()) {
        return findHelper(node->left, id);//Рекурсивный вызов, идем на левую ветку
    }
    else {
        return findHelper(node->right, id);//Рекурсивный вызов, идем на правую ветку
    }
}

void ClientBST::displayInOrderHelper(ClientNode* node) const {
    if (node) {
        displayInOrderHelper(node->left);//Рекурсивный вызов, сначала выводим левую ветку
        cout << "Client: " << node->data->getId() << ", ID: " << node->data->getId()
            << ", Balance: " << node->data->getTotalBalance() << endl;//выводим заданный узел
        displayInOrderHelper(node->right);//Рекурсия, выводим правую ветку
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
