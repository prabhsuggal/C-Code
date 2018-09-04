#include <cmath>
#include <cstdio>
#include<fstream>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int parent(int i){return (i-1)/2;}
int left(int i){ return (2*i+1);}
int right(int i){ return (2*i+2);}

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(vector<int>& a,int i,int heap_size){
    int smallest=i;
    if(left(i)<heap_size && a[left(i)]<a[smallest])
        smallest=left(i);
    if(right(i)<heap_size && a[right(i)]<a[smallest])
        smallest=right(i);

    if(smallest!=i){
        swap(&a[i],&a[smallest]);
        heapify(a,smallest,heap_size);
    }
    
}

void deletemin(vector<int>& a,int heap_size){
    swap(&a[0],&a[heap_size-1]);
    heapify(a,0,heap_size-1);
}

void insert(vector<int>& a,int i){
    while(i>0 && a[parent(i)]>a[i]){
        swap(&a[i],&a[parent(i)]);
        i=parent(i);
    }
}

void delet(vector<int>& a,int value,int heap_size){
    int i;
    for(i=0;i<heap_size;i++){
        if(a[i]==value)break;
    }
    a[i]=INT_MIN;

    insert(a,i);

    deletemin(a,heap_size);   
}

int main(int argc,char** argv) {
    ifstream in;
    ofstream out;
    in.open(argv[1],ios::in);
    out.open("output.txt",ios::out);
    int Q;
    in>>Q;
    vector<int> heap(100000);
    int heap_size=0;
    for(int i=0;i<Q;i++){
        int type;
        in>>type;
       // out<<heap_size<<"fkbsdj"<<endl;
        switch(type){
            case 1:{
                int value;
                in>>value;
                heap[heap_size]=value;
                heap_size++;
                if(heap_size>1)insert(heap,heap_size-1);
                break;
            }
            case 2:{
                int value;
                in>>value;
                delet(heap,value,heap_size);
                heap_size--;
                break;
            }
            case 3:{
                out<<heap[0]<<endl;
                break;
            }
        }
    }

    in.close();
    out.close();
    return 0;
}

