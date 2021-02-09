#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Doesn't Work. Not completely anyways.
 * 
 */

#define ONLINE_JUDGE
typedef pair<int, int> ipair;

vector<ipair> placements;

void print(vector<ipair> &a, int n){
    cout << "Particular Placement:\n";

    vector<vector<char> > table(n, vector<char>(n, 'X'));
    int count = 0;
    for(ipair point : a){
        table[point.first][point.second] = ('0' + (++count));
    }

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
}

uint64_t ways(unordered_set<int> &p, int x, int y, int k, int n){
    if(k == 0){
        print(placements, n);
        return 1;
    }
    if(y >= n){
        return 0;
    }

    uint64_t count = 0;
    unordered_set<int>::iterator it;
    for(int i = y; i<n; i++){
        for(int j = x; j<n; j++){
            if(p.find(i+j) != p.end() || p.find(i-j) != p.end())continue;
            p.insert(i+j);
            p.insert(i-j);
            placements.push_back(make_pair(i, j));
            count += (uint64_t)ways(p, (j+1)%n, i + (j+1)/n, k-1, n);
            placements.pop_back();
            it = p.find(i+j);
            if(it != p.end())p.erase(it);
            it = p.find(i-j);
            if(it != p.end())p.erase(it);
        }
    }

    return count;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n,k;
    while(true){
        cin >> n >> k;
        if(n == 0 && k == 0){
            break;
        }
        unordered_set<int> pattern;
        uint64_t ans = ways(pattern, 0, 0, k, n);
        cout << "No. of way to place bishops: " << ans << "\n";
    }

    return 0;
}
