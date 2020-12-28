#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

bool comp(vector<int> &a, vector<int> &b){
    int x = a[1]*b[0], y=a[0]*b[1];
    if(x != y){
        return x > y;
    }
    return a[2] < b[2];
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int cases;
    cin >> cases;

    while(cases--){
        int n,t,s;
        cin >> n;
        vector<vector<int> > ts(n, vector<int>(3,0));

        for(int i=0; i<n; i++){
            cin >> t >> s;
            ts[i][0] = t;
            ts[i][1] = s;
            ts[i][2] = i+1;
        }
        sort(ts.begin(), ts.end(), comp);
        for(int i=0; i<n; i++){
            cout << ts[i][2];
            if(i==n-1){
                cout << '\n';
            }
            else{
                cout << ' ';
            }
        }
        if(cases){
            cout << '\n';
        }
        
    }

    return 0;
}
