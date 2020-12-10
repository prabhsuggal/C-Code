#include<bits/stdc++.h>

using namespace std;

#define ONLINE_JUDGE

int getdiv(int st[], int si, int ss, int se, int l, int r){
    if(ss >=l && se <= r){
        return st[si];
    }
    if(se < l || ss > r){
        return 0;
    }
    
    int mid =ss + (se-ss)/2;
    
    return getdiv(st, 2*si+1, ss, mid, l ,r) +
            getdiv(st, 2*si+2, mid+1, se, l, r);
    
}

int createSegmentTree(int a[], int ss, int se, int st[], int si){
    
    if(ss==se){
        st[si] = ((a[ss]%5==0)?1:0);
        return st[si];
    }
    int mid = ss + (se-ss)/2;
    st[si]=createSegmentTree(a, ss, mid, st, 2*si+1)
            +createSegmentTree(a, mid+1, se, st, 2*si+2);
    
    return st[si];
}

int* segment_tree(int a[], int n){
    int x = (int)ceil(log2(n));
    
    int size = (int)(2*pow(2,x)-1);
    
    int* arr = new int[size];
    
    createSegmentTree(a, 0, n-1, arr, 0);
    
    return arr;
    
}

int main()
 {

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif
	int T;
	
	cin >> T;
	while(T--){
	    int n,q;
	    cin >> n >> q;
	    int a[n];
	    for(int i=0; i<n; i++){
	        cin >> a[i];
	    }
	    int l[q],r[q];
	    for(int i=0; i<q; i++){
	        cin >> l[i] >> r[i];
	    }
	    
	    int* st = segment_tree(a, n);
	    
	    for(int i=0; i<q; i++){
	        cout << getdiv(st, 0, 0, n-1, l[i]-1, r[i]-1) << " ";
	    }
	    cout <<"\n";
	    
	}
	
	return 0;
}