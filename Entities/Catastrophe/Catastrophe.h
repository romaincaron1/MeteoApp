//
// Created by Romain Caron on 28/06/2023.
//

#ifndef METEO_CATASTROPHE_H
#define METEO_CATASTROPHE_H

#include <string>
#include "../Meteo/Meteo.h"

class Catastrophe {
    private:
        std::string name;
        Meteo meteo;
    public:
        Catastrophe(std::string name, Meteo meteo);
        // Getters
        virtual std::string getName() const;
        // Setters
        virtual void setName(std::string name);
};


#endif //METEO_CATASTROPHE_H
