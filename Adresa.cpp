#include "Adresa.h"

Adresa::Adresa(const std::string& strada, int numar, const std::string& oras)
    : strada(strada), numar(numar), oras(oras) {}

std::string Adresa::getStrada() const {
    return strada;
}

int Adresa::getNumar() const {
    return numar;
}

std::string Adresa::getOras() const {
    return oras;
}
