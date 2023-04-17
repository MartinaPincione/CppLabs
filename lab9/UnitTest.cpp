#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "graph.h"

using namespace std;

vector<vector<int>> m1 = read_matrix("matrix1.txt");
vector<vector<int>> expected_m1 = {{0, 0, 1}, {0, 0, 1}, {1, 0, 0}};
vector<vector<int>> copy1 = read_matrix("matrix1.txt");


vector<vector<int>> m2 = read_matrix("matrix2.txt");
vector<vector<int>> expected_m2 = {{1, 2, 3, 4},{0, 1, 3, 4},{0, 2, 4, 3},{1, 1, 1, 1}};
vector<vector<int>> copy2 = read_matrix("matrix2.txt");

TEST_CASE("matrix reading"){

    SUBCASE("matrix 1"){

        CHECK(m1.size() == 3);
        CHECK(m1[0].size() == 3);

        for(int i = 0 ; i < m1.size(); i++){
            for(int j = 0; j < m1[1].size(); j++){
                CHECK(m1[i][j] == expected_m1[i][j]);
            }
        }
    };

    SUBCASE("matrix 2"){

        CHECK(m2.size() == 4);
        CHECK(m2[0].size() == 4);

        for(int i = 0 ; i < m2.size(); i++){
            for(int j = 0; j < m2[0].size(); j++){
                CHECK(m2[i][j] == expected_m2[i][j]);
            }
        }

    };



}

vector<vector<int>> expected_mult = {{5, 14, 25, 25}, {4, 11, 19, 17}, {3, 13, 25, 23}, {2, 6, 11, 12}};


TEST_CASE("matrix multiplication"){

    SUBCASE("matrix 1"){
        vector<vector<int>> id_m1 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        vector<vector<int>> res_m1 = matrix_multiply(m1, id_m1);
        for(int i = 0 ; i < res_m1.size(); i++){
            for(int j = 0; j < res_m1[1].size(); j++){
                CHECK(res_m1[i][j] == expected_m1[i][j]);
            }
        }
    };

    SUBCASE("matrix 2"){
        vector<vector<int>> res_m2 = matrix_multiply(m2, m2);
        for(int i = 0 ; i < res_m2.size(); i++){
            for(int j = 0; j < res_m2[1].size(); j++){
                CHECK(res_m2[i][j] == expected_mult[i][j]);
            }
        }
    };

    SUBCASE("handling incompatible matrices"){
        vector<vector<int>> res = matrix_multiply(m1, m2);
        CHECK(res.size() == 0);
    };
}

TEST_CASE("matrix remove +/- 1 edges"){

    SUBCASE("matrix 1"){
        remove_edges(m1);
        for(int i = 0 ; i < m1.size(); i++){
            for(int j = 0; j < m1[1].size(); j++){
                CHECK(m1[i][j] == 0);
            }
        }
    };

    SUBCASE("matrix 2"){
        vector<vector<int>> test = matrix_multiply(m2, m2);
        remove_edges(test);

        for(int i = 0 ; i < test.size(); i++){
            for(int j = 0; j < test[1].size(); j++){
                CHECK(test[i][j] == expected_mult[i][j]);
            }
        }
    };



}


TEST_CASE("matrix normalize and divide by two"){

    SUBCASE("matrix 1"){
        normalize_and_divide_by2(m1);
        for(int i = 0 ; i < m1.size(); i++){
            for(int j = 0; j < m1[1].size(); j++){
                CHECK(m1[i][j] == 0);
            }
        }
    };

    SUBCASE("matrix 2"){

    };
}

TEST_CASE("matrix compute reachability"){

    SUBCASE("matrix 1"){
        vector<vector<int>> result_m1 = compute_reachability(copy1);
        for(int i = 0 ; i < result_m1.size(); i++){
            for(int j = 0; j < result_m1[1].size(); j++){
                CHECK(result_m1[i][j] == 0);
            }
        }
    };
}