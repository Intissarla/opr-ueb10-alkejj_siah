#pragma once
#include <string>
#include <sstream>
class Bankdruecken;
class Sportler {
private:
    std::string name_;
    double koerpergewicht_;
    double armlaenge_;
    double umgesezteEnegie = 0;
public:
    static double WIRKUNGSGRAD;
    Sportler(const std::string& name1, double gewicht, double laenge);
    Sportler() = default;
    std::string name() const;
    double koerpergewicht() const;
    double armlaenge() const;
    void wiederholungAusfuehren(Bankdruecken &geraet);
    double energieUmsatz() const;
    std::string text() const;
    friend std::ostream& operator<<(std::ostream &os, const Sportler &sportler);
};