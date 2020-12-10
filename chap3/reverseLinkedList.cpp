#include<bits/stdc++.h>
using namespace std;

#define ONLINE_JUDGE

typedef struct Node_{
    int data;
    struct Node_* next;
}Node;

Node* create_list(int a[], int size){

    if(size == 0){
        return NULL;
    }

    Node* head = (Node*)malloc(sizeof(Node));
    Node* it = head;
    it->data = a[0];
    for(int i=1; i<size; i++){
        it->next = (Node*)malloc(sizeof(Node));
        it->next->data = a[i];
        it = it->next;
    }
    it->next = NULL;

    return head;
}

void print_list(Node* head){
    Node* it = head;
    while(it != NULL){
        cout << it->data << "->";
        it = it->next;
    }
    cout <<"NULL\n";
}

Node* reverse_list(Node* a){
    Node* it = a, *tmp = NULL, *prev = NULL;

    while(it != NULL){
        tmp = it->next;
        it->next = prev;
        prev = it;
        it = tmp;
    }

    return prev;
}

int main(){

#ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif

    int arr[] = {1,2,3,4,5};

    Node* head = create_list(arr, 5);

    print_list(head);

    head = reverse_list(head);

    print_list(head);

    return 0;
}
