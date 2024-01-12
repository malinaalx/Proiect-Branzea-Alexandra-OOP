#pragma once

#include "../headers/Agenda.h"
#include <memory>
class Aplicatie {
private:
    std::unique_ptr<Agenda> agenda;
public:
    Aplicatie();
    void ruleaza();
    static bool verificaNumarTelefon(const std::string& numarTelefon);///functie statica
};