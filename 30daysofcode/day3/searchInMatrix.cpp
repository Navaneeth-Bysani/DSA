#include<bits/stdc++.h>
using namespace std;

void variation1() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0, r = n*m-1;
        
        while(l<=r) {
            int mid = l + (r-l)/2;
            int row = mid/m, col = mid%m;
            if(matrix[row][col] == target) {
                cout << "Found at: " << row << " " << col << endl;
                return;
            } else if(matrix[row][col] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        cout << "element not found" << endl;
}


void variation2() {
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 29;
    int n = matrix.size(), m = matrix[0].size();

    int i = 0, j = m-1;
    while(i<n && j>=0) {
        if(matrix[i][j] == target) {
            cout << "Found at: " << i << " " << j;
            return;
        }
        if(matrix[i][j] > target) {
            j--;
        } else {
            i++;
        }
    }

    cout << "Couldn't find the element" << endl;
}

int main() {
    //Two variations of problem

    //Variation 1 - https://leetcode.com/problems/search-a-2d-matrix/submissions/
    //This is very easy as we need to use regular binary search only, but change it a bit so that we can use the algo to search in a matrix
    //O(log n*m)
    variation1();

    //Variation 2 - https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/
    //This is a bit tricky question
    variation2();
}