#ifndef SIMULATIONSTATE_H
#define SIMULATIONSTATE_H

#include <vector>
#include <queue>
#include "Event.h"
#include "Patient.h"

using namespace std;

struct SimulationState {
    int B, R, m1, m2, S;
    double lambda_val, mu_e, mu_t, mu_c;

    double current_time;
    int patients_in_system;

    vector<double> arrival_times;
    int patients_dropped;
    int patients_in_E_queue_counter;
    double total_wait_E_queue;
    vector<double> wait_times_E_queue;

    int patients_in_P_queue_counter;
    double total_wait_P_queue;
    vector<double> wait_times_P_queue;

    int rooms_available;
    int total_departures;
    vector<double> departure_times;
    vector<double> response_times;

    int janitors_available;
    int rooms_waiting_cleanup;
    vector<double> cleanup_times;

    double total_response_time;
    double total_cleanup_time;

    priority_queue<Event, vector<Event>, greater<Event> > event_list;

    queue<Patient> emergency_queue;

    priority_queue<Patient, vector<Patient>, ComparePatients> patient_priority_queue;

    queue<int> janitor_queue;

    SimulationState(
      double lambda_val, 
      double mu_e, 
      double mu_t, 
      double mu_c, 
      int B, 
      int R, 
      int m1, 
      int m2, 
      int S
     ) {
      this->lambda_val = lambda_val;
      this->mu_e = mu_e;
      this->mu_t = mu_t;
      this->mu_c = mu_c;
      this->B = B;
      this->R = R;
      this->m1 = m1;
      this->m2 = m2;
      this->S = S;

      this->patients_in_system = 0;
      this->patients_dropped = 0;
      this->patients_in_E_queue_counter = 0;
      this->total_wait_E_queue = 0;
      this->patients_in_P_queue_counter = 0;
      this->total_wait_P_queue = 0;
      this->rooms_available = R;
      this->total_departures = 0;
      this->janitors_available = m2;
      this->rooms_waiting_cleanup = 0;
      this->total_response_time = 0;
      this->total_cleanup_time = 0;

      for (int i = 0; i < m2; ++i) {
        janitor_queue.push(i + 1); // Janitor IDs start from 1
      }

      event_list.push(Event(0, "arrival"));
     }
};

#endif