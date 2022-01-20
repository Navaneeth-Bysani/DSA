#include <bits/stdc++.h>
using namespace std;

void method1(vector<int> Arr) {
    int n = Arr.size();
    int power_set_size = pow(2,n);
    for(int i = 0; i<power_set_size; i++) {
        int x = i;
        int bit = 0;
        while(x > 0) {
            if(x%2 == 1) {
                cout << Arr[bit] << " ";
            }
            x = x/2;
            bit++;
        }
        cout << endl;
    }
}
int main() {
    vector<int> Arr = {5,1,6};

    //method1, this takes exponential time
    method1(Arr);
}