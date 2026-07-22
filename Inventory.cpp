// Metodi della classe Inventory dell'esercizio 5
#include "Inventory.h"

#include <iostream>
#include <stdexcept>

void Inventory::load(const Product& product) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (*it == product) {
            it->setQuantita(1);
            return;
        }
    }
    products.push_back(product);
}

void Inventory::unload(const Product& product) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (*it == product) {
            if (it->getQuantita() == 1) {
                products.erase(it);
            } else {
                it->setQuantita(-1);
            }
            return;
        }
    }
    throw std::runtime_error("Prodotto non presente nell'inventario");
}

void Inventory::lowStock() const {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getQuantita() < 5) {
            throw std::runtime_error("Prodotto non presente nell'inventario");
        }
    }
}

void Inventory::print() const {
    for (auto it = products.begin(); it != products.end(); ++it) {
        std::cout << "Nome: " << it->getNome()
                  << "\nCodice: ";
        it->printCodice();
        std::cout << "\nQuantita: " << it->getQuantita()
                  << "\nPrezzo: " << it->getPrezzo()
                  << " euro\n\n";
    }
}