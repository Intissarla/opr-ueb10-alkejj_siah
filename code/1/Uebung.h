#pragma once

#include "Sportler.h"
#include "Bankdruecken.h"
#include "EnergieFormat.h"

template <typename Formatierer>
class Uebung {
private:
    Sportler* sportler_;
    Bankdruecken geraet_;
    int anzahlSaetze_;
    int anzahlWiederholungenProSatz_;
    double gewicht_;
    double umgesetzteEnergie;
    Formatierer formatierer_;

public:
    Uebung(Sportler& sportler, Bankdruecken& geraet, int anzahlSaetze, int anzahlWiederholungenProSatz, double gewicht)
        : sportler_(&sportler), geraet_(geraet),
          anzahlSaetze_(anzahlSaetze), anzahlWiederholungenProSatz_(anzahlWiederholungenProSatz),
          gewicht_(gewicht), umgesetzteEnergie(0) {
        geraet_.gewichtEinstellen(gewicht_);
    }

    std::ostream& ausfuehren(std::ostream& os) {
        for (int i = 0; i < anzahlSaetze_ * anzahlWiederholungenProSatz_; ++i) {
            double energie = geraet_.energieProWiederholung(*sportler_) / Sportler::WIRKUNGSGRAD;
            umgesetzteEnergie += energie;
            sportler_->wiederholungAusfuehren(geraet_);
        }
        os << formatierer_.format(umgesetzteEnergie) << std::endl;
        return os;
    }

    std::string energieUmsatz() {
        return formatierer_.format(umgesetzteEnergie);
    }
};
