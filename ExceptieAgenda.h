//
// Created by alexa on 12/6/2023.
//

#ifndef EXCEPTIE_AGENDA_H
#define EXCEPTIE_AGENDA_H

#include <stdexcept>

class ExceptieAgenda : public std::runtime_error {
public:
    ExceptieAgenda() : std::runtime_error("ExceptieAgenda: Numarul de telefon invalid.") {}
};

#endif // EXCEPTIE_AGENDA_H
