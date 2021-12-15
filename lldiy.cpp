#include<iostream>
#include<cstring>
using namespace std;


class Node{
    private:
        int data;
        Node* next;
        Node* head;
        Node* tail; 
        // int size;
    public:
        void Insert(int z);
        void Insert(int z, int n);
        void Print();
        void findTail();
        void searchData(int ser);
        void searchByNode(int nodenum);
        void reverseList();
        void deleteData(int deldat);
        void deleteNode(int delndnum);
        Node(){
            head = NULL;
        }
};

void Node::Insert(int z){
    Node* temp = new Node();       //temp->next will point to current head and curr. head will be shifted to the temp so that at the first iteration the current head becomes tail and at each succession new head is added.
    temp->data = z;
    temp->next = head;      
    head = temp;                          
}

void Node::Insert(int z, int n){
    Node *temp3 = new Node();
    temp3->data = z;
    temp3->next=NULL;
    if(n==1){
        temp3->next = head;
        head = temp3;
    }  
    Node* temp4 = head;
    
}

void Node::Print(){
    Node* temp2 = head;
    cout<<"The list is: ";
    while (temp2!=NULL)
    {
        cout<<temp2->data<<" ";
        temp2 = temp2->next;
    }
    cout<<"\n";
}

void Node::findTail(){
    if(head == NULL){
        cout<<"The linked list is empty and tail cannot be computed."<<endl;
    }
    else{    
    Node* tailPH = head;
    while(tailPH->next!=NULL){
        tailPH = tailPH->next;
    }
    // i do not know what i am doing in the next line so if anything breaks then just comment it out
    tail = tailPH;
    cout<<"\nThe value at head is: "<<head->data;
    cout<<"\nThe value at tail is: "<<tailPH->data<<endl;  //the data at the tail of the linked list
    //cout<<"\n"<<&tailPH;}      //the memory location of the tail placeholder declared which holds 
                               //data of the tail of the linked list
}
}

//code to search a particular value in the linked list and return the node at which the vallue is stored //IF it is stored

void Node::searchData(int ser){
    Node* tempser = head;
    int nodecount = 1;
    bool found;
    if(head == NULL){
        cout<<"The linked list is empty."<<endl;
            }
    else{
    while(true){
        if(tempser==NULL && !found){
            cout<<"The value does not exist in the linked list."<<endl;
            break;
        }
        else if(tempser==NULL && found){
            break;
        }
        else{
        if(tempser->data == ser){
            cout<<"The value exists in the linked list at the node: "<<nodecount<<endl;
            nodecount++;
            tempser = tempser->next;
            found = true;
        }
        else{
            tempser = tempser->next;
            nodecount++;
        }
        }
    }
        }
}

void Node::searchByNode(int nodenum){
    Node* tempo = head;
    for(int j = 1; j < nodenum; j++){
        tempo = tempo->next;
    }
    cout<<"The value at node "<<nodenum<<" is "<<tempo->data<<endl;;
}

void Node::reverseList(){
    Node* current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        }
    //i do not know what i am doing below NVM it worked
    current = head;
    head = tail;
    tail = current;    
}

// redo this with the delete keyword later on 
void Node::deleteData(int deldat){
    Node* first = head->next;
    Node* second = head;
    if(head == NULL){
        cout<<"The linked list is empty and data cannot be deleted."<<endl;
    }
    else{
    while(true){
        if(second->data == deldat){
        second = NULL;
        second = first;
        head = second;
        first = first->next;
        }
        else if(first->data == deldat && first->next == NULL){
            second->next = first->next;
            first = NULL;
            break;
        }
        else if(first->next == NULL){
            break;
        }
        else if(first->data == deldat){
            second->next = first->next;
            first = NULL;    //dunno just uncommented this
            first = second->next;
            first = first->next;
            second = second->next;
        }
        else{
            first = first->next;
            second = second->next;
        }
    }
    }
}

void Node::deleteNode(int delndnum){
    Node* firstn = head->next;
    Node* secondn = head;
    for(int z = 0; z < delndnum-2; z++){
        firstn = firstn->next;
        secondn = secondn->next;
    }
    secondn->next = firstn->next;
    firstn = NULL;
}

int main(){
    Node obj;
    int size;
    cout<<"Enter the number of itegers you want to add to the linked list:  ";
    cin>>size;
    int x;
    for(int i = 0; i < size; i++)
    {
        cout<<"\nEnter the number: ";
        cin>>x;
        obj.Insert(x);
        obj.Print();
    }
    obj.findTail();
    obj.searchData(3);
    obj.searchByNode(2);
    obj.reverseList();
    obj.Print();
    obj.deleteData(3);
    obj.Print();
    obj.deleteNode(2);
    obj.Print();
    return 0;
}