#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE
//vector<int> path;

void print(vector<int> &a){
    cout << "start";
    for(int i : a){
        cout << " -> " << i;
    }
    cout << "\n";
}

int dfs(vector<vector<pair<int, int> > > &adj, vector<bool> &visited, int node, int destination){
    if(node == destination){
        //print(path);
        return INT_MAX;
    }
    int max_tourists = 0;
    for(pair<int, int> it : adj[node]){
        if(!visited[it.first] && it.second > max_tourists){
            visited[it.first] = true;
            //path.push_back(it.first+1);
            max_tourists = max(max_tourists, min(it.second, dfs(adj, visited, it.first, destination)));
            //path.pop_back();
            visited[it.first] = false;
        }
    }
    //cout << "Node: " << node+1 << " destination: " << destination+1 <<" max_tourists: " << max_tourists << "\n";
    return max_tourists;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    while(true){
        int N,R;
        cin >> N >> R;
        if(N==0 && R==0){
            break;
        }

        //cout << "N: " << N << " R: "<< R <<"\n";
        vector<vector<pair<int, int> > > adj(N);

        int x,y,p;
        for(int i=0; i<R; i++){
            cin >> x >> y >> p;
            adj[x-1].push_back(make_pair(y-1,p));
            adj[y-1].push_back(make_pair(x-1,p));
            //cout << x << " " << y << " " << p <<"\n";
        }

        int start, destination, tourists;
        cin >> start >> destination >> tourists;
        //cout << start << " "<< destination << " " << tourists << "\n";

        vector<bool> visited(N, false);
        visited[0] = true;
        int max_passengers = dfs(adj, visited, start-1, destination-1);

        int trips = tourists/(max_passengers-1);
        if(trips*(max_passengers-1) >= tourists){
            cout << trips <<"\n";
        }
        else{
            cout << trips+1 << "\n";
        }

    }

    return 0;
}
