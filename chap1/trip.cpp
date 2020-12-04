#include<bits/stdc++.h>
using namespace std;

/* #define ONLINE_JUDGE */

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int num;
    int sum, sumAbove, sumBelow, dollar, cent;
    char temp;

    while(true){
        cin >> num;
        if(num == 0)
            break;
        sum=0;
        sumAbove=0;
        sumBelow=0;
        vector<int> students(num);
        for(int i=0; i<num; i++){
            cin >> dollar >> temp >> cent;
            students[i] = dollar*100 + cent;
            sum+=students[i];
        }
        int lowAverage = sum / num;
        int highAverage = lowAverage + ((sum % num) ? 1 : 0);
        
        for (int i = 0; i < num; ++i)
        {
            if (students[i] > highAverage)
                sumAbove += students[i] - highAverage;
        }
        
        int sumBelow = 0;
        for (int i = 0; i < num; ++i)
        {
            if (students[i] < lowAverage)
                sumBelow += lowAverage - students[i];
        }
        
        int usedSum = max(sumAbove, sumBelow);
        
        cout << '$' << (usedSum / 100) << '.' << setw(2) << setfill('0') << (usedSum % 100) << '\n';
    }
    return 0;
}

