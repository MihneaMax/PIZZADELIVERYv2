
#include "Comanda.h"
#include "Exceptii.h"
#include "Pizza.h"
#include "Bautura.h"
#include "Desert.h"

Comanda::Comanda(int id, const Client& client, const Adresa& adresa, const std::string& data)
    : id(id), client(client), adresa(adresa), data(data), status(StatusComanda::InPregatire) {}

void Comanda::adaugaProdus(std::shared_ptr<Produs> produs) {
    produse.push_back(produs);
}

void Comanda::afiseazaProduse() const {
    if (produse.empty()) {
        throw ExceptieComandaGoala();
    }

    std::cout << "Produse comandate:\n";
    for (const auto& produs : produse) {
        std::cout << " - " << produs->getNume() << " (" << produs->getPret() << " RON)\n";

        if (auto p = std::dynamic_pointer_cast<Pizza>(produs)) {
            std::cout << "   -> Tip: Pizza [" << p->getTip() << "]\n";
        } else if (auto b = std::dynamic_pointer_cast<Bautura>(produs)) {
            std::cout << "   -> Tip: Bautura " << (b->esteAlcoolica() ? "(alcoolica)" : "(nealcoolica)") << "\n";
        } else if (auto d = std::dynamic_pointer_cast<Desert>(produs)) {
            std::cout << "   -> Tip: Desert " << (d->esteRece() ? "(rece)" : "(cald)") << "\n";
        }
    }
}
