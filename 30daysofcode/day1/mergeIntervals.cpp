#include <bits/stdc++.h>
using namespace std;


//Question - https://leetcode.com/problems/merge-intervals/

void method1(vector<vector<int>> A) {
    sort(A.begin(), A.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });
    int n = A.size();
    
    int start = A[0][0];
    int end = A[0][1];
    vector<vector<int>> Ans;
    
    for(int i = 1; i<n; i++) {
        if(A[i][0] <= end) {
            end = max(end, A[i][1]);
        } else {
            Ans.push_back({start, end});
            start = A[i][0];
            end = A[i][1];
        }
    }

    Ans.push_back({start, end});

    for(auto a : Ans) {
        cout << a[0] << " " << a[1] << endl;
    }
    return;
}

int main() {
    vector<vector<int>> A = {{1,3},{2,6},{8,10},{8,9},{9,11},{15,18},{2,4},{16,17}};
    //In method1 we sort the array in non-decreasing order of start values. Then iterate linearly by keeping track of all the mergeable 
    // points
    method1(A);
}