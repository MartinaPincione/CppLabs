#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "doctest.h"
#include "cosine.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <utility>
#include <map>

TEST_CASE("testing individual function"){

    SUBCASE("testing magnitude function"){

        
        vector<double> v1 = {2.1, 3.4, 6.6};
        cout << find_magnitude(v1) << endl;
        int res1 = find_magnitude(v1) == 7.71557;
        CHECK( res1 == 0);

        vector<double> v2 = {0.0, 3.3, 6.23};
        int res2 = find_magnitude(v2) == 7.05003;
        CHECK( res2 == 0);

    };

    SUBCASE("testing dot product function"){

        vector<double> v1 = {2.1, 3.4, 6.6};
        vector<double> v2 = {0.0, 3.3, 6.23};
        CHECK( dot_product(v1, v2) ==  52.338);

        v1 = {1, 2};
        v2 = {3, 4};
        CHECK( (double)dot_product(v1, v2) ==  (double)11);


    };

    SUBCASE("testing cosine distance function"){

        cout << "Input the following vectors: " << endl;
        cout << "0.1 0.2 -0.3 0.4" << endl;
        cout << "0.5 0.6 0.7 0.8" << endl;
        cout << "9.9 2.3 99.9 45" << endl;
        vector<vector<double>> test = read_vectors();


        vector<pair<double, pair<int, int>>> dist = make_cosine_pairs(test);
        vector<double> expected_results = {0.686597,1.17283, 1.74624};

        for (int i = 0; i < dist.size(); i++) {
            int temp_res = dist[i].first == expected_results[i];
            CHECK( temp_res == 0); 
    }

    };
}
