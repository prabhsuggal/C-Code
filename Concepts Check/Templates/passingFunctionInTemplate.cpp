#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

int add1(int a, int b){return a*b+1;}
double add2(double a, double b){return a+b;}

template<class T, class __comp>
T operate(vector<T> arr, __comp func){
    T res{};
    for(auto it = arr.begin(); it != arr.end(); it++){
        res = func(*it, res);
    }
    return res;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    vector<int> arr1 = {1,2,3,4,5,6};
    vector<double> arr2 = {1.1,2.0,3.0,4.0,5.0,6.0};

    cout << operate(arr1, add1) << "\n";
    cout << operate(arr2, add2) << "\n";

    return 0;
}
