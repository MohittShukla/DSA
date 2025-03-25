#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

      Node(int data){
        this-> data = data;
      }


};

void insertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);

    tail -> next = temp;

    tail = tail-> next;

}

void print(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<< temp->data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

int main(){
    Node* p = new Node(13);

        Node* head = p;
        Node* tail = p;

        insertAtTail(tail,20);
        print(head);
        insertAtTail(tail,23);
        print(head);
        insertAtTail(tail,53);
        print(head);

}
