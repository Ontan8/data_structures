#include<iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* head;
        Node* tail;
        Node* next;
    public:
        Node(){
            head = NULL;
            tail = NULL;
        }
        void Insert(int x);
        void Insert(int z, int n);
        void Print();
};

void Node::Insert(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    if(head == NULL){
        head = temp;
        tail = head;
    }
    else{
        head = temp;
        tail->next = head;
    }
}

void Node::Print(){
    Node* tempo = head;
    cout<<"The list is: ";
    while(true){
        if(tempo == tail){
            cout<<tempo->data<<endl;
            break;
        }
        else{
        cout<<tempo->data<<" ";
        tempo = tempo->next;
        }
    }
    // do
    // {
    //     cout<<tempo->data<<" ";
    //     tempo = tempo->next;
    // } while (tempo->next!=head);
    // while(tempo->next!=head){
    //     cout<<tempo->data<<" ";
    //     tempo = tempo->next;
    // }
}

int main(){
    Node obj;
    obj.Insert(24);
    obj.Insert(36);
    obj.Insert(64);
    obj.Print();
    return 0;
}