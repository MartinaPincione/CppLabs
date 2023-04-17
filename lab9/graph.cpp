#include <fstream>

#include "graph.h"

vector<vector<int>> read_matrix(string filename){
    
    vector<vector<int>> result;

    ifstream file(filename);

    int rows, cols;

    file >> rows >> cols;


    for(int i = 0; i < rows ; i++){
        vector<int> r;
        for (int j = 0 ; j < cols ; j++){
            int num;
            file >> num;
            r.push_back(num);
        }
        result.push_back(r);
    }

    file.close();

    return result;


}

vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}


void remove_edges(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0 && abs(matrix[i][j]) != 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

vector<vector<int>> get_zero_edges(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> zeroEdges(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                zeroEdges[i][j] = 1;
            }
        }
    }

    return zeroEdges;
}

void normalize_and_divide_by2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        int countPlus1 = 0;
        int countMinus1 = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                countPlus1++;
            } else if (matrix[i][j] == -1) {
                countMinus1++;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = countPlus1 > countMinus1 ? 1 : 0;
            } else if (matrix[i][j] == -1) {
                matrix[i][j] = countMinus1 > countPlus1 ? -1 : 0;
            }
            if (matrix[i][j] != 0) {
                matrix[i][j] /= 2;
            }
        }
    }
}

vector<vector<int>> compute_reachability(const vector<vector<int>>& graph) {
    int n = graph.size();

    vector<vector<int>> m = graph;

    int logn = log2(n) + 1;

    for (int l = 2; l <= logn; l++) {
        m = matrix_multiply(m, m);
        remove_edges(m);
        normalize_and_divide_by2(m);
        vector<vector<int>> z = get_zero_edges(m);
        m = matrix_multiply(z, m);
        m = matrix_multiply(m, z);
    }

    return m;
}