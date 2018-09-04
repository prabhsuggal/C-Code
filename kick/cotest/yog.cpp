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
        int N,K;
        in>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            in>>A[i];
        }
        sort(A.begin(),A.end());
        long long ans=0;
        int i,index=0;
        for(i=0;index<=N-K;){
            if(i<A[index]){
                ans+=K;
                index+=K;
                i++;
            }
            else{
                while(i>=A[index])index++;

            }
        }
        while(index<N){
            if(i<A[index]){
                ans+=(N-index);
                break;
            }
            else index++;
        }
        out<<"Case #"<<t+1<<": "<<ans<<endl;

    }

    in.close();
    out.close();
    return 0;
}

