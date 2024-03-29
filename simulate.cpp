#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include <cmath>
#include "time_generators.h"
#include "Patient.h"
#include "Event.h"
#include "cleanup.h"
#include "treatment.h"
#include "arrival.h"
#include "evaluation.h"
#include "departFromEmergencyQueue.h"
#include "arrivePriorityQueue.h"
#include "SimulationState.h"

using namespace std;

void simulate(double lambda_val, double mu_e, double mu_t, double mu_c, int B, int R, int m1, int m2, int S) {

    initialize_generator(S);
    SimulationState state = SimulationState(lambda_val, mu_e, mu_t, mu_c, B, R, m1, m2, S);

    while (!state.event_list.empty()) {
      Event next_event = state.event_list.top();
      state.event_list.pop();
      state.current_time = next_event.time;
      cout << next_event.type << endl;
      if (next_event.type == "arrival") {
          cout << state.janitors_available << endl;
          arrival(state);
      } 
      else if (next_event.type == "start_evaluation") {
          start_evaluation(state);
      } 
      else if (next_event.type == "depart_from_E_queue") {
          depart_from_E_queue(next_event.patient, state);
      }
      else if (next_event.type == "arrive_P_queue") {
          arrive_P_queue(next_event.patient, state);
      } 
      else if (next_event.type == "start_treatment") {
          start_treatment(state);
      } 
      else if (next_event.type == "complete_treatment") {
          complete_treatment(next_event.patient, state);
      } 
      else if (next_event.type == "wait_cleanup") {
          wait_cleanup(state);
      } 
      else if (next_event.type == "start_cleanup") {
          start_cleanup(state);
      } 
      else if (next_event.type == "end_cleanup") {
          end_cleanup(state);
      }
      
      // Debug output
      cout << "Current Time: " << state.current_time << ", Event Type: " << next_event.type << endl;
      cout << "Nr of events on list" << state.event_list.size() << endl;
    }
    
    cout << "Event simulation completed" << endl;

    double sim_time = (state.current_time-360); // Total simulation time excluding 6 hours

    double total_patients_in_system = state.patients_in_E_queue_counter + state.patients_in_P_queue_counter + (state.R - state.rooms_available);
    
    double mean_num_patients = total_patients_in_system / (sim_time*60); // Average number of patients
    double mean_response_time = state.total_departures > 0 ? state.total_response_time / state.total_departures : 0;
    double mean_wait_E_queue = state.total_departures > 0 ? state.total_wait_E_queue / state.total_departures : 0;
    double mean_wait_P_queue = state.total_departures > 0 ? state.total_wait_P_queue/ state.total_departures : 0;
    double mean_cleanup_time = (state.R > 0 && state.total_departures > 0) ? state.total_cleanup_time / (state.R * state.total_departures) : 0;
    
    // Calculate and print statistics
    cout << "Departures = " << state.total_departures << endl;
    cout << "Mean_num_patients = " << mean_num_patients << endl;
    cout << "Mean_response_time = " << mean_response_time/60 << endl;
    cout << "Mean_wait_E_queue = " << mean_wait_E_queue/60 << endl;
    cout << "Mean_wait_P_queue = " << mean_wait_P_queue/60 << endl;
    cout << "Mean_cleanup_time = " << mean_cleanup_time/60 << endl;
    cout << "Dropped_arrivals = " << state.patients_dropped << endl;
}