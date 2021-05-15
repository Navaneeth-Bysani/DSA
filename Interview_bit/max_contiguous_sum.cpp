#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(const vector<int> &A) {
    int currSum = 0,maxSum;
    maxSum = -100000000;
    int n = A.size();
    for(int i = 0; i<n; i++) {
        currSum = currSum + A[i];
        maxSum = max(maxSum,currSum);
        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(A) << endl;
}