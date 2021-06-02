#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Question - https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
//Application of Binary Search
void matrix_median(vector<vector<int>> &matrix, int r, int c) {
    int Min = matrix[0][0], Max = matrix[0][c-1];
    for(int i = 1; i<r; i++) {
        Max = max(Max,matrix[i][c-1]);
        Min = min(Min,matrix[i][0]);
    }
    int l = Min, h = Max;
    int required = (r*c+1)/2;
    int mid;
    while(l<h) {
        int count = 0;
        mid = l + (h-l)/2;
        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(matrix[i][j] <= mid) {
                    count++;
                }
            }
        }
        if(count < required) {
            l = mid+1;
        } else {
            h = mid;
        }
    }
    cout << "Median is: " << l << endl;
}
int main() {
    vector<vector<int>> matrix;
    matrix = {{1,3,5},{2,6,9}, {3,6,9}};
    // matrix = {{5,17,100}};
    int r = matrix.size();
    int c = matrix[0].size();
    matrix_median(matrix, r, c);
}