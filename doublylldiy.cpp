#include<iostream>
using namespace std;


class Node{
    private:
        int data;
        Node* next;
        Node* prev;
        Node* head;
        Node* tail;
    public:
        Node(){
            next = NULL;
            prev = NULL;
            head = NULL;
            tail = NULL;
        }
        void Insert(int x);
        void Insert(int x, int n);
        void InsertAtEnd(int e);
        void deleteData(int z);
        void Print();
};

void Node::Insert(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;
    if(head!=NULL){
        head->prev = temp;
    }
    head = temp;
}

void Node::Insert(int x, int n){
    if(n==1){
        Insert(x);
    }
    else{
        Node* temp = new Node();
        temp->data = x;
        Node* temp2 = head;
        for(int i = 1; i<n-1; i++){
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next = temp;
        temp->prev = temp2;
        temp2 = temp->next;
        temp2->prev = temp;
    }
}

void Node::Print(){
    Node* tempo = head;
    cout<<"The list is: ";
    while (tempo!=NULL)
    {
        cout<<tempo->data<<" ";
        tempo = tempo->next;
    }
    cout<<"\n";
}

void Node::InsertAtEnd(int e){
    Node* temp = new Node();
    temp->data = e;
    Node* temp2 = head;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp->prev = temp2;
    temp2->next = temp;
}

int main(){
    int size;
    Node obj;
    cout<<"How many elements to be inserted into the linked list: ";
    cin>>size;
    cout<<"\n";
    int z;
    for(int j = 0; j<size; j++){
        cout<<"Enter a number to be inserted in the linked list: ";
        cin>>z;
        obj.Insert(z);
        obj.Print();
    }
    obj.Insert(5678, 2);
    obj.Print();
    obj.Insert(69, 3);
    obj.Print();
    obj.Insert(1, 1);
    obj.Print();
    obj.InsertAtEnd(100);
    obj.Print();
    return 0;
}