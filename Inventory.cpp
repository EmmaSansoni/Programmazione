// Metodi della classe Inventory dell'esercizio 5
#include "Inventory.h"

#include <iostream>
#include <stdexcept>

void Inventory::load(const Product& product) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (*it == product) {
            it->setQuantita(it->getQuantita() + 1); // Incrementa di 1
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

void Inventory::lowStock() {
    bool trovato = false;
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getQuantita() < 5) {
            std::cout << "ATTENZIONE - Scorte basse per: " << it->getNome()
                      << " (Quantita: " << it->getQuantita() << ")\n";
            trovato = true;
        }
    }
    if (!trovato) {
        std::cout << "Tutti i prodotti hanno scorte sufficienti.\n";
    }
}

void Inventory::print() {
    for (auto it = products.begin(); it != products.end(); ++it) {
        std::cout << "Nome: " << it->getNome()
                  << "\nCodice: ";
        it->printCodice();
        std::cout << "\nQuantita: " << it->getQuantita()
                  << "\nPrezzo: " << it->getPrezzo()
                  << " euro\n\n";
    }
}