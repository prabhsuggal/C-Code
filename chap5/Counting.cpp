#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

#define MAP(x) ((x==4)?1:x)

vector<string> dp(1,"1");

string Add(string &a, string &b){
    if(a.size() < b.size())return Add(b, a);
    int x,y, carry=0, i=a.size()-1, j=b.size()-1;
    string res = "";

    while(j >= 0){
            x = a[i--] - '0';
            y = b[j--] - '0';
            res = to_string((x+y+carry)%10) + res;
            carry = (x+y+carry)/10;
    }
    while(i >= 0){
        x = a[i--] - '0';
        res = to_string((x+carry)%10) + res;
        carry = (x+carry)/10;
    }
    if(carry){
        res = to_string(carry) + res;
    }
    return res;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n;
    while(cin >> n){

        string res;
        int sz = dp.size();
        for(int i=sz; i<=n; i++){
            res = "";
            if(i>0){
                res = Add(dp[i-1], dp[i-1]);
            }
            if(i > 1){
                res = Add(res, dp[i-2]);
            }
            if(i > 2){
                res = Add(res, dp[i-3]);
            }
            //cout << i << " " << res <<"\n";
            dp.push_back(res);
        }
        cout << dp[n] << "\n";
    }

    return 0;
}
