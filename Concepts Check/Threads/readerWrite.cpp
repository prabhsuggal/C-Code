// CPP program to demonstrate multithreading
// using three different callables.
#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

bool data_valid{0};
typedef struct data_{
    int a,b;
}data;
data d;

void reader(){
    while(data_valid == false);
    cout << d.a << " " << d.b << "\n";
}

void writer(){
    usleep(10);
    d.a = 10;
    d.b = 5;
    data_valid = true;
}

int main(){
    thread r(reader);
    thread w(writer);

    r.join();
    w.join();
    return 0;
}