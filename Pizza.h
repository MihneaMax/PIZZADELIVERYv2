
#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <vector>
#include <memory>
#include "Produs.h"

class Pizza : public Produs {
private:
    std::string tip;
    std::vector<std::string> ingrediente;

public:
    Pizza(const std::string& nume, double pret, const std::string& tip, const std::vector<std::string>& ingrediente);

    std::string getTip() const;
    std::vector<std::string> getIngrediente() const;
    double getPret() const override;

    std::shared_ptr<Produs> clone() const override;
};

#endif // PIZZA_H
