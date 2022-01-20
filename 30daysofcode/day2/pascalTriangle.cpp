#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/pascals-triangle/solution/
void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int el : row) {
            cout << el << " ";
        }
        cout << endl;
    }
}

void printPascal(int numRows) {
    vector<vector<int>> ans;
        for(int i = 1; i<=numRows; i++) {
            ans.push_back({});
            for(int j = 1; j<=i; j++) {
                if(j == 1 || j == i) {
                    ans[i-1].push_back(1);
                } else {
                    ans[i-1].push_back(ans[i-2][j-2]+ans[i-2][j-1]);
                }
            }
        }
        
    printMatrix(ans);
}

int main() {
    int numRows = 5;
    //The given question can be solved as follows T(n) --> O(numRows^2)
    printPascal(numRows);

    //If we are asked to find one particular element by giving row and col, eg : 5th row and 3rd column, for numRows = 5, it would
    //be 6, we can return (r-1)C(c-1) (combinatorics). i.e.... r and c are row number and column number (1-indexed)

    //If we are asked to print an only entire row of the Pascal Triangle, then we can use the above formula for all the elements
    //but that would increase time complexity to caluclate each time
    //So, we can use, (r-1)C(c-1)/(r-1)C(c) value
}