#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <utility>
#include <map>
#include <cmath>

#include "cosine.h"


using namespace std;

double dot_product(vector<double> v1, vector<double> v2){

    double result = 0.0;

    for(int i = 0; i < v1.size() ; i++){

        result += (v1[i] * v2[i]);

    }
    
    return result;
}

double find_magnitude(vector<double> v){
    double result = 0.00;

    for(auto num: v){
        result += pow(num, 2);
    }

    result = sqrt(result);

    return result;
}


vector<vector<double>> read_vectors(){

    

    int num_vectors, vector_size;

    cout << "Input the number of vectors: ";
    cin >> num_vectors;

    cout << "Input the size of vectors: ";
    cin >> vector_size;

    cout << "Input vector:" << endl;

    
    vector<vector<double>> arr_vectors(num_vectors, vector<double>(vector_size));

    
    for (int i = 0; i < num_vectors; i++) {
        for (int j = 0; j < vector_size; j++) {
            cin >> arr_vectors[i][j];
        }
    }

    return arr_vectors;
}

void output_vectors(vector<vector<double>> arr_vectors){

    cout << "___________________________________________" << endl;

    for (auto v: arr_vectors){
        for (auto num: v){
            cout << num << " ";
        }
        cout << endl;
    }

}

vector<pair<double, pair<int, int>>> make_cosine_pairs(vector<vector<double>> v){


    pair<vector<double>, vector<double>> p;
    vector<pair<double, pair<int, int>>> dist;

    for (int i = 0; i < v.size() - 1; i++){
        for(int j = i + 1; j < v.size(); j++){

            //you will have vector indexed at i and the vector indexed at j
            double dot_prod = dot_product(v[i], v[j]);

            double cos_distance = acos((double)(dot_prod)/ (find_magnitude(v[i]) * find_magnitude(v[j])));

            dist.push_back(make_pair(cos_distance, make_pair(i, j)));
        }
    }

    sort(dist.begin(), dist.end());

    for (int i = 0; i < dist.size(); i++) {
        int v1 = dist[i].second.first;
        int v2 = dist[i].second.second;
        cout << "cosine similarity: " << dist[i].first << " vector" << v1 << " && vector" << v2<< endl; 
    }

    return dist;
}

/* 
int main(){

    vector<vector<double>> test = read_vectors();
    output_vectors(test);

    pair<vector<double>, vector<double>> p;
    vector<pair<double, pair<int, int>>> dist;

    for (int i = 0; i < test.size() - 1; i++){
        for(int j = i + 1; j < test.size(); j++){

            //you will have vector indexed at i and the vector indexed at j
            double dot_prod = dot_product(test[i], test[j]);

            double cos_distance = acos((double)(dot_prod)/ (find_magnitude(test[i]) * find_magnitude(test[j])));

            dist.push_back(make_pair(cos_distance, make_pair(i, j)));
        }
    }

    sort(dist.begin(), dist.end());

    for (int i = 0; i < dist.size(); i++) {
        int v1 = dist[i].second.first;
        int v2 = dist[i].second.second;
        cout << "cosine similarity: " << dist[i].first << " vector" << v1 << " && vector" << v2<< endl; 
    }




    return 0;

} */