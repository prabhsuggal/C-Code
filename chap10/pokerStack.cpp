#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

void print(vector<vector<string> > &a){
    cout << "stack pattern:\n";
    for(auto arr : a){
        for(string s: arr){
            cout << std::setfill(' ') << std::setw(15) << s << " ";
        }
        cout << "\n";
    }
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    string X,Y;
    cin >> X >> Y;
    int n = X.size(), m = Y.size();

    vector<vector<string> > dp(n+1, vector<string>(m+1));

    dp[0][0] = '\0';
    if(n>0)dp[1][0] = X[0];
    if(m>0)dp[0][1] = Y[0];

    for(int i=2; i<=n; i++){
        if(X[i-1] == X[i-2])dp[i][0] = dp[i-1][0];
        else dp[i][0] = dp[i-1][0] + X[i-1];
    }

    for(int i=2; i<=m; i++){
        if(Y[i-2] == Y[i-1])dp[0][i] = dp[0][i-1];
        else dp[0][i] = dp[0][i-1] + Y[i-1];
    }

    print(dp);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = X+Y;
            if(i>1 && X[i-1] == X[i-2]){
                if(j>1 && Y[j-1] == Y[j-2]){
                    if(dp[i][j].size() > dp[i-1][j-1].size())dp[i][j] = dp[i-1][j-1];
                }
                else if(dp[i][j].size() > dp[i-1][j].size())dp[i][j] = dp[i-1][j];
            }
            else{
                if(j>1 && Y[j-1] == Y[j-2]){
                    if(dp[i][j].size() > dp[i][j-1].size())dp[i][j] = dp[i][j-1];
                }
            }
            if(X[i-1] == Y[j-1] && dp[i][j].size() > dp[i-1][j-1].size()+1)dp[i][j] = dp[i-1][j-1] + X[i-1];
            if(dp[i][j].size() > dp[i-1][j].size()+1)dp[i][j] = dp[i-1][j] + X[i-1];
            if(dp[i][j].size() > dp[i][j-1].size()+1)dp[i][j] = dp[i][j-1] + Y[j-1];
        }
        cout <<"i: " << i << "\n";
        print(dp);
    }

    cout << dp[n][m] << " " << dp[n][m].size() << "\n";

    return 0;
}
