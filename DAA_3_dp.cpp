#include<bits/stdc++.h>
using namespace std;

int knapsack(int cap, const vector<int>&weights, const vector<int>&values, int n){
    // Initialize the dp array
    vector<vector<int>>dp(n+1, vector<int>(cap+1, 0));
    
    // Build the dp
    for(int i = 1; i <= n; i++){
        for(int w = 1; w <= cap; w++){
            if(weights[i-1] <= w){
                dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]]);
            }else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][cap];
}

int main() {
    int n = 4;
    int capacity = 8;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {1, 2, 5, 6};

    int max_value = knapsack(capacity, weights, values, n);

    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}