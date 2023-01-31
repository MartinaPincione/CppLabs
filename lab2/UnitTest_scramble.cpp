#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "scramble.h"
using namespace std;
int nums_1[] = {2, 4, 6, 7, 8, 5};
int nums_2[] = {0, 1, 2, 3, 9, 9, 9, 9};
int nums_3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};





TEST_CASE("testing lab 2"){
  SUBCASE("testing nums_1"){
    double testing_7000 = testing_convergence(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), 7000);
    double testing_14000 = testing_convergence(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), 14000);
    CHECK((testing_7000 > testing_14000) == true);
    cout << endl;
    cout << "Ratio of passing/failing when running algorithm 7000 times on array of size " << sizeof(nums_1)/sizeof(nums_1[0]) << " is "  << testing_7000 << endl;


    cout << endl;
    cout << "Ratio of passing/failing when running algorithm 14000 times on array of size " << sizeof(nums_1)/size\
of(nums_1[0]) << " is "  << testing_14000 << endl;
  };
  
  SUBCASE("testing nums_2"){
    double testing_7000 = testing_convergence(nums_2, sizeof(nums_2)/sizeof(nums_2[0]), 7000);
    double testing_28000 = testing_convergence(nums_2, sizeof(nums_2)/sizeof(nums_2[0]), 28000);
    CHECK((testing_7000 > testing_28000) == true);

    cout << endl;
    cout << "Ratio of passing/failing when running algorithm 7000 times on array of size " << sizeof(nums_2)/size\
of(nums_2[0]) << " is "  << testing_7000 << endl;


    cout << endl;
    cout << "Ratio of passing/failing when running algorithm 28000 times on array of size " << sizeof(nums_2)/siz\
e\
of(nums_2[0]) << " is "  << testing_28000 << endl;
    
  };

  SUBCASE("testing nums_3"){
    double testing_7000 = testing_convergence(nums_3, sizeof(nums_3)/sizeof(nums_3[0]), 7000);
    double testing_28000 = testing_convergence(nums_3, sizeof(nums_3)/sizeof(nums_3[0]), 28000\
);
    CHECK((testing_7000 > testing_28000) == true);

    cout << endl;
    cout << "Ratio of passing/failing when running algorithm 7000 times on array of size " << sizeof(nums_3)/size\
of(nums_3[0]) << " is "  << testing_7000 << endl;


    cout << endl;
    cout << "Ratio of passing/failing when running algorithm 28000 times on array of size " << sizeof(nums_3)/siz\
e\
of(nums_3[0]) << " is "  << testing_28000 << endl;
    
  };
}
