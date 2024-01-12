#pragma once
#include "../headers/Factory.h"
#include "../headers/Persoana.h"
#include "../headers/Contact.h"
#include "../headers/Agenda.h"

template <typename T>
T creazaEntitate(const std::string& nume) {
    return Factory<T>::create(nume);
}

template <typename T>
T creazaEntitate(const std::string& nume, const std::string& prenume) {
    return Factory<T>::create(nume, prenume);
}

template <typename T>
T creazaEntitate(const std::string& nume, const Persoana& persoana, const std::string& numarTelefon) {
    return Factory<T>::create(nume, persoana, numarTelefon);
}

template <typename T>
T creazaEntitate(const std::string& nume, const Persoana& persoana, const std::string& numarTelefon, const std::vector<std::string>& grupuri) {
    T entitate = Factory<T>::create(nume, persoana, numarTelefon);
    for (const auto& grup : grupuri) {
        entitate.adaugaGrup(grup);
    }
    return entitate;
}
