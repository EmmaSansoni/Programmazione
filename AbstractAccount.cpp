#include "AbstractAccount.h"
#include <iostream>

void CheckingAccount::deposit(double amount) {
    if (amount > 0)
        saldo += amount;
}

void CheckingAccount::withdraw(double amount) {
    if (amount > 0 && saldo - amount >= -fido_max)
        saldo -= amount;
}

void CheckingAccount::print() {
    std::cout << "Conto corrente\n"
              << "Intestatario: " << intestatario
              << ", saldo: " << saldo
              << ", fido massimo: " << fido_max
              << '\n';
}

void SavingsAccount::deposit(double amount) {
    if (amount > 0)
        saldo += amount;
}

void SavingsAccount::withdraw(double amount) {
    if (amount > 0 && saldo - amount >= 0)
        saldo -= amount;
}

void SavingsAccount::addInterest() {
    saldo += tasso / 100.0 * saldo;
}

void SavingsAccount::print() {
    std::cout << "Conto risparmio\n"
              << "Intestatario: " << intestatario
              << ", saldo: " << saldo
              << ", tasso d'interesse: " << tasso << "%"
              << '\n';
}