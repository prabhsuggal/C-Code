#include <bits/stdc++.h>

using namespace std;


void build(vector<int> arr,vector<int> &tree,int d){

    for(int i=0;i<d;i++){
        tree[201+arr[i]]++;
    }
    //for(int i=401;i>200;i--){
    //    cout<<tree[i]<<" "<<i<<endl;
    //}
    for(int i=200;i>0;i--){
        tree[i]=tree[i<<1]+tree[i<<1|1];
        if(tree[i]>0)cout<<tree[i]<<" "<<i<<endl;
    }

}

int findMedian(vector<int> &tree,int d){
    int i=1;
    bool isEven=false;
    if(d%2==0)isEven=true;
    int search=(d+1)/2;
    while(i<201){
       // cout<<tree[(i<<1)]<<" ";
        if(tree[(i<<1)]<search){
            search-=tree[i<<1];
            i=(i<<1|1);
        }
        else i=(i<<1);
        //cout<<search<<" "<<i<<endl;
    }
   // cout<<i<<" "<<search<<endl;
    if(isEven){
        //cout<<tree[i]<<" "<<i<<endl;
        int rem = tree[i]-search;
        //cout<<rem<<endl;
        if(rem>0)return 2*i-402;
        else if(rem==0){
            int num=i-201;
            while(tree[i+1]==0)i++;
            return i-200+num;
        }
    }
    return 2*i-402;
}

void remove(vector<int> &tree,int x){
    tree[201+x]--;
    int i=201+x;
    while(i>=1){
        tree[i>>1]--;
        i>>=1;
    }
}

void add(vector<int> &tree,int x){
    tree[201+x]++;
    int i=201+x;
    while(i>=1){
        tree[i>>1]++;
        i>>=1;
    }
}
// Complete the activityNotifications function below.
int activityNotifications(ostream &out,vector<int> expenditure, int d) {
    vector<int> segment(402);
    int notice=0;
    build(expenditure,segment,d);
    int n=expenditure.size(),twice_med;
    for(int i=d;i<n;i++){
        twice_med=findMedian(segment,d);
        int sum=0;
        for(int j=201;j<402;j++){
          sum+=segment[j];
          out<<j-201<<"->"<<sum<<" ";
        }
        out<<endl;
        out<<"twice_med->"<<twice_med;
        if(twice_med<=expenditure[i])notice++;
        remove(segment,expenditure[i-d]);
        add(segment,expenditure[i]);
        out<<" next-> "<<expenditure[i]<<" noticfications->"<<notice<<endl;
    }

    return notice;
}

int main(int argc,char** argv){
  ifstream in(argv[1]);
  ofstream out("output.txt");
  int n,d;
  in>>n>>d;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    in>>arr[i];
  //  cout<<arr[i]<<" ";
  }
  cout<<activityNotifications(out,arr,d)<<endl;

  in.close();
  out.close();

  return 0;
}
