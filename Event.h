#ifndef EVENT_H
#define EVENT_H

#include "Patient.h"
#include <string>

struct Event {
    double time;
    std::string type;
    Patient patient;

    Event(double t, std::string ty);
    Event(double t, std::string ty, const Patient& p);

    bool operator>(const Event& other) const;
};

#endif