//
// Created by Romain Caron on 04/07/2023.
//

#ifndef METEO_METEOREPOSITORY_H
#define METEO_METEOREPOSITORY_H


#include "../Database/DatabaseConnection.h"
#include "../Entities/Meteo/Meteo.h"

class MeteoRepository {
    public:
        MeteoRepository();
        int save(const Meteo& meteo);
        Meteo findById(int id);
        void update(const Meteo& meteo);
        bool remove(const Meteo& meteo);
};


#endif //METEO_METEOREPOSITORY_H
