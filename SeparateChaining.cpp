#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* HT[10];
Node*cur;
Node* temp;

void hash(int value){
    for(int i=0; i<10; i++){
        HT[i] = NULL;
    }
}

void Insert(int value){
    int index = value % 10;
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
  
    if(HT[index] == NULL){
        HT[index] = temp;   //new Node
    }
    else{
        Node* cur = HT[index];
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = temp;
     
    }
}

void Search(int value){
    int index = value % 10;
    Node* cur = HT[index];
    while(cur != NULL){
        if(value == HT[index]->data){
            cout<<"value found at index: " << index <<"\n";
           return;
        }
        cur = cur->next;
    }
    cout<<"value not found\n";
}

void Display(){
    for(int i=0; i<10; i++){
        cout<< i <<": ";
        Node* cur = HT[i];
        while(cur != NULL){
            cout<< cur->data << "->";
                cur = cur->next;
        }
        cout<<"NULL\n";
    }
}

int main(){

    int value;
    int n =9;
    cout<<"ENTER VALUES TO INSERT: \n";
    for(int i=0; i<n; i++){
    cin>> value;
    Insert(value);
    }
    Display();


    cout<<"ENTER VALUE TO SEARCH:\n";
    cin>>value;
    Search(value);
    Display();


    return 0;
}
