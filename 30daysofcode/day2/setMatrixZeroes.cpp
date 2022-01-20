#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/set-matrix-zeroes/

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int el : row) {
            cout << el << " ";
        }
        cout << endl;
    }
}

void setZeroes(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool isCol = false;
        
        for(int i = 0; i<n; i++) {
            if(matrix[i][0] == 0) {
                isCol = true;
            }
            for(int j = 1; j<m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<n; i++) {
            for(int j = 1; j<m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0) {
            for(int i = 0; i<m; i++) {
                matrix[0][i] = 0;
            }
        }
        if(isCol) {
            for(int i = 0; i<n; i++) {
                matrix[i][0] = 0;
            }
        }

        printMatrix(matrix);
}


int main() {
    vector<vector<int>> A = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(A);

}


//trees, stack - google
//maths, backtracking, dp - DE Shaw