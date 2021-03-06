#ifndef HashTable_H
#define HashTable_H

#include<iostream>
#include<string>
#include "Node.h"
using namespace std;

struct HashTable{
    private:
        int size{10};
        Node* hasharr[10]{0};
        Node list;
    public: 
        int hashfunction(int key);
        void print(int key);
        int addToHash(int key, string value);
        int deleteFromHash(int key);
        string searchHash(int key);
};

int HashTable::hashfunction(int key){
    return key % size;
}

void HashTable::print(int key){
    list.printData(hasharr, key, hashfunction(key));
    return;
}

int HashTable::addToHash(int key, string value){
    hasharr[hashfunction(key)] = list.addData(key, value);
    return 1;
}

int HashTable::deleteFromHash(int key){
    list.deleteData(hasharr, key, hashfunction(key));
    return 1;
}

string HashTable::searchHash(int key){
    return list.searchData(hasharr, hashfunction(key), key);
}

#endif