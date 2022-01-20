#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/rotate-image/

void printMatrix(vector<vector<int>> matrix) {
    for(auto v: matrix) {
        for(auto c :v) {
            cout << c << " ";
        }
        cout << endl;
    }
}
void rotate1(vector<vector<int>> matrix) {
        int n = matrix.size();
        vector<vector<int>> ans = matrix;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                ans[j][n-i-1] = matrix[i][j];
            }
        }
        
        matrix = ans;
        printMatrix(matrix);
}

void rotate2(vector<vector<int>> matrix) {
    int n = matrix.size();
    //Find transpose : The following is the method to find transpose
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //Reverse each row   
    for(int i = 0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    cout << "Optimised" << endl;
    printMatrix(matrix);
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    //Brute force --> Copy elements in required order into new matrix -> O(N^2) time and space
    rotate1(matrix);

    //Better space optimised --> O(N^2)
    rotate2(matrix);
}