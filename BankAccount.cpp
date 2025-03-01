//
// Created by pedro on 2/28/25.
//

//
//  BankAccount.cpp
//  CPPProject
//
//  Created by Pedro Henrique Gonçalves Silva Pinto on 2/26/25.
//

// BankAccount.cpp
#include "BankAccount.h"

BankAccount::BankAccount(int initialBalance) : balance(initialBalance) {}

void BankAccount::deposit(int amount) {
    balance += amount;
    std::cout << "Deposit: " << amount << "\nCurrent balance: " << balance << std::endl;
}

bool BankAccount::withdraw(int amount) {
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Withdraw: " << amount << "\nCurrent balance: " << balance << std::endl;
        return true;
    }
    std::cout << "Insufficient funds" << std::endl;
    return false;
}

