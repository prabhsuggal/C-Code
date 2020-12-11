#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

std::vector<int> create_random_data(int n) {
  std::random_device r;
  std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
  std::mt19937       eng(seed); // a source of random data

  std::uniform_int_distribution<int> dist;
  std::vector<int> v(n);

  generate(begin(v), end(v), bind(dist, eng));
  return v;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif
    auto random_data = create_random_data(100000);
    srand(time(0));
    int val = random_data[(rand()*1369)%100000];

    
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;

    list<int> linklist(random_data.begin(), random_data.end());
    auto start = high_resolution_clock::now();
    auto a = find(linklist.begin(), linklist.end(), val);
    auto end = high_resolution_clock::now();

    std::cout << "linked list search: " << *a <<" "<< duration_cast<nanoseconds>(end - start).count() << "ns\n";

    set<int> bst(random_data.begin(), random_data.end());
    start = high_resolution_clock::now();
    auto b = find(bst.begin(), bst.end(), val);
    end = high_resolution_clock::now();

    std::cout << "Balanced BST search: "<< *b <<" " << duration_cast<nanoseconds>(end - start).count() << "ns\n";

    unordered_set<int> hashtable(random_data.begin(), random_data.end());
    start = high_resolution_clock::now();
    auto c = find(hashtable.begin(), hashtable.end(), val);
    end = high_resolution_clock::now();

    std::cout << "hashtable search: "<< *c <<" " << duration_cast<nanoseconds>(end - start).count() << "ns\n";

    return 0;
}
