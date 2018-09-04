#include<bits/stdc++.h>

using namespace std;

int main(int argc,char** argv){
    ifstream in;
    ofstream out;
    in.open(argv[1],ios::in);
    out.open("output.txt",ios::out);
    int T;
    in>>T;
    for(int t=0;t<T;t++){
        int N;
        in>>N;
        //cout<<N<<endl;
        //vector<string> srcs;
        map<string,string> tickets;
        map<string,int> indeg;
        for(int i=0;i<N;i++){
            string src,dest;
            in>>src>>dest;
            tickets[src]=dest;
            indeg[dest]++;
           // cout<<src<<" "<<dest<<endl;
        }
        map<string,string>::iterator i;
        string start;
        for(i=tickets.begin();i!=tickets.end();i++){
         //   cout<<i->first<<"check"<<endl;
            if(indeg[i->first]==0){
                start = i->first;
            }
        }
       // cout<<"start"<<start<<endl;
        out<<"Case #"<<t+1<<":";
        for(int x=0;x<N;x++){
            out<<" "<<start<<"-"<<tickets[start];
            start = tickets[start];
        }
        out<<endl;
    }
   out.close();
    in.close();
    return 0;
}
