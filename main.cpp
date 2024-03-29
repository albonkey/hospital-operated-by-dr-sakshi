//
//  main.cpp
//  hw6
//
//  Created by Sakshi Singh on 2024-03-24.
//

#include "simulate.h"

int main(int argc, char *argv[]) {
    // Parse command line arguments
    double lambda_val = 5.0; // Arrival rate of patients
    double mu_e = 4.0;       // Evaluation rate
    double mu_t = 3.0;       // Treatment rate
    double mu_c = 2.0;       // Cleanup rate
    int B = 300;              // Buffer size
    int R = 5;               // Number of treatment rooms
    int m1 = 2;              // Number of initial janitors available
    int m2 = 4;              // Maximum number of janitors available
    int S = 12345;  

    // Run simulation
    simulate(lambda_val, mu_e, mu_t, mu_c, B, R, m1, m2, S);

    return 0;
}
