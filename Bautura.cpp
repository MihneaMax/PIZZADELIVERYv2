
#include "Bautura.h"

Bautura::Bautura(const std::string& nume, double pret, bool alcoolica)
    : Produs(nume, pret), eAcoolica(alcoolica) {}

double Bautura::getPret() const {
    return pret;
}

bool Bautura::esteAlcoolica() const {
    return eAcoolica;
}

std::shared_ptr<Produs> Bautura::clone() const {
    return std::make_shared<Bautura>(*this);
}
