#include <bits/stdc++.h>
using namespace std;

//Question - https://www.interviewbit.com/problems/implement-power-function/

//given x,n,d find (x^n)%d
//Keep in mind that x^n could cause an overflow
//the answer could be negative, but return positive answer at the end (if(a%b < 0) a%b + b)
//Need a better solution than O(n);


//Answer approach
// if n is even, the x^n can be written as (x*x)^n/2, we can use this logic to solve this
int main() {
    int x,n,d;
    cin >> x >> n >> d;
    long long int ans = 1, base = x;
    if(n == 0) {
        cout << 1 << endl;
        return 0;
    }
    if(x == 1) {
        cout << 1%d << endl;
        return 0;
    }
    if(d == 1) {
        cout << 0 << endl;
        return 0;
    }
    while(n > 0) {
        if(n%2 == 0) {
            base = (base*base)%d;
            n = n/2;
        } else {
            ans = (ans * base)%d;
            n--;
        }
    } 

    if(ans > 0) {
        cout << ans << endl;
    } else {
        cout << (ans + d)%d << endl;
    }
}