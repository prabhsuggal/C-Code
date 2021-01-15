#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

void printGraph(vector<vector<int> > &a){
    int n = a.size();

    for(int i=0; i<n; i++){
        int m = a[i].size();
        cout << i << ": ";
        for(int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << "end\n";
    }

}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n = 10;
    srand(time(0));
    vector<int> indeg(n);
    vector<vector<int> > hatedBy(n);
    unordered_set<int> pairs;

    int x,y;
    for(int i=0; i<n;){
        x = rand()%n, y = rand()%n;
        if(x == y){
            continue;
        }
        if(pairs.find(x*n+y) == pairs.end() && pairs.find(y*n+x) == pairs.end()){
            pairs.insert(x*n+y);
            hatedBy[x].push_back(y);
            i++;
        }
    }
    printGraph(hatedBy);
    queue<int> train;
    vector<int> ans;

    for(int i=0; i<n; i++){
        for(int j=0; j<hatedBy[i].size(); j++){
            indeg[hatedBy[i][j]]++;
        }
    }

    for(int i=0; i<n; i++){
        if(indeg[i] == 0){
            train.push(i);
        }
    }

    if(train.empty()){
        cout << "Too much hate Here. We can't sort them out. Everybody hates each other\n";
        return 0;
    }

    while(!train.empty()){
        int kid = train.front();
        ans.push_back(kid);
        train.pop();
        for(int i=0; i<hatedBy[kid].size(); i++){
            indeg[hatedBy[kid][i]]--;
            if(indeg[hatedBy[kid][i]] == 0){
                train.push(hatedBy[kid][i]);
            }
        }
    }

    if(ans.size() != n){
        cout << "There seems to be some hate cycle going on here. Won't be able to resolve that\n";
        cout<< "For others we will print the list\n";
    }
    cout << "List: ";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << "end\n";

    return 0;
}
