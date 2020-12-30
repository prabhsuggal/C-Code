#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE
#define INF 10000

bool compx(vector<int> &a, vector<int> &b){
    return a[0]<b[0];
}

bool compy(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}

double dist(vector<int> &a, vector<int> &b){
    return sqrt((a[0]-b[0])*(a[0]- b[0]) +
                (a[1]-b[1])*(a[1]-b[1]));
}

double bruteForce(vector<vector<int> > &a, int l, int r){
    double min = INF+0.5, d;
    for(int i=l; i<r; i++){
        for(int j=i+1; j<r; j++){
            d = dist(a[i], a[j]);
            if( d < min){
                min = d;
            }
        }
    }
    return min;
}

double closestStrip(vector<vector<int> > &strip, double min){

    int n = strip.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n && strip[j][1] - strip[i][0] < min; j++){
            min = dist(strip[j], strip[i]);
        }
    }
    return min;

}

double closestDist(vector<vector<int> > &sorted_x, vector<vector<int> > &sorted_y, int l, int r){
    if(r - l <= 3){
        return bruteForce(sorted_x, l, r);
    }
    int mid = l + (r-l)/2;

    vector<vector<int> > sorted_yl(mid-l, vector<int>(2,0)), sorted_yr(r - mid, vector<int>(2,0));
    int li = 0, ri=0;
    for(int i=l; i<r; i++){
        if(sorted_y[i-l][0] <= sorted_x[mid][0] && li < mid-l){
            sorted_yl[li++] = sorted_y[i-l];
        }
        else{
            sorted_yr[ri++] = sorted_y[i-l];
        }
    }

    double dl, dr;
    dl = closestDist(sorted_x, sorted_yl, l, mid);
    dr = closestDist(sorted_x, sorted_yr, mid, r);

    double d = min(dl, dr);

    vector<vector<int> > strip;
    for(int i=l; i<r; i++){
        if(abs(sorted_y[i-l][0] - sorted_x[mid][0]) < d){
            strip.push_back(sorted_y[i-l]);
        }
    }
    
    return closestStrip(strip, d);
}

void print(vector<vector<int> > &a){
    for(int i=0; i<a.size(); i++){
        cout << "("<<a[i][0]<<","<<a[i][1] << ") ";
    }
    cout << "\n";
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int n;
    while(true){
        cin >> n;
        if(!n)break;

        vector< vector<int> > sorted_x(n, vector<int>(2,0));
        for(int i=0; i<n; i++){
            cin >> sorted_x[i][0] >> sorted_x[i][1];
        }

        vector< vector<int> > sorted_y = sorted_x;
        sort(sorted_x.begin(), sorted_x.end(), compx);
        sort(sorted_y.begin(), sorted_y.end(), compy);

        double res = closestDist(sorted_x, sorted_y, 0, n);
        if(res > INF){
            cout << "INFINITY" << endl;
        }
        else{
            cout << fixed << setprecision(4) << res << "\n";
        }
    }

    return 0;
}
