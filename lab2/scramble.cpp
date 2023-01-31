#include <iostream>
#include "scramble.h"
#include <cstdlib>


using namespace std;

void fill_with_ones(int nums[], int length){
  int checker = length / 2;
  
  for(int i = 0 ; i < length ; i++){
    if (i < checker) nums[i] = 1;
    else nums[i] = -1;
  }
  
}

void fisher_swap(int array[], int length){
  fill_with_ones(array, length);
  int i, j;
  for(i = 0; i < length; i++){
    j = std::rand() % (i + 1); //finding a random number between 0 and i
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

int generate_correct_fisher_loop(int nums[], int length){
  int failed = 0;
  do{
    fisher_swap(nums, length);
    failed++;
  } while(!non_negative_sum(nums, length));
  return failed;
}

double testing_convergence(int nums[], int length, int num_runs){
  double passing = 0.0, failing = 0.0;
  for (int i = 0 ; i < num_runs ; i++){
    failing += generate_correct_fisher_loop(nums, length);
    passing++;
  }
  return (double)passing / failing; 
}

