#pragma once

#include "EnergieFormat.h"
#include <sstream>
#include <iomanip>

class EnergieFormatSchokolade : public EnergieFormat {
public:
    EnergieFormatSchokolade() = default;

    std::string format(double nicht_formatiert) override {
        double tafeln = nicht_formatiert / 2220000.0;  // korrekter Umrechnungsfaktor
        std::stringstream ausgabe;
        ausgabe << std::fixed << std::setprecision(3)
                << tafeln << " Tafeln Schokolade";
        return ausgabe.str();
    }
};
