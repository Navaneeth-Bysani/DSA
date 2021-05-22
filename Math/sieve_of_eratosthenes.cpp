#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> sieve(int A) {
    vector<int> primes(A+1);
    for(int i = 0; i<A+1; i++) {
        primes[i] = 1;
    }
    primes[0] = 0;
    primes[1] = 0;
    int upperlimit = sqrt(A);
    for(int i = 2; i<=upperlimit; i++) {
        if(primes[i] == 1) {
            for(int j = 2; i*j<=A; j++) {
                primes[i*j] = 0;
            }
        }
    }
    vector<int> Ans;
    for(int i = 0; i<A+1; i++) {
        if(primes[i] == 1) {
            Ans.push_back(i);
        }
    }
    return Ans;
}
int main() {
    int A = 300;
    vector<int> Ans;
    Ans = sieve(A);
    int n = Ans.size();
    for(int i = 0; i<n; i++) {
        cout << Ans[i] << " ";
    }
}