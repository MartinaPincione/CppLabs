#ifndef __COSINE_H_
#define __COSINE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <utility>
#include <map>


using namespace std;

double find_magnitude(vector<double> v);

double dot_product(vector<double> v1, vector<double> v2);

vector<vector<double>> read_vectors();

double compute_cosine_distance(vector<double> v1, vector<double> v2);

void output_vectors(vector<vector<double>> arr_vectors);

vector<pair<double, pair<int, int>>> make_cosine_pairs(vector<vector<double>> v);

#endif