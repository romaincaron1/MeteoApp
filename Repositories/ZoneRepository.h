//
// Created by Romain Caron on 02/07/2023.
//

#include <iostream>
#include <vector>
#include "../Entities/Zone/Zone.h"
#include "../Database/DatabaseConnection.h"

#ifndef METEO_ZONEREPOSITORY_H
#define METEO_ZONEREPOSITORY_H


class ZoneRepository {
    public:
        ZoneRepository();
        int save(const Zone& zone);
        Zone findById(int id);
        void update(const Zone& zone);
        bool remove(const Zone& zone);
};


#endif //METEO_ZONEREPOSITORY_H
