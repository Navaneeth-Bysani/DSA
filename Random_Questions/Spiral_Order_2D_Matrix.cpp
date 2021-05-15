#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int T = 0, B = m-1, L = 0, R = n-1;
    int dir = 0;
    //dir = 0 right | dir = 1 bottom | dir = 2 left | dir = 3 up
    vector<int> Ans;
    if(m*n == 1) {
        Ans.push_back(A[0][0]);
        return Ans;
    }
    while(T<=B && L<=R) {
        if(dir == 0) {
            for(int j = L; j<=R; j++) {
                Ans.push_back(A[T][j]);
                cout << A[T][j] << " ";
            }
            
            T = T+1;
            // dir = (dir+1)%4;
            dir = 1;
            continue;
        }
        if(dir == 1) {
            for(int i = T; i<=B; i++) {
                Ans.push_back(A[i][R]);
                cout << A[i][R] << " ";
            }
            
            R = R-1;
            // dir = (dir+1)%4;
            dir = 2;
            continue;
        }
        if(dir == 2) {
            for(int j = R; j>=L; j--) {
                Ans.push_back(A[B][j]);
                cout << A[B][j] << " ";
            }
            
            B = B-1;
            // dir = (dir+1)%4;
            dir = 3;
            continue;
        }
        if(dir == 3) {
            for(int i = B; i>=T; i--) {
                Ans.push_back(A[i][L]);
                cout << A[i][L] << " ";
            }
            
            L = L+1;
            // dir = (dir+1)%4;
            dir = 0;
            continue;
        }
    }
    return Ans;
}

int main() {
	// your code goes here
	vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
	spiralOrder(A);
	return 0;
}
