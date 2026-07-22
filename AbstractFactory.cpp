// Esercizio 6: metodi dell'AbstractFactory
#include "AbstractFactory.h"

#include <iostream>

void ChiaroFactory::ButtonsFactory(Buttons* b) {
    b->setType("chiaro");
    buttons.push_back(*b);
}

void ChiaroFactory::BarsFactory(Bars* b) {
    b->setType("chiaro");
    bars.push_back(*b);
}

void ChiaroFactory::TextFactory(Text* t) {
    t->setType("chiaro");
    texts.push_back(*t);
}

void ChiaroFactory::renderAll() {
    for (auto i = buttons.begin(); i != buttons.end(); ++i) {
        i->render();
    }
    for (auto i = bars.begin(); i != bars.end(); ++i) {
        i->render();
    }
    for (auto i = texts.begin(); i != texts.end(); ++i) {
        i->render();
    }
}

void ScuroFactory::ButtonsFactory(Buttons* b) {
    b->setType("scuro");
    buttons.push_back(*b);
}

void ScuroFactory::BarsFactory(Bars* b) {
    b->setType("scuro");
    bars.push_back(*b);
}

void ScuroFactory::TextFactory(Text* t) {
    t->setType("scuro");
    texts.push_back(*t);
}

void ScuroFactory::renderAll() {
    for (auto i = buttons.begin(); i != buttons.end(); ++i) {
        i->render();
    }
    for (auto i = bars.begin(); i != bars.end(); ++i) {
        i->render();
    }
    for (auto i = texts.begin(); i != texts.end(); ++i) {
        i->render();
    }
}