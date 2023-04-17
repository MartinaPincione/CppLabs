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
    
    try {
        int n = A.size();
        vector<vector<int>> result(n, vector<int>(n, 0));
        if (A[0].size() != B.size()) throw int(0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return result;
    } catch (int i){
        cout << "matrix were not compatible for multiplication" << endl;
        return {};
    }    
}


void remove_edges(vector<vector<int>>& m) {
    int n = m.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(m[i][j]) == 1) {
                m[i][j] = 0;
            }
        }
    }
}

vector<vector<int>> get_zero_edges(const vector<vector<int>>& m) {
    int n = m.size();
    vector<vector<int>> zeroEdges(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == 0) {
                zeroEdges[i][j] = 1;
            }
        }
    }

    return zeroEdges;
}

void normalize_and_divide_by2(vector<vector<int>>& m) {
    int n = m.size();
    int x = m[0].size();
    int rowSum;
    for (int i = 0; i < n; i++) {
        rowSum = 0;
        for (int j = 0; j < x; j++) {
            rowSum += m[i][j];
        }
        if (rowSum > 0) {
            for (int j = 0; j < x; j++) {
                m[i][j] /= (2 * rowSum);
            }
        }
        if (rowSum == 0) {
            for (int j = 0; j < x; j++) {
                m[i][j] = 0;
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