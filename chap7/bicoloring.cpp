#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    while(true){
        int n,l;
        cin >> n;
        if(n == 0){
            break;
        }
        cin >> l;
        vector<vector<int> > adj(n);
        int x,y;
        for(int i=0; i<l; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> color(n,-1);
        vector<bool> visited(n, false);
        queue<int> bfs;

        bfs.push(0);
        visited[0] = true;
        color[0] = 0;

        while(!bfs.empty()){
            int node = bfs.front();
            bfs.pop();
            for(int i : adj[node]){
                if(visited[i]){
                    if(color[node] == color[i]){
                        cout << "NOT BICOLORABLE.\n";
                        goto end;
                    }
                }
                else{
                    color[i] = (color[node] == 0)?1:0;
                    visited[i] = true;
                    bfs.push(i);
                }
            }
        }
        cout << "BICOLORABLE.\n";
    end:
        continue;
    }

    return 0;
}
