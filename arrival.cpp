#include <iostream>
#include "time_generators.h"
#include "arrival.h"
#include "SimulationState.h"

using namespace std;

void arrival(SimulationState& state) {
  double interarrival_time = generate_interarrival_time(state.lambda_val);
  state.arrival_times.push_back(state.current_time);
  state.event_list.push(Event(state.current_time + interarrival_time, "arrival"));

    if (state.patients_in_system >= state.B) {
        state.patients_dropped++;
        return;
    }
    state.patients_in_system++;
    // Increment patients in E queue
    state.patients_in_E_queue_counter++;
        
    if (state.patients_in_E_queue_counter <= state.m1) {
      cout << "Adding Patient to Evaluation Queue" << endl;
      // Add patient to the emergency queue
      Patient new_patient;
      new_patient.arrivalTime = state.current_time;
      new_patient.serviceTime = generate_evaluation_time(state.mu_e);
      state.evaluation_queue.push(new_patient);
      
      state.total_wait_E_queue += state.current_time - new_patient.arrivalTime;
      state.wait_times_E_queue.push_back(state.current_time - new_patient.arrivalTime);
      // Schedule evaluation start event
      state.event_list.push(Event(state.current_time, "start_evaluation"));
    }
    cout<<"End of fn 1"<<endl;
}