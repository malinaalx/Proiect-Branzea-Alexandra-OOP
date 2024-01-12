#include "../headers/Agenda.h"
#include "../headers/Contact.h"

void Agenda::adaugaContact(const Contact &contact) {
    contacte.push_back(contact);
}

void Agenda::afiseazaContacte() const {
    for (const Contact &contact: contacte) {
        std::cout << contact << std::endl;
    }
}







