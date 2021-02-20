#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

#define INF (INT_MAX/2)

bool comp(const vector<int> &a, const vector<int> &b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

void print(vector<vector<int> > &arr, string name){
    cout << name << ":\n";
    for(auto &a : arr){
        for(int i : a){
            cout << std::setfill(' ') << std::setw(10) << i << " ";
        }
        cout << "\n";
    }

}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    //ofstream cout("output.txt");
#endif

    int w, s;
    vector<vector<int> > turtleStack;
    while(cin >> w >> s){
        turtleStack.push_back({w,s});
    }

    int n = turtleStack.size();
    sort(turtleStack.begin(), turtleStack.end(), comp);

    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

    for(int i=1; i<=n; i++){
        dp[i][0] = INF;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = dp[i][j-1];
            if(turtleStack[j-1][0] + dp[i-1][j-1] <= turtleStack[j-1][1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + turtleStack[j-1][0]);
            // cout << "idx: " << j << " height:" << i << " weight[idx]: " << turtleStack[j-1][0]
            //          << " strength[idx]: " << turtleStack[j-1][1] << "\n";
            // print(dp, "weight_arr");
        }
    }

    for(int i=1; i<=n; i++){
        if(dp[i][n] >= INF){
            cout << i-1 << "\n";
            break;
        }
    }

    return 0;
}
