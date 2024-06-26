#include "evaluation.h" // Include the header file where you'll declare any necessary functions or variables
#include "SimulationState.h"
#include "time_generators.h"

void start_evaluation(SimulationState& state) {
    // If there are patients in the emergency queue
    if (!state.evaluation_queue.empty()) {
        // Get the next patient from the emergency queue
        Patient patient = state.evaluation_queue.front();
        double evaluation_time = generate_evaluation_time(state.mu_e);
        state.total_response_time += evaluation_time;
        
        // Generate priority for the patient
        double priority = ((double) rand() / RAND_MAX);  // Assuming uniform distribution
        // Update patient's priority
        patient.priority = priority;

        // Schedule arrival at P queue event
        state.event_list.push(Event(state.current_time + evaluation_time, "depart_from_E_queue", patient));
    }
    std::cout << "End of fn 2" << std::endl;
}