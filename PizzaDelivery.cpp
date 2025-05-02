
#include "Client.h"
#include "Comanda.h"
#include "Pizza.h"
#include "Bautura.h"
#include "Desert.h"
#include "Adresa.h"
#include "Exceptii.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <algorithm>

void afiseazaMeniu() {
    std::cout << "\n=== MENIU ===\n";
    std::cout << "1. Adaugă comandă nouă\n";
    std::cout << "2. Încarcă comenzi din fișier\n";
    std::cout << "3. Afișează toate comenzile\n";
    std::cout << "4. Sortează comenzile după dată\n";
    std::cout << "5. Modifică o comandă\n";
    std::cout << "0. Ieșire\n";
    std::cout << "Alege opțiunea: ";
}

std::shared_ptr<Comanda> creeazaComandaDeLaTastatura(int id) {
    std::string nume, telefon, strada, oras, data;
    int numar;

    std::cin.ignore();
    std::cout << "Nume client: "; std::getline(std::cin, nume);
    std::cout << "Telefon: "; std::getline(std::cin, telefon);
    std::cout << "Strada: "; std::getline(std::cin, strada);
    std::cout << "Număr: "; std::cin >> numar;
    std::cin.ignore();
    std::cout << "Oraș: "; std::getline(std::cin, oras);
    std::cout << "Data comenzii (YYYY-MM-DD): "; std::getline(std::cin, data);

    Client client(nume, telefon, Adresa(strada, numar, oras));
    auto comanda = std::make_shared<Comanda>(id, client, Adresa(strada, numar, oras), data);

    int nrProduse;
    std::cout << "Câte produse are comanda? "; std::cin >> nrProduse;
    std::cin.ignore();

    for (int i = 0; i < nrProduse; ++i) {
        std::string tip;
        std::cout << "Tip produs (Pizza/Bautura/Desert): ";
        std::getline(std::cin, tip);

        if (tip == "Pizza") {
            std::string numeP, tipP, ing;
            double pret;
            std::cout << "Nume pizza: "; std::getline(std::cin, numeP);
            std::cout << "Preț: "; std::cin >> pret;
            std::cin.ignore();
            std::cout << "Tip: "; std::getline(std::cin, tipP);
            std::cout << "Ingrediente (separate prin virgula): "; std::getline(std::cin, ing);

            std::vector<std::string> ingrediente;
            size_t pos;
            while ((pos = ing.find(',')) != std::string::npos) {
                ingrediente.push_back(ing.substr(0, pos));
                ing.erase(0, pos + 1);
            }
            ingrediente.push_back(ing);

            comanda->adaugaProdus(std::make_shared<Pizza>(numeP, pret, tipP, ingrediente));
        } else if (tip == "Bautura") {
            std::string numeB;
            double pret;
            int alc;
            std::cout << "Nume băutură: "; std::getline(std::cin, numeB);
            std::cout << "Preț: "; std::cin >> pret;
            std::cout << "Alcoolică? (1/0): "; std::cin >> alc;
            std::cin.ignore();
            comanda->adaugaProdus(std::make_shared<Bautura>(numeB, pret, alc));
        } else if (tip == "Desert") {
            std::string numeD;
            double pret;
            int rece;
            std::cout << "Nume desert: "; std::getline(std::cin, numeD);
            std::cout << "Preț: "; std::cin >> pret;
            std::cout << "Servit rece? (1/0): "; std::cin >> rece;
            std::cin.ignore();
            comanda->adaugaProdus(std::make_shared<Desert>(numeD, pret, rece));
        }
    }

    return comanda;
}

void citesteDinFisier(std::vector<std::shared_ptr<Comanda>>& comenzi) {
    std::ifstream fisier("input.txt");
    if (!fisier) throw ExceptieCitireFisier();

    std::string nume, telefon, strada, oras, dataComanda;
    while (std::getline(fisier, nume)) {
        std::getline(fisier, telefon);
        std::getline(fisier, strada);
        int numar;
        fisier >> numar; fisier.ignore();
        std::getline(fisier, oras);
        std::getline(fisier, dataComanda);

        Client client(nume, telefon, Adresa(strada, numar, oras));
        auto comanda = std::make_shared<Comanda>(comenzi.size() + 1, client, Adresa(strada, numar, oras), dataComanda);

        int nrProduse; fisier >> nrProduse; fisier.ignore();

        for (int i = 0; i < nrProduse; ++i) {
            std::string tipProdus;
            std::getline(fisier, tipProdus);

            if (tipProdus == "Pizza") {
                std::string numeP, tip, ingredienteStr;
                double pret;
                std::getline(fisier, numeP); fisier >> pret; fisier.ignore();
                std::getline(fisier, tip); std::getline(fisier, ingredienteStr);
                std::vector<std::string> ingrediente;
                size_t pos;
                while ((pos = ingredienteStr.find(',')) != std::string::npos) {
                    ingrediente.push_back(ingredienteStr.substr(0, pos));
                    ingredienteStr.erase(0, pos + 1);
                }
                ingrediente.push_back(ingredienteStr);
                comanda->adaugaProdus(std::make_shared<Pizza>(numeP, pret, tip, ingrediente));
            } else if (tipProdus == "Bautura") {
                std::string numeB; double pret; int alc;
                std::getline(fisier, numeB); fisier >> pret >> alc; fisier.ignore();
                comanda->adaugaProdus(std::make_shared<Bautura>(numeB, pret, alc));
            } else if (tipProdus == "Desert") {
                std::string numeD; double pret; int rece;
                std::getline(fisier, numeD); fisier >> pret >> rece; fisier.ignore();
                comanda->adaugaProdus(std::make_shared<Desert>(numeD, pret, rece));
            }
        }
        comenzi.push_back(comanda);
    }
}

int main() {
    try {
        std::vector<std::shared_ptr<Comanda>> comenzi;
        citesteDinFisier(comenzi);
        std::cout << comenzi.size() << " comenzi au fost incarcate din fișier.\n";
        int alegere;

        do {
            afiseazaMeniu();
            std::cin >> alegere;
            switch (alegere) {
                case 1: {
                    auto comanda = creeazaComandaDeLaTastatura(comenzi.size() + 1);
                    comenzi.push_back(comanda);
                    break;
                }
                case 2: {
                    citesteDinFisier(comenzi);
                    break;
                }
                case 3: {
                    for (const auto& c : comenzi) {
                        std::cout << "\nComanda #" << c->getId() << " - Data: " << c->getData() << "\n";
                        c->afiseazaProduse();
                    }
                    break;
                }
                case 4: {
                    std::sort(comenzi.begin(), comenzi.end(), [](const auto& a, const auto& b) {
                        return a->getData() < b->getData();
                    });
                    std::cout << "Comenzile au fost sortate dupa data.\n";
                    break;
                }
                case 5: {
                    int id;
                    std::cout << "Introdu ID-ul comenzii de modificat: ";
                    std::cin >> id;
                    if (id > 0 && id <= (int)comenzi.size()) {
                        auto comandaNoua = creeazaComandaDeLaTastatura(id);
                        comenzi[id - 1] = comandaNoua;
                        std::cout << "Comanda a fost modificată cu succes.\n";
                    } else {
                        std::cout << "ID invalid.\n";
                    }
                    break;
                }
                case 0:
                    std::cout << "Iesire...\n";
                    break;
                default:
                    std::cout << "Optiune invalidă.\n";
            }
        } while (alegere != 0);

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Eroare: " << e.what() << "\n";
        return 1;
    }
}
