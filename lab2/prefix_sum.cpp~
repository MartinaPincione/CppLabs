#include <iostream>
#include "prefix_sum.h"


using namespace std;


int prefix_sum(int array[], int length) {

    int sum = 0;
    for(int i =0; i < length; i++){
      sum += array[i];
    }
    return sum;
  }

bool non_negative_sum(int array[], int length){
    bool is_non_negative = true;

    if (length == 1 && array[0] < 0) return is_non_negative = false;

    
    for(int i = 0 ; i < length ; i++){
      int sum = prefix_sum(array, i);
      if( sum < 0) {
	return is_non_negative = false;
      }
    }
    return is_non_negative;
}

bool non_positive_sum(int array[], int length){
  bool is_not_positive = true;

  if (length == 1 && array[0] > 0) return is_not_positive = false;
 
  for (int i = 0 ; i < length ; i++){
    int sum = prefix_sum(array, i);
    if (sum > 0){
      return is_not_positive = false;
    }
  }
  return is_not_positive;
}
