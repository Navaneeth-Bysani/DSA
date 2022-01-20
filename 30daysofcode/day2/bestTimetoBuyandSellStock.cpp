#include <bits/stdc++.h>
using namespace std;

//Question - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int maxProfit(vector<int>& prices) {
        int Min = INT_MAX;
        int MaxProfit = 0;
        int n = prices.size();
        for(int i = 0; i<n; i++) {
            Min = min(Min, prices[i]);
            MaxProfit = max(MaxProfit, prices[i]-Min);
        }
        return MaxProfit;
}
int main() {
    vector<int> prices = {7,1,5,3,6,4};

    //Brute force solution is to traverse array and for each index chack for the maximum element on it's left side --> O(N^2) TLE
    //Better approach
    cout << maxProfit(prices) << endl;
}