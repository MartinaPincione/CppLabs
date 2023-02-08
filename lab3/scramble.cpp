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


int lowest_valley_index(int * arr, int length){
  int minimum = arr[0];
  int min_index = 0;
  int prefix = 0;
  for(int i = 0; i < length; i++){
    prefix += arr[i];
    if (prefix < minimum){
      minimum = prefix;
      min_index = i;
    }
  }
  return min_index;
}

void print_array(int* arr, int length){
  for (int i =0 ; i < length; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int*  parenthesis(int n){

  if (n == 0) return NULL;

  int new_size = (2 * n)+1;
  int* arr = new int[new_size];
  
  for(int i = 0; i < new_size; i++){
    arr[i] = i;
  }
  
  fill_with_ones(arr, new_size);

  fisher_swap(arr, new_size);

  while(arr[0] != 1){ //while array doesn't start with 1
    fisher_swap(arr, new_size);
  }

  print_array(arr,new_size);

  int lowest_index = lowest_valley_index(arr, new_size);
  cout << lowest_index  << endl;

  int* new_arr = new int[new_size - 1];

  int new_arr_index = 0;
  for (int i = (lowest_index + 1); i < new_size ; i++){
    //cout << arr[i] << endl;
    new_arr[new_arr_index] = arr[i];
    new_arr_index++;
  }
  for(int i = 0; i < lowest_index; i++){
    //cout << arr[i] << endl;
    new_arr[new_arr_index] = arr[i];
    new_arr_index++;
  }
  print_array(new_arr, new_size - 1);
  delete[] arr;
  return new_arr;
}

void free_array(int * arr){
  cout << "freeing array size of " << sizeof(arr)/sizeof(arr[0]) << " in free array function" << endl;
  delete arr;
}

