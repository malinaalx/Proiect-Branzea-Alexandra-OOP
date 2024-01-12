// Persoana.h

#pragma once

#include <iostream>
///avem funcții virtuale pure în clasa de bază (Persoana),
/// și acestea sunt apelate prin pointeri de bază în cadrul funcțiilor polimorfice.
///Constructorii din clasele derivate (Contact, Agenda, Aplicatie)
/// apelează constructorul clasei de bază (Persoana).
class Persoana {
private:
    std::string nume;
    std::string prenume;

public:
    Persoana() = default;
    Persoana(std::string nume, std::string prenume);
    Persoana(const Persoana& other) = default;
    Persoana& operator=(const Persoana& other);
    ~Persoana() = default;

    friend std::ostream& operator<<(std::ostream& os, const Persoana& persoana);
};