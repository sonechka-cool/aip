#pragma once
#include<string>
#include<vector>
#include<cstring>
#include "client.h"
#include "transaction.h"


class Blockchain {
private:
    ClientBST clients;
    TransactionList transactions;
public:
    void addClient(Client* client);
    bool processTransaction(Transaction* tx);
    void displayClients();
    void displayTransactions();
};