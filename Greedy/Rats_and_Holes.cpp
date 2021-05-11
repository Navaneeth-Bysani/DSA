#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void solve() {
    int Nh, Nr;
    cin >> Nh >> Nr;
    int Rats[Nr], Holes[Nh];
    for(int i = 0; i<Nh; i++) {
        cin >> Holes[i];
    }
    for(int i = 0; i<Nr; i++) {
        cin >> Rats[i];
    }
    sort(Holes,Holes+Nh);
    sort(Rats,Rats+Nr);

    int Max = abs(Holes[0] - Rats[0]);
    for(int i = 1; i<Nr && i<Nh; i++) {
        Max = max(Max,abs(Holes[i]-Rats[i]));
    }

    cout << "Maximum Time Taken: " << Max << endl;
}
int main() {
    solve();
}

//Question
// •Given Rat[] and Hole[] arrays each of size n that give the positions of rats and holes respectively on a horizontal straight line.
// •Each hole can accommodate at most one rat.
// •To move from position ito position j, the time needed = |i–j|.
// •Objective: To minimize the maximum time for a rat to move to its hole.