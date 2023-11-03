#include <iostream>
#include <string>
#include <vector>

class Persoana {
private:
    std::string nume;
    std::string prenume;

public:
    Persoana() = default;
    Persoana(std::string nume, std::string prenume)
            : nume(std::move(nume)), prenume(std::move(prenume)) {}

    Persoana(const Persoana& other) = default;

    Persoana& operator=(const Persoana& other) {
        if (this != &other) {
            nume = other.nume;
            prenume = other.prenume;
        }
        return *this;
    }

    ~Persoana() = default;

    friend std::ostream& operator<<(std::ostream& os, const Persoana& persoana) {
        os << persoana.nume << " " << persoana.prenume;
        return os;
    }
};

class Contact {
private:
    Persoana persoana;
    std::string numarTelefon; // Schimbare la std::string

public:
    Contact(Persoana &persoana, std::string&(numarTelefon))
            : persoana((persoana)), numarTelefon((numarTelefon)) {}

    Contact(const Contact& other) = default;

    Contact& operator=(const Contact& other) {
        if (this != &other) {
            persoana = other.persoana;
            numarTelefon = other.numarTelefon;
        }
        return *this;
    }

    ~Contact() = default;
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact) {
        os << "Nume: " << contact.persoana << ", Numar de telefon: " << contact.numarTelefon;
        return os;
    }
};

class Agenda {
private:
    std::vector<Contact> contacte;

public:
    void adaugaContact(const Contact& contact) {
        contacte.push_back(contact);
    }

    void afiseazaContacte() const {
        for (const Contact& contact : contacte) {
            std::cout << contact << std::endl;
        }
    }
};

class Aplicatie {
private:
    Agenda agenda;

public:
    void ruleaza() {
        while (true) {
            std::cout << "1. Adauga contact\n2. Afiseaza contacte\n3. Iesire\n";
            int optiune;
            std::cin >> optiune;

            if (optiune == 1) {
                std::string nume, prenume;
                std::string numarTelefon; // Schimbare la std::string
                std::cout << "Nume: ";
                std::cin >> nume;
                std::cout << "Prenume: ";
                std::cin >> prenume;

                // Bucla do-while pentru a asigura introducerea unui număr de telefon valid
                do {
                    std::cout << "Numar de telefon: ";
                    std::cin >> numarTelefon;

                    if (!verificaNumarTelefon(numarTelefon)) {
                        std::cout << "Numarul de telefon nu este valid. Incercati din nou.\n";
                    }
                } while (!verificaNumarTelefon(numarTelefon));

                Persoana persoana(nume, prenume);
                Contact contact(persoana, numarTelefon);
                agenda.adaugaContact(contact);
            } else if (optiune == 2) {
                std::cout << "Contactele din agenda:\n";
                agenda.afiseazaContacte();
            } else if (optiune == 3) {
                break;
            } else {
                std::cout << "Optiune invalida. Incercati din nou.\n";
            }
        }
    }
    [[nodiscard]]
    static bool verificaNumarTelefon(const std::string& numarTelefon)  {
        // Verifica daca numarul de telefon are intre 10 si 12 cifre
        return (numarTelefon.length() >= 10 && numarTelefon.length() <= 12);
    }
};

int main() {
    Aplicatie aplicatie;
    aplicatie.ruleaza();
    return 0;
}