#include <iostream>
#include <string>
#include <vector>

#include "AbstractAccount.h"
#include "AbstractFactory.h"
#include "Inventory.h"
#include "Product.h"

int main() {
    std::cout << "Esercizio 4: software di home banking\n";
    std::vector<AbstractAccount*> accounts;
    std::cout << "Creazione dei conti...\n"
              << "Intestatario: ";
    std::string intestatario;
    std::getline(std::cin, intestatario);
    accounts.push_back(new CheckingAccount(intestatario, 50));
    accounts.push_back(new SavingsAccount(intestatario, 3.5));
    std::cout << "Fai il tuo primo deposito sul conto corrente.\n"
              << "Quanto vuoi depositare? ";
    double amount;
    std::cin >> amount;
    accounts[0]->deposit(amount);
    std::cout << "Sposta un po' di soldi sul conto risparmio "
              << "per guadagnare il 3,5%.\n"
              << "Quanto vuoi spostare? ";
    std::cin >> amount;
    accounts[0]->withdraw(amount);
    accounts[1]->deposit(amount);
    accounts[1]->addInterest();
    std::cout << "\nSituazione dopo un anno:\n";
    accounts[0]->print();
    accounts[1]->print();

    try {
        std::cout << "\n\nEsercizio 5: Inventario di prodotti\n";
        Inventory inventory;
        // Primo prodotto
        std::cout << "\nCreazione del primo prodotto\n";
        std::cout << "Nome: ";
        std::string nome1;
        std::cin >> nome1;
        const char codice1[] = "000000";
        std::cout << "Codice a sei caratteri generato: "
                  << codice1 << '\n';
        std::cout << "Prezzo: ";
        double prezzo1;
        std::cin >> prezzo1;
        Product prodotto1(codice1, nome1, prezzo1);
        std::cout << "Quanti esemplari vuoi aggiungere? ";
        int tot1;
        std::cin >> tot1;
        for (int i = 0; i < tot1; ++i) {
            inventory.load(prodotto1);
        }
        // Secondo prodotto
        std::cout << "\nCreazione del secondo prodotto\n";
        std::cout << "Nome: ";
        std::string nome2;
        std::cin >> nome2;
        const char codice2[] = "000001";
        std::cout << "Codice a sei caratteri generato: "
                  << codice2 << '\n';
        std::cout << "Prezzo: ";
        double prezzo2;
        std::cin >> prezzo2;
        Product prodotto2(codice2, nome2, prezzo2);
        std::cout << "Quanti esemplari vuoi aggiungere? ";
        int tot2;
        std::cin >> tot2;
        for (int i = 0; i < tot2; ++i) {
            inventory.load(prodotto2);
        }
        std::cout << "\nInventario finale:\n";
        inventory.print();
        std::cout << "\nControllo prodotti con scorte basse:\n";
        inventory.lowStock();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Errore di inventario: " << e.what() << '\n';
    }

    std::cout << "\n\nEsercizio 6: Abstract Factory" << std::endl;
    AbstractFactory* factory = nullptr;
    std::cout << "Scegli il tema dell'applicazione (1 scuro o 0 chiaro): ";
    int scelta;
    std::cin >> scelta;
    if (scelta == 0) {
        factory = new ChiaroFactory();
    } else if (scelta == 1) {
        factory = new ScuroFactory();
    } else {
        std::cout << "Scelta non valida" << std::endl;
        return 1;
    }
    bool continua = true;
    while (continua) {
        std::cout << "\nMenu componenti:\n"
                  << "1. Crea un pulsante\n"
                  << "2. Crea una barra\n"
                  << "3. Crea un testo\n"
                  << "Altro. Mostra e esci\n"
                  << "Scelta: ";
        std::cin >> scelta;

        switch (scelta) {
            case 1: {
                Buttons button;
                factory->ButtonsFactory(&button);
                std::cout << "Pulsante aggiunto!\n";
                break;
            }
            case 2: {
                Bars bar;
                factory->BarsFactory(&bar);
                std::cout << "Barra aggiunta!\n";
                break;
            }
            case 3: {
                Text text;
                factory->TextFactory(&text);
                std::cout << "Testo aggiunto!\n";
                break;
            }
            default:
                continua = false; // Esci dal ciclo while
                break;
        }
    }
    std::cout << "\nInterfaccia ottenuta: \n";
    factory->renderAll();
    delete factory;
    return 0;
}