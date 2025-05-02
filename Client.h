#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "Adresa.h"

class Client {
private:
    std::string nume;
    std::string telefon;
    Adresa adresa;

public:
    Client(const std::string& nume, const std::string& telefon, const Adresa& adresa);
    
    std::string getNume() const;
    std::string getTelefon() const;
    Adresa getAdresa() const;
};

#endif 
