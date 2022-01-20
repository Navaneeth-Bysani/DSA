#include<iostream>
#include<vector>

using namespace std;

void print_LIS(vector<int> x, int P[], int i) {
    if(P[i] != i) {
        return print_LIS(x,P,P[i]);
    }
    cout << x[i] << " ";
}
int LIS(vector<int> x, int n) {
  int L[n];
  int P[n];
  fill_n(L,n,1);
  int LastIdxLIS = 0;

  for(int i = 0; i<n; i++) {
    P[i] = i;
  }

  int max = L[0];
  for(int i = 0; i<n; i++) {
      for(int j = i-1; j>=0; j--) {
          if(x[i] > x[j] && L[j]+1 > L[i]) {
              L[i] = L[j] + 1;
              P[i] = j;
          }
          if(L[i] > max) {
              max = L[i];
              LastIdxLIS = i;
          }
      }
  }

//   print_LIS(x,P,n);
//   cout << endl;
  return max;
}

int main() {
    int n,t;
    vector<int> x;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> t;
        x.push_back(t);
    }

    cout << "Length of longest Increasing Subsequence is: " << LIS(x,n);
}