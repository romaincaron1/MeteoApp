#ifndef METEO_PREFERENCE_H
#define METEO_PREFERENCE_H

#include "../Threshold/Threshold.h"

class Preference {
    private:
        Threshold threshold;
    public:
        Preference(Threshold threshold);
        Threshold getThreshold();
        // Getters
        Threshold getThreshold() const;
        // Setters
        void setThreshold(Threshold threshold);
};


#endif //METEO_PREFERENCE_H
