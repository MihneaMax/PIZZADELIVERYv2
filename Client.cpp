#include "Client.h"

Client::Client(const std::string& nume, const std::string& telefon, const Adresa& adresa)
    : nume(nume), telefon(telefon), adresa(adresa) {}

std::string Client::getNume() const {
    return nume;
}

std::string Client::getTelefon() const {
    return telefon;
}

Adresa Client::getAdresa() const {
    return adresa;
}
