#include <iostream>
#include "treatment.h"
#include "time_generators.h"
#include "SimulationState.h"

void start_treatment(SimulationState& state) {
    if (state.rooms_available == 0) {
        state.event_list.push(Event(state.current_time, "wait_cleanup"));
    } else if (!state.patient_priority_queue.empty()){
        Patient patient = state.patient_priority_queue.top();
        state.patient_priority_queue.pop();
        state.rooms_available--;
      
        double treatment_time = generate_treatment_time(patient.priority, state.mu_t);
        cout << "Treatment time: " << treatment_time << endl;
        state.event_list.push(Event(state.current_time + treatment_time, "complete_treatment", patient));
    }

    std::cout << "End of fn 5" << std::endl;
}

void complete_treatment(Patient& patient, SimulationState& state) {
    state.total_departures++;
    state.rooms_waiting_cleanup++;
    state.patients_in_system--;
    double response_time = state.current_time - patient.arrivalTime;
    state.response_times.push_back(response_time);
    state.total_response_time += response_time;
    
    state.departure_times.push_back(state.current_time);
    
    state.event_list.push(Event(state.current_time, "wait_cleanup"));

    std::cout << "End of fn 6" << std::endl;
}