#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE
typedef pair<double, int> Pair;

double Distance(pair<double, double> &a, pair<double, double> &b){
    double x = a.first - b.first;
    double y = a.second - b.second;
    return sqrt(x*x + y*y);
}

double prim(vector<vector<pair<int,double> > > &adj){
    int n = adj.size();
    vector<double> dist(n, INT_MAX*1.0);
    vector<bool> inTree(n, false);
    dist[0] = 0.0;
    priority_queue<Pair, vector<Pair>, greater<Pair> > pq;

    pq.push(make_pair(dist[0], 0) );

    int v;
    while(!pq.empty()){
        v = pq.top().second;
        inTree[v] = true;
        pq.pop();

        for(pair<int, double> edge : adj[v]){
            if(!inTree[edge.first] && dist[edge.first] > edge.second){
                dist[edge.first] = edge.second;
                pq.push(make_pair(dist[edge.first], edge.first));
            }
        }
    }

    double len=0.0;
    for(double i : dist){
        len += i;
    }
    return len;

}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int N;
    cin >> N;

    cout << std::fixed << setprecision(2);
    while(N--){
        int n;
        cin >> n;
        vector<pair<double, double> > points(n);
        vector<vector<pair<int, double> > > adj(n);
        double dist;
        for(int i=0; i<n; i++){
            cin >> points[i].first >> points[i].second;
            for(int j=0; j<i; j++){
                dist = Distance(points[i], points[j]);
                adj[j].push_back(make_pair(i, dist));
                adj[i].push_back(make_pair(j, dist));
            }
        }
        double cost = prim(adj);

        cout << cost << "\n";
        if(N){
            cout << "\n";
        }
    }

    return 0;
}
