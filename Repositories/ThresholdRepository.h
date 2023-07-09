//
// Created by Romain Caron on 02/07/2023.
//

#ifndef METEO_THRESHOLDREPOSITORY_H
#define METEO_THRESHOLDREPOSITORY_H

#include <iostream>
#include <vector>
#include "../Entities/Threshold/Threshold.h"
#include "../Database/DatabaseConnection.h"

class ThresholdRepository {
public:
    ThresholdRepository();
    int save(const Threshold& threshold);
    Threshold findById(int id);
    void update(const Threshold& threshold);
    bool remove(const Threshold& threshold);
};


#endif //METEO_THRESHOLDREPOSITORY_H
