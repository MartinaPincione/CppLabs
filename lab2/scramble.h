#ifndef __SCRAMBLE_H
#define __SCRAMBLE_H

void fill_with_ones(int nums[], int length);
int prefix_sum(int array[], int length);
bool non_negative_sum(int array[], int length);
//NOT NECESSARY: bool non_positive_sum(int array[], int length);
void fisher_swap(int array[], int length);
int generate_correct_fisher_loop(int array[], int length);
double testing_convergence(int array[], int length, int num_runs);

#endif

