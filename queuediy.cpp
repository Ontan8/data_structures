#include<iostream>
using namespace std;


class Node{
    private:
        int data;
        Node* front;
        Node* next;
        Node* rear;
    public:
        Node(){
            front = NULL;
            rear = NULL;
        }
        void isEmpty();
        void Enqueue(int x);
        void Dequeue();
        void Front();
        void Rear();
};

void Node::isEmpty(){
    if(rear == NULL){
        cout<<"The queue is empty."<<endl;
    }
}

void Node::Enqueue(int x){
    Node* temp = new Node();
    if(front == NULL){
        temp->data = x;
        temp->next = front;
        front = temp;
        rear = front;
    }
    temp->data = x;
    rear->next = temp;
    rear = temp;
}

void Node::Dequeue(){
    Node* temp = front;
    front = front->next;
    delete temp;
}

void Node::Front(){
    cout<<"The value at front is: "<<front->data<<endl;
}

void Node::Rear(){
    cout<<"The value at rear is: "<<rear->data<<endl;
}

int main(){
    Node obj;
    obj.Enqueue(5);
    obj.Enqueue(10);
    obj.Enqueue(28);
    obj.Rear();
    obj.Front();
    obj.Dequeue();
    obj.Front();
    obj.Enqueue(69);
    obj.Rear();
    return 0;
}