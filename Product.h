// Esercizio 5: Struttura di Product

#ifndef PROGRAMMAZIONE_PRODUCT_H
#define PROGRAMMAZIONE_PRODUCT_H

#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>

class Product {
private:
    char codice[6];
    std::string nome;
    int quantita;
    double prezzo;

public:
    Product(const char* c, const std::string& n, double p)
        : nome(n), quantita(1), prezzo(p) {

        if (c == nullptr)
            throw std::invalid_argument("Codice non valido");

        if (std::strlen(c) > 5)
            throw std::invalid_argument(
                "Il codice può contenere al massimo 5 caratteri"
            );

        std::strcpy(codice, c);
    }

    ~Product() = default; // Non serve delete: codice è un array statico.

    bool operator==(const Product& other) const {
        return nome == other.nome;
    }

    void setQuantita(int variazione) {
        quantita += variazione;
    }

    int getQuantita() const {
        return quantita;
    }

    double getPrezzo() const {
        return prezzo;
    }

    const std::string& getNome() const {
        return nome;
    }

    void printCodice() const {
        std::cout << codice;
    }
};

#endif