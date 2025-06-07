#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include "entity.h"
#include"client.h"

using namespace std;

//��� ������ WAllet
Wallet::Wallet(const string& id, const string& ownerId, double balance) : Entity(id) {
    this->balance = balance;
    this->ownerId = ownerId;
}
void Wallet::deposit(double amount) {
    if (amount > 0) balance += amount;
}

bool Wallet::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

double Wallet::getBalance() {
    return balance;
}

const string& Wallet::getOwnerId() {
    return ownerId;
}

const string& Wallet::getId() {
    return id;
}

//��� ������ CLient
Client::Client(const string& id, const string& name):Entity(id) {
    this->name = name;
};
void Client::addWallet(Wallet* wallet) { // ����� ���������� ��������
    if (wallet != nullptr) {
        wallets.addEntity(wallet);
    }
}

double Client::getTotalBalance() { //
    double total = 0.0;
    int count; //���������� ��� ���������� ���������
    Entity** allWallets = wallets.getAllEntities(&count);

    for (int i = 0; i < count; i++) {
        Wallet* wallet = dynamic_cast<Wallet*>(allWallets[i]);
        if (wallet != nullptr) {
            total += wallet->getBalance();//���������� �������
        }
    }
    return total;
}

const string& Client::getId() {
    return id;
}

//��� ����������� Client
//Gold
double GoldClient::calculateCommission(double amount) {
    return amount * 0.01; // 1%
}

double GoldClient::getMaxTransactionLimit() {
    return 10000;
}

string GoldClient::getBenefits() {
    return "������������ ���������, ������ ��������";
}

//Platinum
double PlatinumClient::calculateCommission(double amount) {
    return amount * 0.02; // 2%
}

double PlatinumClient::getMaxTransactionLimit() {
    return 5000;
}

string PlatinumClient::getBenefits() {
    return "�������� ��������������, ��������� ��������";
}

//Standard
double StandardClient::calculateCommission(double amount) {
    return amount * 0.05; // 5%
}

double StandardClient::getMaxTransactionLimit() {
    return 1000;
}

string StandardClient::getBenefits() {
    return "����������� ������";
}
