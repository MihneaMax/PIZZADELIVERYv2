#ifndef ADRESA_H
#define ADRESA_H

#include <string>

class Adresa {
private:
    std::string strada;
    int numar;
    std::string oras;

public:
    Adresa(const std::string& strada, int numar, const std::string& oras);
    
    std::string getStrada() const;
    int getNumar() const;
    std::string getOras() const;
};

#endif 
