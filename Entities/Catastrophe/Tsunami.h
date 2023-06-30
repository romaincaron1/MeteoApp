//
// Created by Romain Caron on 30/06/2023.
//

#ifndef METEO_TSUNAMI_H
#define METEO_TSUNAMI_H

#include "Catastrophe.h"

class Tsunami : public Catastrophe {
    private:
        float waveHeight;
    public:
        Tsunami(std::string name, float waveHeight, Meteo meteo);
};


#endif //METEO_TSUNAMI_H
