// Esercizio 5: Classe Inventory

#ifndef PROGRAMMAZIONE_INVENTORY_H
#define PROGRAMMAZIONE_INVENTORY_H

#include <vector>
#include "Product.h"

class Inventory {
private:
    std::vector<Product> products;

public:
    void load(const Product& product);
    void unload(const Product& product);
    void lowStock();
    void print();
};

#endif