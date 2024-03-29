#include "../headers/Contact.h"
#include "../headers/Persoana.h"

Contact::Contact(const Persoana& persoana, const std::string& numarTelefon)
        : persoana(persoana), numarTelefon(numarTelefon) {}

std::string Contact::getNumarTelefon() const {
    return numarTelefon;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << "Nume: " << contact.persoana << ", Numar de telefon: " << contact.numarTelefon;
    return os;
}

void Contact::push_back(const Contact &contact) {

}
