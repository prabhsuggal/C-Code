#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

string charChange(string a, int x){
    if(x >= a.size()){
        return a;
    }
    a[x] = '*';
    return a;
}

string charAdd(string a, int x){
    if(a.size() <= x){
        return a+'*';
    }

    string str = "";
    for(char i : a){
        if(str.size() == x){
            str += '*';
        }
        str += i;
    }
    return str;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    string str;
    vector<string> dict;
    while(cin >> str){
        dict.push_back(str);
    }

    int n = dict.size();
    unordered_map<string, int> tree;

    vector<int> dp(n, 0);
    int max_len = 0;
    for(int i=0; i<n; i++){
        for(int k=0; k<dict[i].size(); k++){
            str = charChange(dict[i], k);
            if(tree.find(str) != tree.end()){
                dp[i] = max(dp[i], dp[tree[str]]+1);
            }
            tree[str] = i;
            str = charAdd(dict[i], k);
            if(tree.find(str) != tree.end()){
                dp[i] = max(dp[i], dp[tree[str]]+1);
            }
            tree[str] = i;
        }
        str = charAdd(dict[i], dict[i].size());
        if(tree.find(str) != tree.end()){
            dp[i] = max(dp[i], dp[tree[str]]+1);
        }
        tree[str] = i;
        max_len = max(max_len, dp[i]);
    }

    cout << max_len+1 << "\n";
    
    return 0;
}
