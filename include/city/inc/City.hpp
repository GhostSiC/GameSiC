#pragma once
#include <CityIf.hpp>

class City : public CityIf
{
public:
    City();
    // virtual EngineIf() = 0;
    // virtual ~MainEngineIf() = 0;
    void initCity() override;
protected:

};