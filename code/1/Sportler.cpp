#include "Sportler.h"
#include "Bankdruecken.h"
double Sportler::WIRKUNGSGRAD = 0.25;
Sportler::Sportler(const std::string& name1, double gewicht, double laenge)
    : name_(name1), koerpergewicht_(gewicht), armlaenge_(laenge) {}
std::string Sportler::name() const { return name_; }
double Sportler::koerpergewicht() const { return koerpergewicht_; }
double Sportler::armlaenge() const { return armlaenge_; }
void Sportler::wiederholungAusfuehren(Bankdruecken &geraet) {
    double energie = geraet.eingestelltesGewicht() * Bankdruecken::ERDBESCHLEUNIGUNG * armlaenge_ / WIRKUNGSGRAD;
    umgesezteEnegie += energie;
}
double Sportler::energieUmsatz() const {
    return umgesezteEnegie;
}
std::string Sportler::text() const {
    std::stringstream ausgabe;
    ausgabe << name_ << ": Körpergewicht = " << koerpergewicht_ << " kg, Armlänge = " << armlaenge_ << " m, Energieumsatz = " << energieUmsatz() << " J";
    return ausgabe.str();
}
std::ostream& operator<<(std::ostream &os, const Sportler &sportler) {
    os << sportler.text();
    return os;
}