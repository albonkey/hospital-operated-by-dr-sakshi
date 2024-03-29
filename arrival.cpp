#include <iostream>
#include "time_generators.h"
#include "arrival.h"
#include "SimulationState.h"

using namespace std;

void arrival(SimulationState& state) {
    if (state.patients_in_system >= state.B) {
        state.patients_dropped++;
        state.event_list.push(Event(state.current_time, "depart_E_queue"));
    }

    // Increment patients in E queue
    state.patients_in_E_queue_counter++;
        
    if (state.patients_in_E_queue_counter <= state.m1) {
      cout << "Adding Patient to Emergency Queue" << endl;
      // Add patient to the emergency queue
      Patient new_patient;
      new_patient.arrivalTime = state.current_time;
      new_patient.serviceTime = generate_evaluation_time(state.mu_e);
      state.emergency_queue.push(new_patient);
      
      state.total_wait_E_queue += state.current_time - new_patient.arrivalTime;
      state.wait_times_E_queue.push_back(state.current_time - new_patient.arrivalTime);
      state.total_response_time = state.current_time - new_patient.arrivalTime;
      // Schedule evaluation start event
      state.event_list.push(Event(state.current_time, "start_evaluation"));
    }
    cout<<"End of fn 1"<<endl;
}