
#ifndef DESERT_H
#define DESERT_H

#include "Produs.h"
#include <string>
#include <memory>

class Desert : public Produs {
private:
    bool eRece;

public:
    Desert(const std::string& nume, double pret, bool rece);

    double getPret() const override;
    bool esteRece() const;

    std::shared_ptr<Produs> clone() const override;
};

#endif 
