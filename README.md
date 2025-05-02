
# Proiect PizzaDelivery

## Descriere

Acest proiect implementeaza un sistem de gestionare a comenzilor pentru o pizzerie 
- Mostenire: clasele `Pizza`, `Bautura` și `Desert` deriva din clasa abstractă `Produs`
- Functii virtuale și `clone()`
- Smart pointers (`std::shared_ptr`)
- Exceptii personalizate (`std::exception`)
- STL (`std::vector`, `std::string`)
- Separare în fisiere `.cpp` și `.h`

## Fișiere

- `PizzaDelivery.cpp` - fisier principal (`main`)
- `input.txt` - fișier de intrare cu comenzi
- clasele sunt separate în fisiere header/sursa

## Cum rulezi proiectul

```bash
g++ -std=c++17 *.cpp -o pizza_app
./pizza_app
```

## Exemplu input (`input.txt`)

```
Ion Popescu
0722123456
Strada Florilor
15
Bucuresti
2024-05-01
2
Margherita
25.5
Clasica
rosii,mozzarella,busuioc
Cola
8.5
0
```

### Legenda input:
- client: nume, telefon, adresa, data
- 2 produse: o pizza și o bautura

## Comportament asteptat

Programul va citi comanda din fisier, va crea produsele folosind polimorfism si va afisa comanda si detaliile produselor, inclusiv tipul specific (Pizza/Bautura/Desert).
