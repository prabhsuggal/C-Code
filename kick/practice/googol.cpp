#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

char bit(long long int a,long long int arr[]){
    //cout<<"a="<<a<<endl;
    if(a==1)return '0';
    long long int *index = std::lower_bound(arr,arr+64,a);
    //cout<<*index<<"lower_bound"<<*(index-1)<<endl;
    if(*(index-1)+1== a)return '0';
    //return '1';
    char bits = bit(*index+1-a,arr); 
    return (bits=='0'?'1':'0');
}

int main(int argc,char** argv){
    
    ifstream in;
    ofstream out;
    out.open("output.txt",ios::out);
    in.open(argv[1],ios::in);
    
    int T;
    in>>T;
    long long int query[T];
    for(int t=0;t<T;t++){
        in>>query[t];
        cout<<query[t]<<endl;
    }
    long long int arr[64];
    arr[0]=1;
    for(int i=1;i<64;i++){
        arr[i]=2*arr[i-1]+1;
    }
    for(int i=0;i<T;i++){
        out<<"Case #"<<i+1<<": "<<bit(query[i],arr)<<endl; 
            }
    out.close();
    in.close();

    return 0;
}
