#pragma once
#include "Geraet.h"
#include <sstream>
class Bankdruecken : public Geraet {
public:
    static double ERDBESCHLEUNIGUNG;
    Bankdruecken() = default;
    double energieProWiederholung(const Sportler &sportler) override;
    std::string text() const override;
    friend std::ostream& operator<<(std::ostream &os, const Bankdruecken &geraet);
};
