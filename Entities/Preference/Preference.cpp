#include "Preference.h"

Preference::Preference(Threshold threshold) {
    this->threshold = threshold;
}

Threshold Preference::getThreshold() {
    return this->threshold;
}

void Preference::setThreshold(Threshold threshold) {
    this->threshold = threshold;
}
