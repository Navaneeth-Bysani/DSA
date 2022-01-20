#include<bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/powx-n/submissions/

void Pow(double x, int n) {
    double ans = 1;
    //why long int? because n is an integer (+ve and -ve), so if n = INT_MIN, then abs(n) will result in integer overflow
    //since INT_MIN = -2^31 and INT_MAX = 2^31-1
    long int m = abs(n);
    while(m>0) {
        if(m%2 == 0) {
            x = x*x;
            m = m/2;
        } else {
            ans = ans*x;
            m--;
        }
    }
    if(n>0)
        cout << ans << endl;
    else
        cout << 1/ans << endl;
}

int main() {
    double x = 2;
    int n = -2;

    //n can be negative or positive. We need to take care of that
    //T(n) -> O(log n)
    Pow(x,n);
    return 0;
}