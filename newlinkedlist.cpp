#include<iostream>
#include<string>
using namespace std;

//sorting a linked list??

class Node{
    private:
        Node* head;
        int data;
        Node* next;
    public:
        int addData(int data1);
        int deleteData();
        int deleteData(int data1);
        int printList();
        int searchData(int data2);
        int addDataEnd(int data1);
        Node(){
            head = NULL;
        }
};

int Node::addData(int data1){
    Node* temp = new Node();
    temp->data = data1;
    temp->next = head;
    head = temp;
    return 1;
}

int Node::printList(){
    Node* temp = head;
    cout<<"The linked list is : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 1;
}

int Node::searchData(int data2){
    Node* temp = head;
    bool found = false;
    int nodenum = 1;
    while(temp!=NULL){
        if(temp->data == data2){
            cout<<"The value "<<data2<<" is present in the linked list at node "<<nodenum<<endl;
            found = true;
        }
        temp = temp->next;
        nodenum++;
    }
    if(!found){
        cout<<"The value "<<data2<<" is not present in the linked list"<<endl;
        return 0;
    }
    return 1;
}

int Node::deleteData(int data1){
    Node* temp = head;
    Node* temp2 = NULL;
    if(head == NULL){
        cout<<"The list is empty. No data to be deleted"<<endl;
        return 0;
    }
    if(head->data == data1){
        head = head->next;
        delete temp;
        return 1;
    }
    while(temp!=NULL && temp->data != data1){
        temp2 = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"Error. Reached end of list. Data not found"<<endl;
        return 0;
    }
    temp2->next = temp->next;
    delete temp;
    return 1;
}

int Node::addDataEnd(int data1){
    Node* temp = head;
    Node* temp2 = new Node();
    temp2->data = data1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp2->next = temp->next;
    temp->next = temp2;
    return 1;
}

int main(){
    Node obj;
    obj.searchData(25);
    obj.addData(37);
    obj.addData(25);
    obj.addData(25);
    obj.addData(30);
    obj.addData(198762);
    obj.printList();
    obj.searchData(25);
    obj.searchData(67);
    obj.searchData(89);
    obj.deleteData(37);
    obj.addDataEnd(56);
    obj.printList();
    return 0;
}