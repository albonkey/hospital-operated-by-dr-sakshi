#ifndef CLEANUP_H
#define CLEANUP_H

#include "SimulationState.h"

void wait_cleanup(SimulationState& state);
void start_cleanup(SimulationState& state); 
void end_cleanup(SimulationState& state); 

#endif