#include<bits/stdc++.h>
using namespace std;

//#define ONLINE_JUDGE

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    uint32_t a,b;

    while(cin >> a >> b){
        if(a==0 && b==0){
            break;
        }
        uint32_t x,y,carry,prev_carry=0, res=0;

        while(a | b){
            x = a%10;
            y = b%10;
            a/=10;
            b/=10;
            carry = (x+y+prev_carry)/10;
            res += carry;
            prev_carry = carry;
        }
        cout << ((res==0)?"No":to_string(res)) << " carry operation" << ((res>1)?"s.":".") << endl;

    }

    return 0;
}
