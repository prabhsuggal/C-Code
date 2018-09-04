#include<iostream>
#include<fstream>

using namespace std;

int main(int argc,char **argv){
    ifstream source;
    ofstream output;

    source.open(argv[1],ios::in);
    output.open("output.txt",ios::out);

    int T;
    source>>T;
    for(int t=0;t<T;t++){
        int n;
        source>>n;
        int arr[5001]={0};
        for(int i=0;i<n;i++){
            int a,b;
            source>>a>>b;
            for(int j=a;j<=b;j++)arr[j]++;
        }
        int p;
        source>>p;
        output<<"Case #"<<t+1<<":";
        while(p--){
            int city;
            source>>city;
            output<<" "<<arr[city];
        }
        output<<endl;
    }
    source.close();
    output.close();
    return 0;
}
