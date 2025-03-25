#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};



void insertAtBeginning(int data,Node* &head){
    Node* temp = new Node(data);

    temp-> next = head;
    head = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<< temp-> data<<" ";
        temp = temp-> next;
    }
    cout<<endl;

}

int main(){
    Node* p = new Node(232);


    Node* head = p;

    print(head);


    insertAtBeginning(12,head);
    insertAtBeginning(123,head);
    
    print(head);

}
