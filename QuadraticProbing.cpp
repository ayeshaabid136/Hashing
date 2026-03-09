#include <iostream>
using namespace std;


int HT[10];

//To make array empty
int init(){
    for(int i=0; i<10; i++){
        HT[i] = -1;
    }
}

//to calculate index
int hashfunction(int key){
    return key%10;
}

//Insert
void Insert(int key){
    int index = hashfunction(key);
    for(int i=0; i<10; i++){
        int idx = (index + i*i)%10;
        if(HT[idx] == -1){
            HT[idx] = key;
            cout<< "Inserted: " << key << "at index: " << idx <<endl;
            return;
        }
    }
    cout<< "Hash Table is full,cannot insert\n";
}

//Search
int search(int key){
 int index = hashfunction(key);
  for(int i=0; i<10; i++){
    int idx = (index + i*i)%10;
    if(HT[idx] == -1){
        cout<< key << "Value not found\n";
        return 0;
    }
    if(HT[idx] == key){
        cout<< key <<"found at: " << idx <<endl;
        return 0;
    }
  }
}

//Display
void display(){
    cout << "-----Hash Table----- \n";
    for(int i=0; i<10; i++){
        cout<< "[" << i << "]: ";
        if(HT[i] == -1){
            cout << "Table Is Empty! \n";
        }
        else{
            cout<< HT[i];
        }
        cout<< "\n";
    }
    cout<< "--------\n";
}

int main(){
   init();
    int choice;
    int key;

    while(true){
    cout<< "1. Insert\n ";
    cout<< "2. Search\n ";
    cout<< "3. Display\n ";
    cout<< "4. Exit\n ";

    cout<< "ENTER YOUR CHOICE: \n";
    cin>> choice;

    switch(choice){
        case 1: {
            cout<< "ENTER KEY TO INSERT: \n";
            cin>> key;
            Insert(key);
            break;
        }
        case 2: {
            cout<< "ENTER KEY TO SEARCH: \n";
            cin>>key;
            search(key);
            break;
        }
        case 3: {
            display();
            break;
        }
        case 4: {
            cout<< "EXIT\n";
            break;
        }

        default: cout<< "INVALID CHOICE!\n";
        break;
        }
        
        if(choice == 5){
            break;
        }
   }

    return 0;
}