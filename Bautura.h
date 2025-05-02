
#ifndef BAUTURA_H
#define BAUTURA_H

#include "Produs.h"
#include <string>
#include <memory>

class Bautura : public Produs {
private:
    bool eAcoolica;

public:
    Bautura(const std::string& nume, double pret, bool alcoolica);

    double getPret() const override;
    bool esteAlcoolica() const;

    std::shared_ptr<Produs> clone() const override;
};

#endif 
