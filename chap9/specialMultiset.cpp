#include<iostream>
#include<vector>

using namespace std;

vector<int> res;
vector<bool> used;

void print(void)
{   cout << "[";
    for(int i : res){
        cout << i << " ";
    }
    cout << "]\n";
}

bool allUsed(void)
{
    for(bool status : used){
        if(!status){
            return status;
        }
    }
    return true;
}

void freeIdx(vector<int> &a){
    for(uint32_t i=0; i<used.size(); i++){
        if(!used[i]){
            a.push_back(i+1);
        }
    }
}

void printSpecialMultiset(int idx, int n)
{
    if(allUsed()){
        print();
        return;
    }
    vector<int> candidates;
    freeIdx(candidates);
    for(int c : candidates){
        if(idx+c+1 < 2*n && res[idx + c + 1] == 0){
            res[idx] = c;
            res[idx + c + 1] = c;
            used[c-1] = true;
            int newIdx = idx;
            while(newIdx < 2*n && res[newIdx]>0)newIdx++;
            printSpecialMultiset(newIdx, n);
            res[idx] = 0;
            res[idx+c+1] = 0;
            used[c-1] = false;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    res.resize(2*n, 0);
    used.resize(n, false);
    printSpecialMultiset(0, n);
    return 0;
}