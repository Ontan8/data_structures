#include<iostream>
#include<string>
using namespace std;

struct Node{
    private:
        int data; //value to be inserted into the binary tree
        Node* left{NULL}; //pointing to the left subtree
        Node* right{NULL}; // pointing to the right subtree
    public:
        Node* setData(int data); //requires the insert function if root is not null
        void insert(int data); //requires the setData function to return the address of the pointer
        void print();
        bool searchData(int data); 
};

Node* root = NULL; //this points to the root of the binary search tree

Node* Node::setData(int data){
    Node* temp = new Node();
    temp->data = data;
    if(!root){
        root = temp;
        return NULL;
    }
    return temp;
}

void Node::insert(int data){
    Node* temp = setData(data);
    Node* traverse = root;
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

bool Node::searchData(int data){
    Node* temp = root;
    while(temp){
        if(data == temp->data){
            cout<<"data found"<<endl;
            return true;
        }
        temp = (data <= temp->data) ? temp->left : temp->right;
    }
    cout<<"data not found" <<endl;
    return false;
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
    bst.insert(598);
    bst.insert(1);
    bst.searchData(598);
    bst.searchData(12);
    bst.searchData(2);
    bst.searchData(4);
    bst.print();
    return 0;
}