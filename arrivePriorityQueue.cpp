#include <iostream>
#include "arrivePriorityQueue.h"
#include "cleanup.h"
#include "SimulationState.h"

void arrive_P_queue(Patient& patient, SimulationState& state) {
    state.patients_in_P_queue_counter++;
    state.patient_priority_queue.push(patient);
    state.total_wait_P_queue += state.current_time - patient.arrivalTime;
   
    if (state.rooms_available > 0) {
        state.event_list.push(Event(state.current_time, "start_treatment"));
    } else {
        wait_cleanup(state);
    }
    std::cout << "End of fn 4" << std::endl;
}