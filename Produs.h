
#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <memory>

class Produs {
protected:
    std::string nume;
    double pret;

public:
    Produs(const std::string& nume, double pret);
    virtual ~Produs() = default;

    virtual double getPret() const = 0;
    virtual std::shared_ptr<Produs> clone() const = 0;

    std::string getNume() const { return nume; }
};

#endif 
