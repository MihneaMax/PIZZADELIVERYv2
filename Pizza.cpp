#include "Pizza.h"
#include <iostream>
Pizza::Pizza(const std::string& nume, double pret, const std::string& tip, const std::vector<std::string>& ingrediente)
    : Produs(nume, pret), tip(tip), ingrediente(ingrediente) {}

std::string Pizza::getTip() const {
    return tip;
}

std::vector<std::string> Pizza::getIngrediente() const {
    return ingrediente;
}

double Pizza::getPret() const {
    return pret;
}

std::shared_ptr<Produs> Pizza::clone() const {
    return std::make_shared<Pizza>(*this);
}
