#include<iostream>
using namespace std;

// void print(int &a){
//     cout << a << endl;
//     return;
// }

void print(int && a){
    cout << a <<endl;
    return;
}

int main(){
    int a = 10;

    int &b = a;
    print(b);
    print(100);
    return 0;
}