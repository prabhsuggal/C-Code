#include <bits/stdc++.h>

using namespace std;

typedef struct parent{
    int parent,rank;
}subset;

int find(subset par[],int a){
    if(par[a].parent!=a)
        par[a].parent = find(par,par[a].parent);
    return par[a].parent
}

void Union(int x,int y,subset subsets[],long *edges,long int* lib){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);

    if(subsets[xroot].rank<subsets[yroot].rank)
        subsets[xroot].parent=yroot;
    else if(subsets[xroot].rank>subsets[yroot].rank)
        subsets[yroot].parent=xroot;
    else{
        subsets[yroot].parent=xroot;
        subsets[xroot].rank++;
    }
    (*edges)++;
    (*lib)--;
}
// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int> > cities) {


    subset arr[n+1];
    for(int i=0;i<n+1;i++){
        arr[i].parent=i;
        arr[i].rank=1;
    }
    long min,val;
    long edges=0;
    long lib = n;
    int roads=cities.size();
    min = c_lib*lib+c_road*edges;
    for(int i=0;i<roads;i++){
        cout<<min<<endl;
        int x = find(arr,cities[i][0]);
        int y = find(arr,cities[i][1]);
        if(x!=y)Union(x,y,arr,&edges,&lib);
        val = c_lib*lib+c_road*edges;
        min=(min>val)?val:min;
    }

    return min;
}

int main(int argc,char** argv)
{
    ofstream fout;
    fout.open("output.txt",ios::out);
    ifstream in;
    in.open(argv[1],ios::in);

    int q;
    in >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n,m,c_lib,c_road;

        in>>n>>m>>c_lib>>c_road;
        vector<vector<int> > cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                in >> cities[i][j];
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        cout<<"\n\n\n\n"<<endl;
        fout << result << "\n";
    }
    in.close();
    fout.close();

    return 0;
}


