#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "scramble.h"

using namespace std;


bool check_if_equal(int arr1[], int arr2[], int length){
  for(int i = 0 ; i < length; i++){
    if (arr1[i] != arr2[i]) return false;
  }
  return true;
}


TEST_CASE("testing balancing parenthesis"){

  SUBCASE("testing n = 0"){
    int num = 0;
    int * new_arr = parenthesis(num);
    CHECK( new_arr == NULL);
    free( new_arr);
  };
  
  SUBCASE("testing lowest index"){
    int nums[] = {1, -1, 1, 1, -1, -1, -1, 1, -1};
    int res = lowest_valley_index(nums, sizeof(nums)/sizeof(nums[0]));
    CHECK( res == 6);
    int nums_2[] = {1, -1, -1, 1, -1};
    int res_2 = lowest_valley_index(nums_2, sizeof(nums_2)/sizeof(nums_2[0]));
    CHECK( res_2 == 2);
    int nums_3[] = {-1, 1, -1, 1, -1};
    int res_3 = lowest_valley_index(nums_3, sizeof(nums_3)/sizeof(nums_3[0]));
    CHECK( res_3 == 0);
  };
  
  
  SUBCASE("testing parenthesis function"){


    cout << "Please input number of elements to make array: ";
    int num;
    cin >> num;
    int * new_arr = parenthesis(num);
    //print_array(new_arr, sizeof(new_arr)/sizeof(new_arr[0]));
    CHECK( non_negative_sum(new_arr, sizeof(new_arr)/sizeof(new_arr[0])) == true);
    free(new_arr);


    cout << "Please input number of elements to make array: ";
    int num_2;
    cin >> num_2;
    int * new_arr_2 = parenthesis(num_2);
    //print_array(new_arr_2, sizeof(new_arr_2)/sizeof(new_arr_2[0]));
    CHECK( non_negative_sum(new_arr_2, sizeof(new_arr_2)/sizeof(new_arr_2[0])) == true);
    free(new_arr_2);


    cout << "Please input number of elements to make array: ";
    int num_3;
    cin >> num_3;
    int * new_arr_3 = parenthesis(num_3);
    //print_array(new_arr_3, sizeof(new_arr_3)/sizeof(new_arr_3[0]));
    CHECK( non_negative_sum(new_arr_3, sizeof(new_arr_3)/sizeof(new_arr_3[0])) == true);
    free(new_arr_3);

    
  };
  
}
