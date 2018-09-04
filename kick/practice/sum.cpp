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
        out<<"Case #"<<t+1<<":"<<endl;
        int N,Q;
        in>>N>>Q;
        cout<<N<<"query"<<Q<<endl;
        int a[N];
        map<int,int> sum_array;
        //fill_n(sum_array,100*N+1,0);
        for(int i=0;i<N;i++){
            in>>a[i];
            int sum=0;
            for(int j=i;j>=0;j--){
                sum+=a[j];
                sum_array[sum]++;
            }
        }
        cout<<sum_array.size()<<endl;
        for(int i=0;i<Q;i++){
            long L,R,index=0,sum=0;
            map<int,int>::iterator x;
            in>>L>>R;
            cout<<L<<"left"<<R<<endl;
            for(x=sum_array.begin();L-index-x->second>0;x++)index+=x->second;
            if(index+x->second>=R){
                sum+=(R-L+1)*x->first;
                out<<sum<<endl;
                //cout<<sum<<"1"<<endl;
                continue;
            }
            else{
                sum+=(index+x->second-L+1)*x->first;
                //cout<<sum<<"2"<<endl;
                index+=x->second;
                x++;
            }
            for(;index+x->second<=R;x++){
                sum+=x->second*x->first;
                index+=x->second;
                //cout<<sum<<"loop"<<index<<endl;
            }
            if(index+x->second>R)sum+=(R-index)*x->first;
                //cout<<sum<<"Total sum"<<endl;
            out<<sum<<endl;

        }
            sum_array.clear();
    }
    in.close();
    out.close();
    return 0;
}
