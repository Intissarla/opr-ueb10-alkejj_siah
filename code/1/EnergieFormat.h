#pragma once
#include <string>
class EnergieFormat {
public:
    EnergieFormat() = default;
    virtual std::string format(double nicht_formatiert) = 0;
    virtual ~EnergieFormat() = default;
};
