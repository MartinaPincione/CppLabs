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
        CHECK( find_magnitude(v1) == doctest::Approx(7.71557));

        vector<double> v2 = {0.0, 3.3, 6.23};
        cout << find_magnitude(v2) << endl;
        CHECK( find_magnitude(v2) == doctest::Approx(7.05003));

    };

    SUBCASE("testing dot product function"){

        vector<double> v1 = {2.1, 3.4, 6.6};
        vector<double> v2 = {0.0, 3.3, 6.23};
        cout << dot_product(v1, v2) << endl;
        CHECK( dot_product(v1, v2) ==  52.338);

        v1 = {1, 2};
        v2 = {3, 4};
        CHECK( dot_product(v1, v2) ==  doctest::Approx(11));


    };

    SUBCASE("testing cosine distance function"){

        vector<vector<double>> test2 = {{0.1, 0.2, -0.3, 0.4}, {0.5, 0.6, 0.7, 0.8},{9.9, 2.3, 99.9, 45}};


        vector<pair<double, pair<int, int>>> dist = make_cosine_pairs(test2);
        vector<double> expected_results = {0.686597,1.17283, 1.74624};

        for (int i = 0; i < dist.size(); i++) {
            int temp_res = dist[i].first == expected_results[i];
            CHECK( temp_res == 0); 
        }

        vector<vector<double>> test3 = {{4.0, 5.1}, {3.2, 1.1}};


        vector<pair<double, pair<int, int>>> dist3 = make_cosine_pairs(test3);
        vector<double> expected_results3 = {0.574597};

        for (int i = 0; i < dist.size(); i++) {
            int temp_res = dist[i].first == expected_results[i];
            CHECK( temp_res == 0); 
        }


        vector<vector<double>> test4 = {{2.1, 3.4, 6.6}, {0.0, 3.3, 6.23}};
        vector<pair<double, pair<int, int>>> dist4 = make_cosine_pairs(test4);

        double result4 = dist4[0].first;
        CHECK( result4 == doctest::Approx(0.275885));
        
        




        int choice;
        cout << "Would you like to test your own values? 0 (yes) or 1 (no): ";
        cin >> choice;
        if (choice){
            vector<vector<double>> test = read_vectors();
            vector<pair<double, pair<int, int>>> dist2 = make_cosine_pairs(test);

            double res;
            vector<double> expected;
            cout << "Input your expected results until EOF: ";
            while(cin >> res){
                expected.push_back(res);
            }

            for (int i = 0; i < dist2.size(); i++) {
                int temp_res = dist2[i].first == expected[i];
                CHECK( temp_res == 0); 
            }    
        }
    };
}
