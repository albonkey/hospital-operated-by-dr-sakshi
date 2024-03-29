#include "Event.h"
#include "Patient.h"

Event::Event(double t, std::string ty) : time(t), type(ty) {}

Event::Event(double t, std::string ty, const Patient& p) : time(t), type(ty), patient(p) {}

bool Event::operator>(const Event& other) const {

    return time > other.time;
    
}