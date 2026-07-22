// Esercizio 6: struttura Application

#ifndef PROGRAMMAZIONE_ABSTRACTSUBJECT_H
#define PROGRAMMAZIONE_ABSTRACTSUBJECT_H
#include <iostream>

class Application {
public:
    virtual ~Application() = default;
    virtual std::string getType() = 0;
    virtual void setType(std::string t) = 0;
    virtual void render() = 0;
protected:
    std::string type;
};

class Buttons : public Application {
public:
    Buttons() {type = "";}
    virtual ~Buttons() override = default;
    virtual std::string getType() override{ return type; }
    virtual void setType(std::string t) override {type = t;}
    virtual void render() override {
        std::cout << "Button " << type << std::endl;
    }
};

class Bars : public Application {
public:
    Bars() {type = "";}
    virtual ~Bars() override = default;
    virtual std::string getType() override{ return type; }
    virtual void setType(std::string t) override {type = t;}
    virtual void render() override {
        std::cout << "Bar " << type << std::endl;
    }
};

class Text : public Application {
public:
    Text() {type = "";}
    virtual ~Text() override = default;
    virtual std::string getType() override{ return type; }
    virtual void setType(std::string t) override {type = t;}
    virtual void render() override {
        std::cout << "Text " << type << std::endl;
    }
};

#endif //PROGRAMMAZIONE_ABSTRACTSUBJECT_H