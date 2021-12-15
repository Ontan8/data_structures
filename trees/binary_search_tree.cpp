#include<iostream>
#include<string>
using namespace std;

struct Node{
    private:
        int data;
        Node* left{NULL};
        Node* right{NULL};
    public:
        Node* setData(int data);
        void insert(int data);
        void print();
};

Node* root = NULL; //this points to the root of the binary search tree
Node* traverse;  //a global variable to traverse the tree without resorting to recursion

Node* Node::setData(int data){
    Node* temp = new Node();
    temp->data = data;
    if(!root){
        root = temp;
        return NULL;
    }
    traverse = root;
    return temp;
}

void Node::insert(int data){
    Node* temp = setData(data);
    if(!temp){
        return;
    }
    while(true){
        if(data <= traverse->data){
            if(!traverse->left){
                traverse->left = temp;
                return;
            }
            traverse = traverse->left;
        }
        else{
            if(!traverse->right){
                traverse->right = temp;
                return;
            }
            traverse = traverse->right;
        }
    }
}

void Node::print(){
    Node* traverse2 = root;
    while(traverse2 != NULL){
        cout<<traverse2->data<<endl;
        traverse2 = traverse2->right;
    }
}

int main(){
    Node bst;
    bst.insert(15);
    bst.insert(29);
    bst.insert(36);
    bst.insert(9);
    bst.insert(3);
    bst.insert(12);
    bst.insert(2);
    bst.print();
    return 0;
}