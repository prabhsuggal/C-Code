#include<iostream>
#include<vector>

using namespace std;

#define COUNT 4

vector<int> lchild, rchild;
vector<bool> used;
int root;

bool allUsed(void)
{
    for(bool idx_used : used){
        if(!idx_used){
            return false;
        }
    }
    return true;
}

void print(vector<int> &a, string name){
    cout << name << ":\n";
    for(int i : a){
        cout << i << " ";
    }
    cout << "\n";
}

void print(vector<bool> &a, string name){
    cout << name << ":\n";
    for(bool i : a){
        cout << i << " ";
    }
    cout << "\n";
}

void printBST(int node, int space)
{
    if(node == -1){
        return;
    }
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    printBST(rchild[node], space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<node+1<<"\n";  
  
    // Process left child  
    printBST(lchild[node], space); 
}

void BST(int l, int node, int r)
{
    // cout << "l : " << l << " node : " << node << " r : " << r << "\n";
    // print(lchild, "lchild");
    // print(rchild, "rchild");
    // print(used, "Used");
    // cout << "\n";

    if(allUsed()){
        cout << "One of the possible BSTs with root " << root + 1<< " are:\n";
        printBST(root, 0);
        return;
    }

    if(l >= r){
        return;
    }

    if(l >= node){
        for(int i = node+1; i<r; i++){
            rchild[node] = i;
            used[i] = true;
            BST(node+1, i, r);
            used[i] = false;
        }
    }
    else if( r <= node){
        for(int i = l; i<node; i++){
            lchild[node] = i;
            used[i] = true;
            BST(l, i, node);
            used[i] = false;
        }
    }
    else{
        for(int i=l; i<node; i++){
            lchild[node] = i;
            used[i] = true;
            BST(l, i, node);
            for(int j=node+1; j<r; j++){
                rchild[node] = j;
                used[j] = true;
                BST(node+1, j, r);
                used[j] = false;
            }
            used[i] = false;
        }
    }
    lchild[node] = -1;
    rchild[node] = -1;

    // cout << "afterwards l : " << l << " node : " << node << " r : " << r << "\n";
    // print(lchild, "lchild");
    // print(rchild, "rchild");
    // print(used, "Used");
    // cout << "\n";

}

int main(){
    int n;
    cin >> n;
    lchild.resize(n, -1);
    rchild.resize(n, -1);
    used.resize(n, false);

    for(root = 0; root < n; root++){
        used[root] = true;
        BST(0, root, n);
        used[root] = false;
    }

    return 0;
}