#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//order of sqrt(N) solution N - input integer
bool isPrime(int A) {
    if(A == 1) return 0;
    if(A == 2) return 1;
    int upperlimit = sqrt(A);
    for(int i = 2; i<=upperlimit; i++) {
        if(A%i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int A = 49;
    cout << isPrime(A) << endl;
}