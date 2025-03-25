#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;  
    Node(int d){

        this-> data = d;
        this-> next = NULL;
        this-> prev = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    
    while(temp != NULL){
        cout<< temp-> data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}
void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp-> next = head;
    head-> prev = temp;
    head = temp;

}

void insertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    
    tail-> next = temp;
    temp-> prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &tail,Node* &head,int d,int position){
    if(position==1){
    insertAtHead(head,1);
    return;
    }
    Node *temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp-> next;
        count++;
    }
    if(temp-> next == NULL){
        insertAtTail(tail,d);
        return;
    }
    Node* nodeToInsert = new Node(d);
    nodeToInsert-> next = temp-> next;
    temp-> next-> prev = nodeToInsert;
    temp-> next = nodeToInsert;
    nodeToInsert-> prev = temp;
}

int getLength(Node* &head){
     Node* temp = head;
     int len = 0;
    
    while(temp != NULL){
        len++;
        temp = temp-> next;
    }
    return len;
}

int main(){
    Node* doublyNode = new Node(10);
    Node* head = doublyNode;
    Node* tail = doublyNode;
    print(head);
//   cout<<  getLength(head);
insertAtHead(head,1);
  print(head);
insertAtHead(head,23);
  insertAtTail(tail,80);
  print(head);
insertAtTail(tail,40);
print(head);
insertAtPosition(tail,head,22,2);
print(head);
  
}
