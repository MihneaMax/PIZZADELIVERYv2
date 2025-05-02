
#include "Produs.h"
#include "Exceptii.h"

Produs::Produs(const std::string& nume, double pret)
    : nume(nume), pret(pret) {
    if (nume.empty() || pret <= 0.0) {
        throw ExceptieProdusInvalid();
    }
}
