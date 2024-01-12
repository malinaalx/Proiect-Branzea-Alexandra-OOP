#pragma once

#include "../headers/Persoana.h"
#include <iostream>

class Contact {
private:

    Persoana persoana;
    std::string numarTelefon;

public:
    Contact(const Persoana& persoana, const std::string& numarTelefon);
    ~Contact() = default;

    std::string getNumarTelefon() const;

    friend std::ostream& operator<<(std::ostream& os, const Contact& contact);

    void push_back(const Contact &contact);

};