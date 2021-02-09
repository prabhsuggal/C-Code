#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

vector<bool> visited, camera;
vector<int> low, parent;

void print(vector<bool> &a, string name){
    cout << name << ":\n";
    for(bool i: a){
        cout << i << " ";
    }
    cout << "\n";
}

void articulationPoint(vector<vector<int> > &adj, vector<int> &disc, int u)
{
    static int time = 0;
    visited[u] = true;

    disc[u] = low[u] = ++time;

    int children=0;

    for(int v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            articulationPoint(adj, disc, v);
            children++;

            low[u] = min(low[v], low[u]);
            if(parent[u] == -1 && children>1){
                camera[u] = true;
            }

            if(parent[u] != -1 && low[v] >= disc[u]){
                camera[u] = true;
            }
        }
        else if(parent[u] != v){
            low[u] = min(disc[v], low[u]);
        }
    }
    //cout << "at node: " << u << "\n";
    //print(camera, "articulationPoint");
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    while(true){
        static int scenario = 1;
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        if(scenario > 1){
            cout << "\n";
        }

        vector<string> index(n);
        unordered_map<string, int> cities;
        for(int i=0; i<n; i++){
            cin >> index[i];
            cities[index[i]] = i;
        }
        int m;
        cin >> m;
        string a, b;
        vector<vector<int> > adj(n);
        for(int i=0; i<m; i++){
            cin >> a >> b;
            adj[cities[a]].push_back(cities[b]);
            adj[cities[b]].push_back(cities[a]);
        }

        visited.clear();
        visited.resize(n, false);

        camera.clear();
        camera.resize(n, false);

        parent.clear();
        parent.resize(n, -1);

        low.clear();
        low.resize(n);
        
        vector<int> disc(n);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                articulationPoint(adj, disc, i);
            }
        }

        vector<string> res;
        for(int i=0; i<n; i++){
            if(camera[i]){
                res.push_back(index[i]);
            }
        }

        sort(res.begin(), res.end());
        
        cout << "City map #" << scenario++ << ": "  << res.size() <<  " camera(s) found\n";
        for(string city : res){
            cout << city << "\n";
        }

    }

    return 0;
}
