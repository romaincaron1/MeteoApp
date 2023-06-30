//
// Created by Romain Caron on 28/06/2023.
//

#ifndef METEO_FLOOD_H
#define METEO_FLOOD_H

#include "Catastrophe.h"

class Flood : public Catastrophe {
    public:
        Flood(std::string name, Meteo meteo);
};


#endif //METEO_FLOOD_H
