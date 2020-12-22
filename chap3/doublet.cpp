#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

bool isDoublet(const string &a, const string &b){
    if(a.size() != b.size()){
        return false;
    }
    int difference=0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]){
            difference++;
        }
    }
    if(difference == 1){
        return true;
    }
    return false;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    vector<string> doublets;
    string a;

    while (getline(cin, a))
    {
        if(a.empty()){
            break;
        }
        doublets.push_back(a);
    }

    vector<vector<int> > graph(doublets.size());
    for(int i=0; i<doublets.size(); i++){
        for(int j=i+1; j<doublets.size(); j++){
            if(isDoublet(doublets[i], doublets[j])){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    string source, dest;
    bool begining = true;
    
    while(cin >> source && cin >> dest){
        if(!begining){
            cout <<"\n";
        }
        else
        {
            begining = false;
        }
        
        queue<int> bfs;
        vector<int> parent(doublets.size(), -2);
        vector<bool> visited(doublets.size(), false);
        int idx = find(doublets.begin(), doublets.end(), source) - doublets.begin();
        int dest_idx = find(doublets.begin(), doublets.end(), dest) - doublets.begin();
        bfs.push(idx);
        visited[idx] = true;
        parent[idx] = -1;
        while(!bfs.empty()){
            idx = bfs.front();
            if(idx == dest_idx){
                break;
            }
            bfs.pop();
            for(int i=0; i<graph[idx].size(); i++){
                if(!visited[graph[idx][i]]){
                    visited[graph[idx][i]] = true;
                    bfs.push(graph[idx][i]);
                    parent[graph[idx][i]] = idx;
                }
            }
        }
        vector<int> ans;
        idx = dest_idx;
        ans.push_back(idx);
        while(parent[idx] != -1){
            if(parent[idx] == -2){
                break;
            }
            ans.push_back(parent[idx]);
            idx = parent[idx];
        }
        if(parent[idx] == -1){
            for(int i=ans.size()-1; i>=0; i--){
                cout << doublets[ans[i]] <<"\n";
            }
        }
        else{
            cout << "No solution.\n";
        }

    }

    return 0;
}
