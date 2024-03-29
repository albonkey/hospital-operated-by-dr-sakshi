#include <iostream>
#include "treatment.h"
#include "time_generators.h"
#include "SimulationState.h"
#include "cleanup.h"

void start_treatment(SimulationState& state) {
    if (state.rooms_available != 0 && !state.patient_priority_queue.empty()) {
        // Update the global variable to reflect the patient currently being treated
        Patient patient = state.patient_priority_queue.top();
        state.patient_priority_queue.pop(); // Remove the patient from the queue
        
        // Decrement patient count
        state.patients_in_system--;
        
        // Decrement available rooms
        state.rooms_available--;
      
        // Generate treatment time based on priority
        double treatment_time = generate_treatment_time(patient.priority, state.mu_t);
        
        // Schedule treatment completion event
        state.event_list.push(Event(state.current_time + treatment_time, "complete_treatment", patient));
    }
    else {
        wait_cleanup(state);
    }
    std::cout << "End of fn 5" << std::endl;
}

void complete_treatment(Patient& patient, SimulationState& state) {
    // Increment total departures
    state.total_departures++;
    state.rooms_waiting_cleanup++;
    // Calculate response time
    double response_time = state.current_time - patient.arrivalTime;
    state.total_response_time += response_time;

    // Record departure time
    state.departure_times.push_back(state.current_time);
    
    state.event_list.push(Event(state.current_time, "wait_cleanup"));

    std::cout << "End of fn 6" << std::endl;
}