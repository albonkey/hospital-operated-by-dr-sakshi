#include <iostream>
#include "departFromEvaluationQueue.h"
#include "Patient.h"
#include "SimulationState.h"

void depart_from_E_queue(Patient& patient, SimulationState& state) {
    state.patients_in_E_queue_counter--;
    state.evaluation_queue.pop();
    state.event_list.push(Event(state.current_time, "arrive_P_queue", patient));

    std::cout << "End of fn 3" << std::endl;
}