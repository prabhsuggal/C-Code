#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n;
    while(cin >>n){
        vector<int> a(n,0), b(n,0);
        cin >> a[0];
        for(int i=1; i<n; i++){
            cin>>a[i];
            b[abs(a[i]-a[i-1])]++;
        }
        int i;
        for(i=1; i<n; i++){
            if(!b[i]){
                cout << "Not jolly\n";
                break;
            }
        }
        if(i == n)
            cout << "Jolly\n";
    }
    

    return 0;
}
