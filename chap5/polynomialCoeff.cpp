#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

vector<long long> permutations;

int factorial(int n){
    
    if(n >= permutations.size()){
        int sz = permutations.size();
        long long res = permutations[sz-1];
        for(int i=sz; i<=n; i++){
            res*=i;
            permutations.push_back(res);
        }
        return permutations[n];
    }
    return permutations[n];
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    permutations.push_back(1);
    int n, k;
    while(cin >> n && cin >> k){
        vector<int> coeff(k);
        for(int i=0; i<k; i++){
            cin >> coeff[i];
        }
        long long ans = factorial(n)/factorial(coeff[0]);
        for(int i=1; i<k; i++){
            ans/=factorial(coeff[i]);
        }
        cout << ans << "\n";
    }

    return 0;
}
