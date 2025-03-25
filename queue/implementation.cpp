#include <iostream>
using namespace std;

class Queue{
private:
    int data;
    int *arr;
    int front;
    int rear;
    int size;

public:
        Queue(){
            size = 100010;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

    void enqueue(int data){
        if(rear == size){
            cout<< "Queue is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }

    }

    void dequeue(){
        if(front == rear){
            cout<< "Queue is Empty "<<endl;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            cout<< "You dequeued "<<ans<<endl;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            
            }

        }
    }
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

void qfront(){
        if(front == rear){
            cout<< "queue is empty"<<endl;
        }
        else{
            cout<< arr[front]<<" "<<endl;
            
        }

    }

};

int main(){
    Queue* q = new Queue();

    q->enqueue(50);
    q->enqueue(68);
    q->enqueue(74);
    q->qfront();
   
    q->dequeue();
    q->dequeue();
    q->qfront();
    q->dequeue();
    q->qfront();
    cout<< q->isEmpty();

}
