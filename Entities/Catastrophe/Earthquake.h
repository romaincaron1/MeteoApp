//
// Created by Romain Caron on 30/06/2023.
//

#ifndef METEO_EARTHQUAKE_H
#define METEO_EARTHQUAKE_H

#include "Catastrophe.h"

class Earthquake : public Catastrophe {
    private:
        int magnitude;
    public:
        Earthquake(std::string name, int magnitude, Meteo meteo);
        // Getters
        const int getMagnitude() const;
        // Setters
        void setMagnitude(int magnitude);
};


#endif //METEO_EARTHQUAKE_H
