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

  SUBCASE("testing make_array function and delete array functioin"){
    cout << "Please input number of elements to make array: ";
    int n;
    cin >> n;
    int *arr_1 = new int(n);
    free(arr_1);
  }; //valgrind test passes here
  SUBCASE("testing parenthesis function"){
    cout << "Please input number of elements to make array: ";
    int num;
    cin >> num;
    int * new_arr = parenthesis(num);

    CHECK( non_negative_sum(new_arr, sizeof(new_arr)/sizeof(new_arr[0])) == true);

    free(new_arr);
  };

}
