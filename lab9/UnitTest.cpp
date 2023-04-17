#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "graph.h"

using namespace std;

vector<vector<int>> m1 = read_matrix("matrix1.txt");
vector<vector<int>> copy1 = read_matrix("matrix1.txt");

TEST_CASE("matrix 1 testing"){

    CHECK(m1.size() == 3);
    CHECK(m1[0].size() == 3);

    

}