#include<iostream>
#include<string>
#include "HashTable.h"

using namespace std;

//search, insert and delete are the basic operations of the hash table
//use linked list inside the hash table to implement sepeate chaining in the array
//add to the tail of the linked list not the head of the linked list 
//implement search for key and return value, return no value if the key does not exist in the hash table
int main(){
    HashTable h;
    h.addToHash(8, "Raiden");
    h.addToHash(18, "Ayaka");
    h.addToHash(28, "Eula");
    h.addToHash(1, "Tanishq");
    h.addToHash(683, "Lisa");
    h.print(8);
    h.deleteFromHash(18);
    h.print(8);
    h.deleteFromHash(2);
    string val = h.searchHash(683);
    cout << val << endl;
    return 0;
}