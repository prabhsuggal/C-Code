#include<iostream>
using namespace std;

int main(){
    srand(time(0));
    int x=rand(), y = rand();

    cout << "x: " << x << " y: " << y <<"\n";

    (x < y ? y : x) = 0;

    cout << "x: " << x << " y: " << y <<"\n";

    return 0;
}