#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

bool comp(const pair<int, vector<int> > &a, const pair<int, vector<int> > &b){
    return (a.first < b.first);
}

bool validate(vector<char> perm, string &a, string &b){
    unordered_map<char, char> tmp_map;
    for(int i=0; i<b.size(); i++){
        if(tmp_map.find(b[i]) == tmp_map.end()){
            if(perm[b[i]-'a']){
                tmp_map[b[i]] = perm[b[i]-'a'];
            }
            else{
                tmp_map[b[i]] = a[i];
            }
        }
    }

    string tmp="";
    for(int i=0; i<b.size(); i++){
        tmp+=tmp_map[b[i]];
    }

    if(tmp != a)
        return false;

    for(int i=0; i<b.size(); i++){
        perm[b[i]-'a'] = tmp_map[b[i]];
    }

    return true;
}

void print_garbage(vector<string> &key){
    for(int i=1; i<key.size(); i++){
        cout << " ";
        for(int j=0; j< key[i].size(); j++){
            cout<<"*";
        }
    }
    cout <<"\n";
}

void print_key(vector<char> &perm, vector<string> &key){
    for(int i=0; i<key.size(); i++){
        for(int j=0; j<key[i].size(); j++){
            cout << perm[key[i][j]-'a'];
        }
        if(i == key.size()){
            cout << "\n";
        }
        else{
            cout << " ";
        }
    }
    return;
}

bool match(vector<int> &a, vector<int> &b){
    if(a.size() != b.size()){
        return false;
    }
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}

bool decrypt(vector<string> &key, vector<string> &dict, 
            int idx, unordered_set<string> &mapper, vector<char> perm){
    while(idx < key.size() && mapper.find(key[idx]) != mapper.end()){
        cout << idx << endl;
        idx++;
    }
    if(idx == key.size()){
        print_key(perm, key);
        return true;
    }
    
    bool rv = false;
    vector<char> parent_perm = perm; 
    
    for(int i=0; i<dict.size(); i++){
        if(dict[i].size() == key[idx].size() && validate(perm, dict[i], key[idx])){
            mapper.insert(key[idx]);
            rv = decrypt(key, dict, idx+1, mapper, perm);
            if(rv){
                return rv;
            }
            perm = parent_perm;
        }
    }
    return false;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n;
    cin >> n;
    vector<string> dict(n);
    string t;
    for(int i=0; i<n; i++){
        cin >> dict[i];
    }

    cin.ignore(1,'\n');
    while(getline(cin, t)){
        vector<string> key;
        vector<char> perm(26,0);
        istringstream iss(t);
        while(iss>>t){
            key.emplace_back(t);
        }
        if(!key.size()){
            cout << "\n";
            continue;
        }
        unordered_set<string> mapper;
        if(!decrypt(key, dict, 0, mapper, perm)){
            print_garbage(key);
        }
    }
    

    return 0;
}
