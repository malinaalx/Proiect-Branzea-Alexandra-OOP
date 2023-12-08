#include "Aplicatie.h"
#include <iostream>
#include "ExceptieAgenda.h"
#include "Contact.h"
////Utilizare cu sens: throw în constructor, try/catch în main:
///Exemple de utilizare cu sens a excepțiilor sunt prezente,
/// de exemplu, în Aplicatie::ruleaza unde se aruncă excepții
/// în cazul introducerii unui număr de telefon invalid.
#include "Aplicatie.h"
#include <iostream>
#include <stdexcept>

Aplicatie::Aplicatie() : agenda(std::make_unique<Agenda>()) {}

void Aplicatie::ruleaza() {
    while (true) {
        std::cout << "1. Adauga contact\n2. Afiseaza contacte\n3. Iesire\n";
        int optiune;
        std::cin >> optiune;

        if (optiune == 1) {
            // Adăugare contact în agenda
            std::string nume, prenume, numarTelefon;
            std::cout << "Nume: ";
            std::cin >> nume;
            std::cout << "Prenume: ";
            std::cin >> prenume;

            do {
                try {
                    std::cout << "Numar de telefon: ";
                    std::cin >> numarTelefon;

                    if (!verificaNumarTelefon(numarTelefon)) {
                        throw std::runtime_error("Numarul de telefon nu este valid.");
                    }

                    Persoana persoana(nume, prenume);
                    Contact contact(persoana, numarTelefon);
                    agenda->adaugaContact(contact);
                } catch (const std::runtime_error &ex) {
                    std::cerr << "Exceptie: " << ex.what() << std::endl;
                }
            } while (!verificaNumarTelefon(numarTelefon));
        } else if (optiune == 2) {
            // Afișare contacte din agenda
            std::cout << "Contactele din agenda:\n";
            agenda->afiseazaContacte();
        } else if (optiune == 3) {
            break;
        } else {
            std::cout << "Optiune invalida. Incercati din nou.\n";
        }
    }
}

bool Aplicatie::verificaNumarTelefon(const std::string& numarTelefon) {
    return (numarTelefon.length() >= 10 && numarTelefon.length() <= 12);
}
