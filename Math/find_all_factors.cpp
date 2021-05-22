#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//program to find all factors
vector<int> find_all_factors(int A) {
    vector<int> Ans;
    if(A < 2) {
        Ans.push_back(A);
        return Ans;
    }
    int upperlimit = sqrt(A);
    for(int i = 1; i<=upperlimit; i++) {
        if(A%i==0) {
            Ans.push_back(i);
            if(i != A/i) {
                Ans.push_back(A/i);
            }
        }
    }
    sort(Ans.begin(),Ans.end());
    return Ans;
}

int main() {
    int A = 41443;
    vector<int> Ans;
    Ans = find_all_factors(A);
    int n = Ans.size();
    for(int i = 0; i<n; i++) {
        cout << Ans[i] << " ";
    }
}