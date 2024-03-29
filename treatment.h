#ifndef TREATMENT_H
#define TREATMENT_H

#include "Patient.h"
#include "SimulationState.h"

class Patient; 

void start_treatment(SimulationState& state);
void complete_treatment(Patient& patient, SimulationState& state); 

#endif