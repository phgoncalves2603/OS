//
//  BankAccount.h
//  CPPProject
//
//  Created by Pedro Henrique Gonçalves Silva Pinto on 2/26/25.
//
// BankAccount.h
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <mutex>

class BankAccount {
public:
    BankAccount(int initialBalance = 0);  // Constructor with default value

    void deposit(int amount);
    bool withdraw(int amount);

    // Mutex to ensure thread safety
    std::mutex mtx;

private:
    int balance;
};

#endif // BANK_ACCOUNT_H
