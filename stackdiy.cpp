#include<iostream>
#include<cstring>
using namespace std;


//using linked list
class Node{
    private:
        int data;
        Node* top;
        Node* next;

    public:
        Node(){
            top = NULL;
        }
        void push(int z);
        void pop();
        void peek();
        void isEmpty();
};

void Node::push(int z){
    Node* temp = new Node();
    temp->data = z;
    temp->next = top;
    top = temp;
}

void Node::pop(){
    if(top==NULL){
        cout<<"The stack is empty."<<endl;
    }
    else{
        Node* temp = top;
        top = top->next;
        temp = NULL;
    }
}

void Node::isEmpty(){
    if(top == NULL){
        cout<<"The stack is empty."<<endl;
    }
    else{
        cout<<"The stack is not empty."<<endl;
    }
}

void Node::peek(){
    cout<<"The value at the top is: "<<top->data<<endl;
}

int main(){
    Node obj;
    obj.push(3);
    obj.push(65);
    obj.pop();
    obj.peek();
    obj.isEmpty();
}