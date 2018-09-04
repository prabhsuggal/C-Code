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
        int R,C;
        in>>R>>C;
        char initial;
        char a[R][C];
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                in>>a[i][j];
            }
            for(int j=0;j<C;j++){
                if(a[i][j]>='A' && a[i][j]<='Z'){
                    initial=a[i][j];
                    for(int x=0;x<C;x++){
                        if(a[i][x]>='A' && a[i][x]<='Z')initial=a[i][x];
                        a[i][x]=initial;
                    }
                }
            }

        }
        out<<"Case #"<<t+1<<":"<<endl;
        for(int i=0;i<R;i++){
            if(i==0 && a[i][0]=='?'){
                int x=0;
                while(a[x][0]=='?')x++;
                for(int j=0;j<C;j++){
                    a[i][j]=a[x][j];
                }
                continue;
            }
            if(a[i][0]=='?'){
                for(int j=0;j<C;j++){
                    a[i][j]=a[i-1][j];
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                out<<a[i][j];
            }
            out<<endl;
        }
    }
    in.close();
    out.close();
    return 0;
}

