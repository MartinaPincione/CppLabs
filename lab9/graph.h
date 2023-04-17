#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> read_matrix(string filename);


vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B);


void remove_edges(vector<vector<int>>& matrix);

vector<vector<int>> get_zero_edges(const vector<vector<int>>& matrix);


void normalize_and_divide_by2(vector<vector<int>>& matrix);


vector<vector<int>> compute_reachability(const vector<vector<int>>& graph);

#endif