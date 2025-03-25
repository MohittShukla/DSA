#include<iostream>
using namespace std;

class Queue{
    private:

    int size;
    int* arr;
    int front;
    int rear;
public:
    Queue(){
        size = 10001;
        arr = new int[size];
        front = rear = -1;
    }
void enqueue(int value){
    if(front == 0 && rear == size-1 || (rear+1)%size == front){
        cout<< "Queue is full";
    }
    else if(rear == size-1 && front!= 0){
        rear = 0;
        arr[rear] = value;
        
    }
    else if(front == -1){
        front = rear = 0;
        arr[rear] = value;
      
    }
    else{
        arr[rear] = value;
        
        rear = (rear + 1) % size;
    }
    cout<<"You enqueued "<<value<<"\n";
}
int dequeue(){
    if(front == -1){
        cout<<"Queue is empty ";
        return -1;
    }
    int ans = arr[front];
    arr[front] = -1;
  if(front == rear){
        front =rear= -1;
    }
   else if(front == size-1){
        front = 0;
    }
    else{
        front++;
    }
    return ans;
}
};


int main(){
    Queue* qp = new Queue();
   
    qp-> enqueue(64);
    qp->enqueue(55);
    qp->enqueue(45);
 
   qp->dequeue();
   qp->dequeue();
   qp->dequeue();
   qp->dequeue();
};
