#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

typedef pair<int, int> ipair;
bool compare(const vector<int> &a, const vector<int> &b){
    return a[0] < b[0];
}

/**
 * @brief this function hasn't been used anywhere. In the earlier version,
 *        I was using it for getting the departure time from src station. Not a good method anyway
 * 
 * @param edges 
 * @param parent 
 * @param arrival_time 
 * @param src_station 
 * @param station 
 * @return int 
 */
int src_departure_time(vector<vector<int> > &edges, vector<int> &parent, vector<int> &arrival_time,
     int src_station, int station){
    int child_station;
    while(parent[station] != -1){
        child_station = station;
        station = parent[station];
    }
    int max_d_time = INT_MIN;
    for(vector<int> edge : edges){
        if(edge[2] == child_station && edge[1] == arrival_time[child_station]){
            max_d_time = max(max_d_time, edge[0]);
        }
    }
    return max_d_time;
}

/**
 * @brief Djikstra's Algorithm
 *        the Cost Function used is as 
 *        dist[v] = dist[u] + arrival_time[v] - arrival_time[u]
 *        here arrival time is the time when we reach a station
 * 
 * @param adj 
 * @param n 
 * @param arrival_time 
 * @param parent 
 * @param src 
 * @param dest 
 */
void shortest_path(vector<vector<vector<int> > > &adj, int n, 
        vector<int> &arrival_time, vector<int> &parent, int src, int dest){
    set<ipair> djkt;
    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    parent[src] = -1;
    
    djkt.insert(make_pair(0, src));
    while(!djkt.empty()){
        int node = djkt.begin()->second;
        djkt.erase(djkt.begin());

        for(vector<int> neighbour: adj[node]){
            if(neighbour[0] >= arrival_time[node]){
                if(dist[neighbour[2]] > dist[node] + neighbour[1] - arrival_time[node]){
                    if(dist[neighbour[2]] != INT_MAX){
                        djkt.erase(djkt.find(make_pair(dist[neighbour[2]], neighbour[2])));
                    }
                    dist[neighbour[2]] = dist[node] + neighbour[1] - arrival_time[node];
                    arrival_time[neighbour[2]] = neighbour[1];
                    parent[neighbour[2]] = node;
                    djkt.insert(make_pair(dist[neighbour[2]], neighbour[2]));
                }
            }
        }
    }
    
}

void print(vector<int> &a, string name){
    cout << name << ":\n";
    for(int i : a){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        unordered_map<string, int> hmap;
        string station;
        for(int i=0; i<n; i++){
            cin >> station;
            hmap[station] = i;
        }

        int T,t;
        cin >> T;

        vector<vector<vector<int> > > adj(n);
        while(T--){
            cin >> t;
            int t_src, t_dst;
            string src, dst;
            cin >> t_src >> src;
            vector<int> dest(3);
            for(int i=1; i<t; i++){
                cin >> t_dst >> dst;
                dest[0] = t_src;                  // storing arrival time, time taken for journey and destination
                dest[1] = t_dst;
                dest[2] = hmap[dst];
                adj[hmap[src]].push_back(dest);

                t_src = t_dst;
                src = dst;
            }
        }
        vector<int> arrival_time(n, -1), parent(n), tmp_arrival_time(n,-1);
        int arrival_src, arrival_dest = INT_MAX;
        string src, dest;
        cin >> arrival_src;
        cin >> src;
        cin >> dest;

        int src_station = hmap[src], dest_station = hmap[dest];
        sort(adj[src_station].begin(), adj[src_station].end(), compare);

        
        for(vector<int> edge : adj[src_station]){
            if(edge[0] < arrival_src){
                continue;
            }
            tmp_arrival_time[src_station] = edge[0];
            shortest_path(adj, n, tmp_arrival_time, parent, src_station, dest_station);
            if(tmp_arrival_time[dest_station] >= 0 && arrival_dest >= tmp_arrival_time[dest_station]){
                arrival_time = tmp_arrival_time;
                arrival_dest = tmp_arrival_time[dest_station];
                tmp_arrival_time[dest_station] = -1;
            }
            else{
                break;
            }
        }
        //print(arrival_time, "arrival_time");
        //print(parent, "parent_array");
        //cout << "src: " << src << " dest: " << dest << " arrival_time at src: " << arrival_src << "\n";

        cout << "Scenario " << i+1 << "\n";
        if(arrival_time[dest_station] >= 0){
            cout << "Departure " << std::setfill('0') << std::setw(4) << 
                arrival_time[src_station] << " " << src << "\n";
    
            cout << "Arrival   " << std::setfill('0') << std::setw(4) 
                << arrival_time[dest_station] << " " << dest << "\n";
        }
        else{
            cout << "No connection\n";
        }
        cout << "\n";
    }

    return 0;
}
