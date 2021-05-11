#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int K;
    cin >> K;
    int N = S.length();
    vector<int> Cats, Rats;
    for(int i = 0; i<N; i++) {
        if(S[i] == 'C') {
            Cats.push_back(i);
        } else {
            Rats.push_back(i);
        }
    }

    int r = 0, c = 0, count = 0;
    while(r < Rats.size() && c < Cats.size()) {
        if(abs(Cats[c]-Rats[r]) <= K) {
            count++;
            c++;
            r++;
        } else if (Cats[c] - Rats[r] > K) {
            r++;
        } else {
            c++;
        }
    }
    cout << count << endl;
}
int main() {
    solve();
}

//Question
// Given an array A of n characters, where each character is a ‘C’ (cat) or a ‘R’ (rat). A cat can catch at most one rat. 
// A cat can not catch a rat if the rat is more than k units away from the cat. Find out the maximum number of rats that can be 
// caught by the cats.