//
// Created by alexa on 12/6/2023.
//
/*
#ifndef EXCEPTIE_AGENDA_H
#define EXCEPTIE_AGENDA_H

#include <stdexcept>

class ExceptieAgenda : public std::runtime_error {
public:
    ExceptieAgenda() : std::runtime_error("ExceptieAgenda: Numarul de telefon invalid.") {}
};

#endif // EXCEPTIE_AGENDA_H
*/
#ifndef EXCEPTIE_AGENDA_H
#define EXCEPTIE_AGENDA_H

#include <stdexcept>
#include <string>

class ExceptieAgenda : public std::runtime_error {
private:
    std::string detalii;

public:
    ExceptieAgenda(const std::string& mesaj, const std::string& detaliiAditionale)
            : std::runtime_error(mesaj), detalii(detaliiAditionale) {}
    // Metodă pentru a obține detalii
    const std::string& getDetalii() const {
        return detalii;
    }
};

#endif // EXCEPTIE_AGENDA_H
