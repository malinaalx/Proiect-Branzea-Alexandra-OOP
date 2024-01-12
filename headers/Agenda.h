#pragma once

#include "../headers/Contact.h"
#include <vector>
///Clasa Agenda conține un atribut de tip vector de pointeri la clasa de bază (Contact).


class Agenda {
private:
    std::vector<Contact> contacte;

public:
    void adaugaContact(const Contact &contact);

    void afiseazaContacte() const;

};
