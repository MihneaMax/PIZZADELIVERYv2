
#ifndef COMANDA_H
#define COMANDA_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Produs.h"
#include "Client.h"
#include "Adresa.h"
#include "StatusComanda.h"

class Comanda {
private:
    int id;
    Client client;
    Adresa adresa;
    std::string data;
    StatusComanda status;
    std::vector<std::shared_ptr<Produs>> produse;

public:
    Comanda(int id, const Client& client, const Adresa& adresa, const std::string& data);

    int getId() const { return id; }
    const Client& getClient() const { return client; }
    const std::string& getData() const { return data; }

    void adaugaProdus(std::shared_ptr<Produs> produs);
    void afiseazaProduse() const;
};

#endif
