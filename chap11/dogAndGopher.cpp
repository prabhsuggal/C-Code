#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

typedef struct loc_{
    double x,y;
}loc;


double distance(loc &a, loc &b){
    double x_ab = a.x - b.x, y_ab = a.y - b.y;
    return x_ab*x_ab + y_ab*y_ab;
}

void print(loc &a){
    cout << a.x << " " << a.y << "\n";
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    loc dog, gopher;
    int n;
    while(cin >> n >> gopher.x >> gopher.y >> dog.x >> dog.y){

        vector<loc> points(n);
        for(int i=0; i<n; i++){
            cin >> points[i].x >> points[i].y;
        }

        for(int i=0; i<n; i++){
            // cout << 4*distance(points[i], gopher) << " " << distance(points[i], dog) << "\n";
            if(4*distance(points[i], gopher)  <= distance(points[i], dog)){
                cout << "The gopher can escape through the hole at ("
                    << fixed << setprecision(3) << points[i].x << "," << points[i].y <<").\n";
                goto end;
            }
        }

        cout << "The gopher cannot escape.\n";
end:
        cin.ignore(1000, '\n');

    }

    return 0;
}
