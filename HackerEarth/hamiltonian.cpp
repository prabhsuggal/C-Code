#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

void print(vector<vector<int>> arr, string name){
    cout << name << ":\n";
    for(auto a : arr){
        for(auto x : a){
            cout << std::hex << x << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n,m;
#define MAX_PERM (1<<n)
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>(n, -1));

    int x,y, cost;
    for(int i=0; i<m; i++){
        cin >> x >> y >> cost;
        adj[x-1][y-1] = cost;
        adj[y-1][x-1] = cost;
    }

    vector<vector<int> > dp(n, vector<int>(MAX_PERM, INT_MAX));
    for(int i=0; i<n; i++){
        dp[i][(1<<i)] = 0;
    }

    for(int perm=1; perm<MAX_PERM; perm++){
        for(int i=0; i<n; i++){
            if(!(perm & (1<<i)))continue;
            for(int j=0; j<n; j++){
                if((i==j) || !(perm & (1<<j)))continue;
                if(adj[i][j] == -1)continue;
                if(dp[j][perm ^ (1<<i)] == INT_MAX)continue;
                dp[i][perm] = min(dp[i][perm], dp[j][perm ^ (1<<i)] + adj[i][j]);
            }
        }
    }

    print(dp, "DP");

    int min_cost = dp[0][MAX_PERM-1];
    for(int i=1; i<n; i++){
        min_cost = min(dp[i][MAX_PERM-1], min_cost);
    }
    cout << min_cost << "\n";

    return 0;
}
