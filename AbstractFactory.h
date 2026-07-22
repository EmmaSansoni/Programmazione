// Esercizio 6: Struttura dell'AbstractFactory
#ifndef PROGRAMMAZIONE_ABSTRACTFACTORY_H
#define PROGRAMMAZIONE_ABSTRACTFACTORY_H

#include "Application.h"

#include <vector>

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;

    virtual void ButtonsFactory(Buttons* b) = 0;
    virtual void BarsFactory(Bars* b) = 0;
    virtual void TextFactory(Text* t) = 0;

    virtual void renderAll() = 0;
};

class ChiaroFactory : public AbstractFactory {
private:
    std::vector<Buttons> buttons;
    std::vector<Bars> bars;
    std::vector<Text> texts;

public:
    ChiaroFactory(){}
    ~ChiaroFactory() override = default;

    void ButtonsFactory(Buttons* b) override;
    void BarsFactory(Bars* b) override;
    void TextFactory(Text* t) override;

    void renderAll() override;
};

class ScuroFactory : public AbstractFactory {
private:
    std::vector<Buttons> buttons;
    std::vector<Bars> bars;
    std::vector<Text> texts;

public:
    ScuroFactory() = default;
    ~ScuroFactory() override = default;

    void ButtonsFactory(Buttons* b) override;
    void BarsFactory(Bars* b) override;
    void TextFactory(Text* t) override;

    void renderAll() override;
};

#endif