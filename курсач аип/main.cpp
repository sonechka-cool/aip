#include <iostream>
#include <cstdio>
#include "blockchain.h"
using namespace std;
int main() {
    // 1. Создаем блокчейн
    Blockchain blockchain;

    // 2. Создаем клиентов разных типов
    Client* goldClient = new GoldClient("gc1", "John Gold");
    Client* platinumClient = new PlatinumClient("pc1", "Alice Platinum");
    Client* standardClient = new StandardClient("sc1", "Bob Standard");

    // 3. Добавляем клиентов в блокчейн
    blockchain.addClient(goldClient);
    blockchain.addClient(platinumClient);
    blockchain.addClient(standardClient);

    // 4. Создаем кошельки для клиентов
    Wallet wallet1("w1", "gc1", 5000.0);  // Кошелек goldClient
    Wallet wallet2("w2", "pc1", 3000.0);  // Кошелек platinumClient
    Wallet wallet3("w3", "sc1", 1000.0);  // Кошелек standardClient

    // 5. Добавляем кошельки клиентам
    goldClient->addWallet(&wallet1);
    platinumClient->addWallet(&wallet2);
    standardClient->addWallet(&wallet3);

    // 6. Создаем транзакции
    Transaction t1("t1", "w1", 1000.0, TRANSFER, 0);
    Transaction t2("t2", "w2",  500.0, TRANSFER, 0);
    Transaction t3("t3", "w1", 2000.0, TRANSFER, 0);

    // 7. Обрабатываем транзакции
    cout << "Processing transaction t1: ";
    if (blockchain.processTransaction(&t1)) {
        cout << "Success" << endl;
    }
    else {
        cout << "Failed" << endl;
    }

    cout << "Processing transaction t2: ";
    if (blockchain.processTransaction(&t2)) {
        cout << "Success" << endl;
    }
    else {
        cout << "Failed" << endl;
    }

    cout << "Processing transaction t3: ";
    if (blockchain.processTransaction(&t3)) {
        cout << "Success" << endl;
    }
    else {
        cout << "Failed" << endl;
    }

    // 8. Выводим информацию о клиентах
    cout << "\nClients information:" << endl;
    blockchain.displayClients();

    // 9. Выводим информацию о транзакциях
    cout << "\nTransactions history:" << endl;
    blockchain.displayTransactions();

    // 10. Проверяем балансы после транзакций
    cout << "\nFinal balances:" << endl;
    cout << "Gold client total balance: " << goldClient->getTotalBalance() << endl;
    cout << "Platinum client total balance: " << platinumClient->getTotalBalance() << endl;
    cout << "Standard client total balance: " << standardClient->getTotalBalance() << endl;

    return 0;
}