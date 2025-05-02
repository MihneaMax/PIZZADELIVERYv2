
#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>

class ExceptieProdusInvalid : public std::exception {
public:
    const char* what() const noexcept override {
        return "Produs invalid: nume sau pret incorect.";
    }
};

class ExceptieComandaGoala : public std::exception {
public:
    const char* what() const noexcept override {
        return "Comanda nu conține niciun produs.";
    }
};

class ExceptieCitireFisier : public std::exception {
public:
    const char* what() const noexcept override {
        return "Eroare la citirea fisierului de comenzi.";
    }
};

#endif 
