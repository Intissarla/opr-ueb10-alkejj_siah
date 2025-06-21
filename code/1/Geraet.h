#pragma once
#include <iostream>
class Sportler;
class Geraet {
public:
    double gewicht = 0;
    Geraet() = default;
    double eingestelltesGewicht();
    void gewichtEinstellen(double gegebenesGewicht);
    virtual double energieProWiederholung(const Sportler &sportler) = 0;
    virtual std::string text() const = 0;
    virtual ~Geraet() = default;
};