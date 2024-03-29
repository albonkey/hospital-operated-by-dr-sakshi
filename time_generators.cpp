#include <vector>
#include <random>
#include <cmath>
#include "time_generators.h"

using namespace std;

default_random_engine generator;

void initialize_generator(double seed) {
    generator.seed(seed);
}

double generate_interarrival_time(double lambda_val) {
    exponential_distribution<double> distribution(1/lambda_val);
    return distribution(generator);
}

double generate_evaluation_time(double mu_e) {
    exponential_distribution<double> distribution(1 / mu_e);
    return distribution(generator);
}

double generate_treatment_time(double priority, double mu_t) {
    double mu = priority > 0.5 ? mu_t : mu_t * 2;
    exponential_distribution<double> distribution(1 / mu);
    return distribution(generator);
}

double generate_cleanup_time(double mu_c) {
    const double cleanup_time = 1 / mu_c;
    return cleanup_time;
}