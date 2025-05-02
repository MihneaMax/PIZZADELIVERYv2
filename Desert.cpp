
#include "Desert.h"

Desert::Desert(const std::string& nume, double pret, bool rece)
    : Produs(nume, pret), eRece(rece) {}

double Desert::getPret() const {
    return pret;
}

bool Desert::esteRece() const {
    return eRece;
}

std::shared_ptr<Produs> Desert::clone() const {
    return std::make_shared<Desert>(*this);
}
