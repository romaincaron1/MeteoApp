#ifndef METEO_PREFERENCE_H
#define METEO_PREFERENCE_H

#include "../Threshold/Threshold.h"

class Preference {
    private:
        int id;
        Threshold threshold;
    public:
        Preference(Threshold threshold);
        // Getters
        int getId() const;
        Threshold getThreshold() const;
        // Setters
        void setThreshold(Threshold threshold);
        void setId(int id);
};


#endif //METEO_PREFERENCE_H
