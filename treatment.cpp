#include <iostream>
#include "treatment.h"
#include "time_generators.h"
#include "SimulationState.h"

void start_treatment(SimulationState& state) {
    if (state.rooms_available == 0) {
        state.event_list.push(Event(state.current_time, "wait_cleanup"));
    } else if (!state.patient_priority_queue.empty()){
        // Update the global variable to reflect the patient currently being treated
        Patient patient = state.patient_priority_queue.top();
        state.patient_priority_queue.pop(); // Remove the patient from the queue
        
        // Decrement available rooms
        state.rooms_available--;
      
        // Generate treatment time based on priority
        double treatment_time = generate_treatment_time(patient.priority, state.mu_t);
        cout << "Treatment time: " << treatment_time << endl;
        // Schedule treatment completion event
        state.event_list.push(Event(state.current_time + treatment_time, "complete_treatment", patient));
    }

    std::cout << "End of fn 5" << std::endl;
}

void complete_treatment(Patient& patient, SimulationState& state) {
    state.total_departures++;
    state.rooms_waiting_cleanup++;
    state.patients_in_system--;
    double response_time = state.current_time - patient.arrivalTime;
    cout << "-------------------- RESPONSE TIME: " << response_time << endl;
    state.response_times.push_back(response_time);
    state.total_response_time += response_time;
    cout << "-------------------- TOTAL RESPONSE TIME: " << state.total_response_time << endl;
    
    state.departure_times.push_back(state.current_time);
    
    state.event_list.push(Event(state.current_time, "wait_cleanup"));

    std::cout << "End of fn 6" << std::endl;
}