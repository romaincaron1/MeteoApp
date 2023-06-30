//
// Created by Romain Caron on 30/06/2023.
//

#ifndef METEO_TORNADO_H
#define METEO_TORNADO_H

#include "Catastrophe.h"

class Tornado : public Catastrophe {
    private:
        float speed;
    public:
        Tornado(std::string name, float speed, Meteo meteo);
        // Getters
        const float getSpeed() const;
        // Setters
        void setSpeed(float speed);
};


#endif //METEO_TORNADO_H
