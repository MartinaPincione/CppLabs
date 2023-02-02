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
 
double testing_convergence(int nums[], int length, int num_runs){
  int failing = 0, passing = 0;
  for (int i =0 ; i < num_runs; i++){
    fisher_swap(nums, length);
    if (non_negative_sum(nums, length)){
      passing++;
    }
    else{
      failing++;
    }
  }
  cout << "List of length " << length << " and " << num_runs << " runs  has ";
  cout << passing << " passing lists and ";
  cout << failing << " failing lists." << endl;

  cout << "Passing: Failing of " << (double)passing/failing << endl;
  
  return (double)passing/failing; 
}

