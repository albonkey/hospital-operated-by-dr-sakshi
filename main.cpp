//
//  main.cpp
//  hw6
//
//  Created by Sakshi Singh on 2024-03-24.
//

#include "simulate.h"

int main(int argc, char *argv[]) {
    // Parse command line arguments
    double lambda_val = 0.01; // Arrival rate of patients
    double mu_e = 0.1;       // Evaluation rate
    double mu_t = 0.1;       // Treatment rate
    double mu_c = 0.5;       // Cleanup rate
    int B = 1;              // Buffer size
    int R = 1;               // Number of treatment rooms
    int m1 = 1;              // Number of initial janitors available
    int m2 = 1;              // Maximum number of janitors available
    int S = 167;  

    // Run simulation
    simulate(lambda_val, mu_e, mu_t, mu_c, B, R, m1, m2, S);

    return 0;
}
