#ifndef TIME_GENERATORS_H
#define TIME_GENERATORS_H


void initialize_generator(double seed);
double generate_interarrival_time(double lambda_val);
double generate_evaluation_time(double mu_e);
double generate_treatment_time(double priority, double mu_t);
double generate_cleanup_time(double mu_c);

#endif