#include<bits/stdc++.h>
using namespace std;

/**
 * @brief DOESN'T WORK FOR ALL CASES
 *  SEEMS nLogn solution has some issues here
 *
 */
//#define ONLINE_JUDGE

typedef pair<int, int> ipair;

bool weight_comp(const vector<int> &a, const vector<int> &b){
    return a[1] < b[1];
}

bool iq_comp(const vector<int> &a, const vector<int> &b){
    return a[2] > b[2];
}

ipair calculate_lis(vector<vector<int> > &elephant, vector<int> &parent){

    int n = elephant.size();

    vector<vector<int> > lis;
    vector<int> idx;

    vector<vector<int> >::iterator it;
    for(int i=0; i<n; i++){
        it = lower_bound(lis.begin(), lis.end(), elephant[i], weight_comp);
        parent[i] = -1;
        while(it-lis.begin() > 0){
            if(lis[it-lis.begin()-1][2] > elephant[i][2]){
                parent[i] = idx[it - lis.begin() - 1];
                break;
            }
            it--;
        }

        if(it == lis.end()){
            lis.push_back(elephant[i]);
            idx.push_back(i);
        }
        else if((*it)[1] > elephant[i][1]){
            *it = elephant[i];
            idx[it - lis.begin()] = i;
        }

        for(vector<int> e : lis){
            cout << "["  << e[0] << " "<< e[1] << " " << e[2] << "] ";
        }
        cout << "\n";

    }

    return make_pair(idx.size(), idx[idx.size()-1]);
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    //ofstream cout("output.txt");
#endif

    int w,s,n = 1;
    vector<vector<int> > elephant_idx;
    while(cin >> w >> s){
        elephant_idx.push_back({n++, w, s});
    }

    sort(elephant_idx.begin(), elephant_idx.end(), iq_comp);

    vector<int> parent(elephant_idx.size());
    ipair res = calculate_lis(elephant_idx, parent);

    int idx = res.second;
    vector<vector<int> > lis;
    while(idx != -1){
        lis.push_back(elephant_idx[idx]);
        idx = parent[idx];
    }

    cout << res.first << "\n";
    for(int i=res.first-1; i>=0; i--){
        cout << "[" << lis[i][0] << " " << lis[i][1] << " " << lis[i][2] << "]" << "\n";
       // cout << lis[i][0] << "\n";
    }

    return 0;
}
