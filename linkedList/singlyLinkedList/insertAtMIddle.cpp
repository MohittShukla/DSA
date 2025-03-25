#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){

            delete next;
            this->next = NULL;
        

        }
        cout<< "the deleted value is "<< value<<endl;
    }
};

void insertAtBeginning(int data,Node* &head){
    Node* temp = new Node(data);

    temp-> next = head;
    head = temp;
}
void insertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);

    tail -> next = temp;

    tail = tail-> next;

}

void deleteNode(int position,Node* &head){



    if(position == 1){

        Node* temp = head;
        head = head-> next;

        temp-> next = NULL;
        delete temp;
        
    }
    else{
        
        Node* current = head;
           Node* prev = NULL;
           int count = 1;
        while(count<position){
           
            prev = current;
           current = current-> next;
           count++;
        }
        prev-> next = current-> next;
        current-> next = NULL;

        delete current;

    }

}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp-> data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

void insertAtMiddle(Node* &tail,int pos,int data, Node* &head){

    if(pos == 1){
        insertAtBeginning(data,head);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count <= pos-1 && temp->next != NULL){
        temp = temp-> next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }

    Node* newNode = new Node(data);
    newNode -> next = temp-> next;
    temp-> next = newNode;

}

int main(){
    Node* newNode = new Node(12);
    Node* head = newNode;
    Node* tail = newNode;

    insertAtBeginning(25,head);
    insertAtBeginning(32,head);
    insertAtBeginning(43,head);

    print(head);

    insertAtMiddle(tail,2,55,head);
    insertAtMiddle(tail,6,31,head);
    print(head);

     cout<<endl;


    deleteNode(6,head);
    print(head);
}
