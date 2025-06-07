#pragma once
#include<string>
#include<vector>
#include<cstring>
#include"entity.h"

using namespace std;

//����� Wallet
class Wallet : public Entity {
private:
    double balance;
    string ownerId;

public:
    Wallet(const string& id, const string& ownerId, double balance);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance();
    const string& getOwnerId();
    const string& getId();
};

//����� Client
class Client : public Entity {
private:
    string name;
    EntityVector wallets;

public:
    Client(const string& id, const string& name);// �����������
    void addWallet(Wallet* wallet);
    double getTotalBalance();
    virtual double calculateCommission(double amount) = 0;
    virtual double getMaxTransactionLimit() = 0;
    const string& getId();
    virtual ~Client() {}//����������
};




// ������ ���������� Client
class GoldClient : public Client {
public:
    GoldClient(const string& id, const string& name) : Client(id, name) {}
    double calculateCommission(double amount);
    double getMaxTransactionLimit();
    string getBenefits();
};

class PlatinumClient : public Client {
public:
    PlatinumClient(const string& id, const string& name) : Client(id, name) {}
    double calculateCommission(double amount);
    double getMaxTransactionLimit();
    string getBenefits();
};

class StandardClient : public Client {
public:
    StandardClient(const string& id, const string& name) : Client(id, name) {}
    double calculateCommission(double amount);
    double getMaxTransactionLimit();
    string getBenefits();
};