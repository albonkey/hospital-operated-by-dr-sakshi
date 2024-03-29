#include <iostream>
#include <vector>
#include "cleanup.h"
#include "time_generators.h"
#include "Event.h"
#include "SimulationState.h"

using namespace std;

void wait_cleanup(SimulationState& state) {
    state.event_list.push(Event(state.current_time, "start_cleanup"));
    std::cout << "End of fn 7" << std::endl;
}

void start_cleanup(SimulationState& state) {
    if (state.janitors_available > 0 && state.rooms_waiting_cleanup > 0) {
        // Decrement the count of available janitors
        state.janitors_available--;
        
        // Decrement the count of rooms currently being cleaned
        state.rooms_waiting_cleanup--;
        
        // Generate cleanup time
        double cleanup_time = generate_cleanup_time(state.mu_c);
        
        // Update cleanup times
        state.cleanup_times.push_back(cleanup_time);
        
        // Schedule an event for the end of cleanup
        state.event_list.push(Event(state.current_time + cleanup_time, "end_cleanup"));
    }

    std::cout << "End of fn 8" << std::endl;
}

void end_cleanup(SimulationState& state) {
    state.janitors_available++;
    double cleanup_time = state.cleanup_times.front(); 
    state.total_cleanup_time += cleanup_time;
    std::cout << "End of fn 9" << std::endl;
}