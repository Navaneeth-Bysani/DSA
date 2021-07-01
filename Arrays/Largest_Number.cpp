#include <bits/stdc++.h>
using namespace std;

//Find the largest number formed with the numbers in the array. For example the answer to the given array is 9534330
//Question - https://www.interviewbit.com/problems/largest-number/

bool Cmpr(string A,  string B) {
    return (A+B > B+A);
}
int main() {
    vector<int> A = {3,30,34,5,9};
    int n = A.size();

    vector<string> S;
    for(int i = 0; i<n; i++) {
        S.push_back(to_string(A[i]));
    }

    sort(S.begin(), S.end(), Cmpr);
    string X = "";
    for(int i = 0; i<n; i++) {
        X += S[i];
    }

    cout << "Largest number that can be formed using these numbers is: " << X << endl;
}