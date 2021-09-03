#include<iostream>
#include<vector>
using namespace std;


class Hashtable{
    private:
        int n;
        vector<Hashtable*> table;
        int key;
        int data;
        Hashtable* head;
        Hashtable* next;
    public:
        Hashtable(){
            head = NULL;
            n = 10;
        }
        Hashtable(int oit) : table(10, NULL), n(oit), head(NULL) { }
        void hashfunction(int z);
        void insert(int x);
        void exists(int q);
        void deldat(int v);
};

void Hashtable::hashfunction(int z){
    key = (z % n);
}

void Hashtable::insert(int x){
    hashfunction(x);
    Hashtable* temp = new Hashtable();        
    temp->data = x;
    temp->next = head;
    head = temp;
    table[key] = head;
}

void Hashtable::exists(int q){
    bool found = false;
    hashfunction(q);
    Hashtable* tempo = new Hashtable();
    tempo = table[key];
    if(tempo==NULL){                     
        cout<<"No value is initialized. The value does not exist in the hash table."<<endl;
    }
    else if(tempo->next == NULL && tempo->data!=q){            
        cout<<"The value "<<q<<" does not exist in the hash table."<<endl;
    }
    else if(tempo->data == q){        
        cout<<"The value "<<q<<" is found in the hash table at array index "<<key<<endl;
    }
    else{                   
        while(true){
            if(tempo!=NULL){
                if(tempo->data == q){
                    found = true;
                    tempo = tempo->next;
                }
                else{
                    tempo = tempo->next;
                }
            }
            else{
                break;
            }
        }
        if(!found){
            cout<<"The value "<<q<<" does not exist in the hash table"<<endl;
        }
        else{
            cout<<"The value "<<q<<" is found in the hash table at array index "<<key<<endl;
        }
    }
}

void Hashtable::deldat(int v){
    hashfunction(v);
    Hashtable* temps = new Hashtable();
    temps = table[key];
    Hashtable* tempslate = new Hashtable();
    tempslate = NULL; 
    if(temps == NULL){
        cout<<"The value "<<v<<" does not exist in the hashtable."<<endl;
    }
    else if(temps->next == NULL && temps->data!=v){            
        cout<<"The value "<<v<<" does not exist in the hash table."<<endl;
    }
    else if(temps->data == v){        
        head = temps->next;
        temps = NULL;
        table[key] = head;
        cout<<"The value "<<v<<" has been deleted from the hashtable."<<endl;
    }
    else{                   
        while(true){
            if(temps!=NULL){
                if(temps->data == v){
                    tempslate->next = temps->next;
                    temps = NULL;
                    cout<<"The value "<<v<<" has been deleted from the hashtable."<<endl;
                }
                else{
                    tempslate = temps;
                    temps = temps->next;
                }
            }
            else{
                break;
            }
        }
    }
}

int main(){
    Hashtable obj(10);
    int dat;
    while(true){
        cout<<"Enter an integer to insert into the hash table: ";
        cin>>dat;
        if(dat == -1){
            break;
        }
        else{
            obj.insert(dat);
        }
    }
    obj.exists(3);
    obj.exists(13);
    obj.exists(43);
    obj.exists(69);
    obj.deldat(3);
    obj.exists(3);
    return 0;
}

