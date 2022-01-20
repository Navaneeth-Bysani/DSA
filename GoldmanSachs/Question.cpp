#include <bits/stdc++.h>
using namespace std;
//Question - https://leetcode.com/discuss/interview-question/1407874/Goldman-Sachs-or-OA-2021-or-Jewellery-Design-or-Help

bool condition(string A, string B) {
    int n = A.length(), m = B.length();
    int count = 0;
    while(n>0 && m > 0 && A[n-1] == B[m-1]) {
        count++;
        n--;
        m--;
    }
    if(count >= max(A.length(), B.length())-1) {
        return true;
    }
    return false;
}
int LIS(vector<string> arr, int n) {
    if(n < 0) {
        return 0;
    }
    int Max = 0;
    for(int i = 0; i<n; i++) {
        if(condition(arr[n], arr[i])) {
            Max = max(Max, LIS(arr, i));
        }
    }
    
    return max(Max+1, LIS(arr, n-1));
}
void solve() {
    vector<string> arr;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << LIS(arr, n-1) << endl;
}

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0;
}
