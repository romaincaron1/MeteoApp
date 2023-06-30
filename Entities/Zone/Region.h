//
// Created by Romain Caron on 27/06/2023.
//

#ifndef METEO_REGION_H
#define METEO_REGION_H


#include "Zone.h"

class Region: public Zone {
    public:
        Region(std::string name, std::uint8_t inseeCode, std::string isoCode);
};


#endif //METEO_REGION_H
