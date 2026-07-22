// Esercizio 4: struttura delle classi utilizzate

#ifndef PROGRAMMAZIONE_ESERCIZIO4_H
#define PROGRAMMAZIONE_ESERCIZIO4_H
#include <string>

// Classe Astratta
class AbstractAccount {
public:
    virtual ~AbstractAccount() = default;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void print() = 0;

    virtual void addInterest();

protected:
    std::string intestatario;
    double saldo;
};

class CheckingAccount : public AbstractAccount {
public:
    CheckingAccount(std::string i, int f)
        : intestatario(i), saldo(0), fido_max(f){}
    virtual ~CheckingAccount() = default;
    virtual void deposit(double amount) override;
    virtual void withdraw(double amount) override;
    virtual void print() override;
    virtual void addInterest() override;
private:
    std::string intestatario;
    double saldo;
    double fido_max;
};

class SavingsAccount : public AbstractAccount {
public:
    SavingsAccount(std::string i, double t)
        : intestatario(i), saldo(0), tasso(t){}
    virtual ~SavingsAccount() = default;
    virtual void deposit(double amount) override;
    virtual void withdraw(double amount) override;
    virtual void print() override;
    virtual void addInterest() override;
    double getTasso() {
        return tasso;
    }
private:
    std::string intestatario;
    double saldo;
    double tasso;
};
#endif //PROGRAMMAZIONE_ESERCIZIO4_H