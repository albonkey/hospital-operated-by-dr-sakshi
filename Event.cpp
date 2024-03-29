#include "Event.h"
#include "Patient.h"

Event::Event(double t, std::string ty) : time(t), type(ty) {}

Event::Event(double t, std::string ty, const Patient& p) : time(t), type(ty), patient(p) {}

bool Event::operator>(const Event& other) const {
    if (type == other.type) {
        // Prioritize departure events over arrival events
        return type == "end_cleanup" && other.type == "start_cleanup";
    } else {
        // For events of different types, prioritize based on time
        return time > other.time;
    }
}