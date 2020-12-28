#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

int calculate_distance(vector<int> &a, int s){
    uint32_t dist = 0;
    for(int i=0; i<a.size(); i++){
        dist+=((a[i]-s)*((a[i]-s > 0)?1:-1));
    }
    return dist;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int cases;
    cin >> cases;
    cin.ignore(1,'\n');
    while(cases--){
        vector<int> relatives;
        int s;
        string str;
        getline(cin, str);
        stringstream ss(str);
        while(ss >> s){
            relatives.push_back(s);
        }
        int n = relatives.size();
        if(n%2 == 0){
            int med, dist1, dist2;
            nth_element(relatives.begin(), relatives.begin()+n/2-1, relatives.end());
            med = relatives[n/2-1];
            dist1 = calculate_distance(relatives, med);
            nth_element(relatives.begin(), relatives.begin()+n/2, relatives.end());
            if(med == relatives[n/2]){
                cout << dist1 <<"\n";
            }
            else{
                med = relatives[n/2];
                dist2 = calculate_distance(relatives, med);
                cout << min(dist1, dist2) << "\n";
            }
        }
        else{
            nth_element(relatives.begin(), relatives.begin()+n/2, relatives.end());
            cout << calculate_distance(relatives, relatives[n/2]) << "\n"; 
        }
    }

    return 0;
}
