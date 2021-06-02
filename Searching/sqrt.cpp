#include <iostream>
using namespace std;

// Program to find the sqrt of a number using binary search approach in O(logN)
int main() {
    int A;
    cout << "Enter the number to find it's sqrt: ";
    cin >> A;
    int l = 0, h = A, mid, ans;
    while(l<=h) {
        mid = l + (h-l)/2;
        if(mid <= A/mid) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    cout << "Sqrt is: " << ans;
    return ans;
}