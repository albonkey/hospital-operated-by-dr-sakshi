#ifndef PATIENT_H
#define PATIENT_H

struct Patient {
    double arrivalTime;
    double priority;
    double serviceTime;
};

struct ComparePatients {
    bool operator()(const Patient& p1, const Patient& p2) const
    {
        // Higher priority patients should have higher priority in the queue
        return p1.priority < p2.priority;
    }
};

#endif