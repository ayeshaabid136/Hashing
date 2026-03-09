#include <iostream>
using namespace std;
#include <stdlib.h>

int HT[10];

//First, Make Array Empty
int initialize(){
    for(int i=0; i<10; i++){
        HT[i] = -1;
    }
}

// TO calculate Index
int hashfunction(int key){
    return key % 10;    //to convert value into index
}

//Insert
void Insert(int key){
    int index= hashfunction(key);
    for(int i=0; i<10; i++){
       int idx = (index+i)%10;

       if(HT[idx] == -1){
        HT[idx] = key;
        cout << "Inserted: " << key << " at index: " << idx << endl;
        return;
       }
    }
    cout << "Hash Table is full, can not insert elements.\n";
}

//Search
void search(int key){
    int index= hashfunction(key);
    for(int i=0; i<10; i++){
        int idx = (index+i)%10;
        if(HT[idx] == -1){
            cout<< key << "key not found\n";
            //return;
        }
        if(HT[idx] == key){
            cout<< key << "found at: " << idx << endl;
            return;
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

    initialize();
    Insert(22);
    Insert(33);
    Insert(44);
    Insert(25);
    Insert(45);
    display();

    search(22);
    display();

    return 0;
}

