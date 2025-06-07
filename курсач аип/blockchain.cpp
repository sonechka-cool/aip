#include<string>
#include<vector>
#include<cstring>
#include "client.h"
#include "transaction.h"
#include "blockchain.h"

using namespace std;

 bool Blockchain::processTransaction(Transaction* tx) {
    Wallet* sender = dynamic_cast<Wallet*>(clients.find(tx->getSenderWalletId()));
    Wallet* receiver = dynamic_cast<Wallet*>(clients.find(tx->getReceiveWalletId()));

    if (!sender || !receiver) return false;

    Client* senderClient = dynamic_cast<Client*>(clients.find(sender->getOwnerId()));
    if (!senderClient) return false;

    double commission = senderClient->calculateCommission(tx->getAmount());
    double totalAmount = tx->getAmount() + commission;

    if (sender->getBalance() < totalAmount) return false;
    if (tx->getAmount() > senderClient->getMaxTransactionLimit()) return false;

    sender->withdraw(totalAmount);
    receiver->deposit(tx->getAmount());

    transactions.addTransaction(tx);
    return true;
}

 void Blockchain::addClient(Client* client) {
     clients.insert(client);
 }

 void Blockchain::displayClients() {
     clients.displayInOrder();
 }

 void Blockchain::displayTransactions() {
     transactions.displayTransactions();
 }
