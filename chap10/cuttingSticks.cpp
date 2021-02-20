#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

void print(vector<int> &a, string name){
    cout << name << ":\n";
    for(int i : a){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n, l;
    while(true){
        cin >> l;
        if(l == 0)break;
        cin >> n;
        vector<int> prefix(n+2, 0);

        for(int i=1; i<=n; i++){
            cin >> prefix[i];
        }
        prefix[n+1] = l;
        //print(prefix, "prefix");

        vector<vector<int> > dp(n+1, vector<int>(n+1, INT_MAX));

        for(int i=0; i<=n; i++)dp[i][i] = 0;

        int min_cut;
        for(int size=1; size<=n; size++){
            for(int i=0; i+size <= n;i++){
                min_cut = INT_MAX;
                for(int k = i; k < i + size; k++){
                    min_cut = min(min_cut, dp[i][k] + dp[k+1][i+size]);
                }
                dp[i][i+size] = min_cut + prefix[i+size+1] - prefix[i];
                //cout << "i: " << i << " j: " << i+size << " dp[i][j]: " << dp[i][i+size] << "\n";
            }
        }
        cout << "The minimum cutting is " << dp[0][n] << ".\n";
    }

    return 0;
}
