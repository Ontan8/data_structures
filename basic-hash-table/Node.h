#ifndef Node_H
#define Node_H

#include<iostream>
#include<string>
using namespace std;

struct Node{
    private:
        int data;           
        string value;
        Node* next;  
        Node* head{NULL};  
        Node* traverse;  //to traverse the hash table array which contains the head of the linked lsit
    public:
        Node* addData(int key, string value);
        void printData(Node* arr[], int key, int index);
        int deleteData(Node* arr[], int key, int index);
        string searchData(Node* arr[], int index, int key);
};

void Node::printData(Node* arr[], int key, int index){
    traverse = arr[index];
    while(traverse){
        cout<<"The index is : "<< index << ", the key is : " << traverse->data << " and the value is : " << traverse->value << endl;
        traverse = traverse->next;
        }            
    return;
}

//adds new key at the end of the linked list as opposed to the start of the linked list
Node* Node::addData(int key, string value){
    Node* temp = new Node();
    temp->data = key;
    temp->value = value;
    if(!head){
        head = temp;
        return head;
    }
    traverse = head;
    while(traverse->next){
        traverse = traverse->next;
    }
    temp->next = NULL;
    traverse->next = temp;
    return head;
}

int Node::deleteData(Node* arr[], int key, int index){
    traverse = arr[index];
    Node* traversePrev = NULL;
    while(traverse){
        if(traverse->data == key){
            traversePrev->next = traverse->next;
            delete traverse;
            cout << "Deletion : Success" << endl;
            return 1;
        }
        traversePrev = traverse;
        traverse = traverse->next;
    }
    cout << "Deletion : Failed" << endl;
    return 0;
}

string Node::searchData(Node* arr[], int index, int key){
    traverse = arr[index];
    string fail{};
    while(traverse){
        if(traverse->data == key){
            return traverse->value;
        }
        traverse = traverse->next;
    }
    return fail;
}

#endif