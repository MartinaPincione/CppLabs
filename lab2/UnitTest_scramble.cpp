#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "scramble.h"


using namespace std;


int nums[] = {4, 2};
int nums_1[] = {2, 4, 6, 7, 8, 5};
int nums_2[] = {0, 1, 2, 3, 9, 9, 9, 9};
int nums_3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int nums_4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

bool check_if_equal(int arr1[], int arr2[], int length){
  for(int i = 0 ; i < length; i++){
    if (arr1[i] != arr2[i]) return false;
  }
  return true;
}



TEST_CASE("testing lab 2"){
  SUBCASE("testing fisher yates not equal to original"){
    int copy[] = {4, 2};
    fisher_swap(copy, sizeof(copy)/sizeof(copy[0]));
    int copy_1[] = {2, 4, 6, 7, 8, 5};
    fisher_swap(copy_1, sizeof(copy_1)/sizeof(copy_1[0]));
    int copy_2[] = {0, 1, 2, 3, 9, 9, 9, 9};
    fisher_swap(copy_2, sizeof(copy_2)/sizeof(copy_2[0]));
    int copy_3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fisher_swap(copy_3, sizeof(copy_3)/sizeof(copy_3[0]));
    int copy_4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7,8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fisher_swap(copy_4, sizeof(copy_4)/sizeof(copy_4[0]));
    CHECK( check_if_equal(copy_1, nums_1, sizeof(copy_1)/sizeof(copy_1[0])) == false);
    CHECK( check_if_equal(copy_2, nums_2, sizeof(copy_2)/sizeof(copy_2[0])) == false);
    CHECK( check_if_equal(copy_3, nums_3, sizeof(copy_3)/sizeof(copy_3[0])) == false);
    CHECK( check_if_equal(copy, nums, sizeof(copy)/sizeof(copy[0])) == false);
    CHECK( check_if_equal(copy_4, nums_4, sizeof(copy_4)/sizeof(copy_4[0]))== false);
};
  SUBCASE("testing 7000"){
    double testing_1 = testing_convergence(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), 7000);
    double testing_2 = testing_convergence(nums_2, sizeof(nums_2)/sizeof(nums_2[0]), 7000);
    double testing_3 = testing_convergence(nums_3, sizeof(nums_3)/sizeof(nums_3[0]), 7000);
    double testing_4 = testing_convergence(nums_4, sizeof(nums_4)/sizeof(nums_4[0]), 7000);
    
    CHECK((testing_1 > testing_2) == true);
    CHECK((testing_2 > testing_3) == true);
    CHECK((testing_3 > testing_4) == true);
    };

  SUBCASE("testing 28000"){
    double testing_1 = testing_convergence(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), 28000);
    double testing_2 = testing_convergence(nums_2, sizeof(nums_2)/sizeof(nums_2[0]), 28000);
    double testing_3 = testing_convergence(nums_3, sizeof(nums_3)/sizeof(nums_3[0]), 28000);
    double testing_4 = testing_convergence(nums_4, sizeof(nums_4)/sizeof(nums_4[0]), 28000);


    CHECK((testing_1 > testing_2) == true);
    CHECK((testing_2 > testing_3) == true);
    CHECK((testing_3 > testing_4) == true);


    };

SUBCASE("testing 700000"){
    double testing_1 = testing_convergence(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), 700000);
    double testing_2 = testing_convergence(nums_2, sizeof(nums_2)/sizeof(nums_2[0]), 700000);
    double testing_3 = testing_convergence(nums_3, sizeof(nums_3)/sizeof(nums_3[0]), 700000);
    double testing_4 = testing_convergence(nums_4, sizeof(nums_4)/sizeof(nums_4[0]), 700000);


    CHECK((testing_1 > testing_2) == true);
    CHECK((testing_2 > testing_3) == true);
    CHECK((testing_3 > testing_4) == true);


  };
}
