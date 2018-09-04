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
        int N,P,packets=0;
        in>>N>>P;
        int price[N];
        for(int i=0;i<N;i++){
            in>>price[i];
        }
        int Q[N][P];
        for(int i=0;i<N;i++){
            for(int j=0;j<P;j++){
                in>>Q[i][j];
            }
            sort(Q[i],Q[i]+P);
        }
        int count[N];
        fill_n(count,N,0);
        int price_sum = accumulate(price,price+N,0);
        while(*max_element(count , count + N)<P){
            int serving,sum=0;
            float check;
            for(int i=0;i<N;i++){
                sum+=Q[i][count[i]];
            }
            serving=round(sum*1.0/price_sum);
           // cout<<check<<" "<<count[0]<<" "<<Q[0][count[0]]<<" "<<0<<" "<<t+1<<" "<<serving<<endl;
            int i;
            for(i=1;i<N;i++){
                check = price[i]*serving;
                cout<<check<<" ";
                check = Q[i][count[i]]/check;
                cout<<check<<" "<<count[i]<<" "<<Q[i][count[i]]<<" "<<i<<" "<<t+1<<" "<<serving<<endl;
                if(check<(float)9/10){
                    count[i]++;
                    break;
                }
                else if(check>(float)11/10){
                    
                }
            }
            if(i==N){
                for(int j=0;j<N;j++){
                    count[j]++;
                }
                packets++;
            }
        }
        out<<"Case #"<<t+1<<": "<<packets<<endl;
    }
    in.close();
    out.close();
    return 0;
}

