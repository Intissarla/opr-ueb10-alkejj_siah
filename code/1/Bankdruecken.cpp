#include "Bankdruecken.h"
#include "Sportler.h"
double Bankdruecken::ERDBESCHLEUNIGUNG = 9.81;
double Bankdruecken::energieProWiederholung(const Sportler &sportler) {
    return gewicht * ERDBESCHLEUNIGUNG * sportler.armlaenge();
}
std::string Bankdruecken::text() const {
    std::stringstream ausgabe;
    ausgabe << "Auf dem Geraet Bankdrücken sind " << gewicht << " kg eingestellt.";
    return ausgabe.str();
}
std::ostream& operator<<(std::ostream &os, const Bankdruecken &geraet) {
    os << geraet.text();
    return os;
}