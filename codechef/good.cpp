#include<bits/stdc++.h>

using namespace std;

int len_good(int a[],int i,int j){
    if(i==j)return 1;
    else if(a[i]>a[j])return j-i+1;
    return max(len_good(a,i+1,j),len_good(a,i,j-1));
}

int main(int argc,char** argv){
    ifstream in;
    in.open(argv[1],ios::in);
    int T;
    in>>T;
    while(T--){
        int n;
        in>>n;
        int a[n];
        for(int i=0;i<n;i++){
            in>>a[i];
        //    cout<<a[i]<<endl;
        }
        int good=len_good(a,0,n-1);
      //  for(int i=0;i<n;i++){
       //     for(int j=n-1;j>=i;j--){
                //cout<<a[i]<<" "<<a[j]<<" "<<good<<endl;
       //         if(a[i]>a[j])good = max(good,j-i+1);
       //     }
       // }
        cout<<good<<endl;
    }
    in.close();
    return 0;
}
