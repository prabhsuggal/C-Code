#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

int *tree;

void update(int idx, int val, int size){
    while (idx < size)
    {
        tree[idx]+=val;
        idx += (idx & -idx);
    }
    
}
int query(int n){
    int idx = n, res=0;

    while(idx > 0){
        res += tree[idx];
        idx -= (idx & -idx);
    }
    return res;
}

void create_tree(vector<int> &a){
    tree = (int*)calloc(a.size(), sizeof(int));

    for(int i=0; i<a.size(); i++){
        update(i+1, a[i], a.size());
    }
}


int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    vector<int> a{ 1,3,4,5,7,2 };

    create_tree(a);

    cout << query(3) << "\n";
    update(1, 4, a.size());
    cout << query(2) << "\n";
    update(1, -4, a.size());
    cout << query(2) << "\n";
    update(1, 2, a.size());
    cout << query(2) << "\n";
    update(2, 4, a.size());
    cout << query(2) << "\n";

    return 0;
}
