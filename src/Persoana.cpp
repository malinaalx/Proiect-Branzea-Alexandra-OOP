#include <string>

#include "../headers/Persoana.h"

using namespace std;
Persoana::Persoana(std::string nume, std::string prenume)
        : nume(std::move(nume)), prenume(std::move(prenume)) {}

Persoana& Persoana::operator=(const Persoana& other) {
    if (this != &other) {
        nume = other.nume;
        prenume = other.prenume;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Persoana& persoana) {
    os << persoana.nume << " " << persoana.prenume;
    return os;
}

