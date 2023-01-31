#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "scramble.h"
using namespace std;
int nums_1[] = {2, 4, 6, 7, 8, 5};
int nums_2[] = {0, 1, 2, 3, 9, 9, 9, 9};

TEST_CASE("testing lab 2"){
  SUBCASE("testing nums_1"){
    double testing_7000 = testing_convergence(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), 7000);
    double testing_14000 = testing_convergence(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), 14000);
    CHECK((testing_7000 > testing_14000) == true);
  };
  
  SUBCASE("testing nums_2"){
    double testing_7000 = testing_convergence(nums_2, sizeof(nums_2)/sizeof(nums_2[0]), 7000);
    double testing_28000 = testing_convergence(nums_2, sizeof(nums_2)/sizeof(nums_2[0]), 28000);
    CHECK((testing_7000 > testing_28000) == true);
  };
}
