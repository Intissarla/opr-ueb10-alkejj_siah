#pragma once
#include "EnergieFormat.h"
#include <sstream>
#include <iomanip>
class EnergieFormatJoule : public EnergieFormat {
public:
    EnergieFormatJoule() = default;
    std::string format(double nicht_formatiert) override {
        std::stringstream formatierteAusgabe;
        formatierteAusgabe << std::fixed << std::setprecision(2)
                           << (nicht_formatiert / 1000) << " kJ";
        return formatierteAusgabe.str();
    }
};