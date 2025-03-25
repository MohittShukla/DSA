#include <iostream>
using namespace std;

class Stack{
    int* arr;
    int top;
    int size;
    public:
    Stack(int size){
        this-> size = size;
        arr = new int[size];
        top = -1;
    }


    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow "<<endl;
        }
    }
    void pop(){
        if(top>= 0){
            top--;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    int peek(){
        if(top>0)
        return arr[top];
    else{
        cout<< "Stack is empty";
        return -1;
    }
    }

    bool isEmpty(){
        if(top<=0){
            return true;
        }
        else{
            return false;
        }
    }


};

int main(){
    Stack st(6);
    st.push(22);
    st.push(4);
    st.push(9);
    st.push(69);

    cout<< st.peek()<<""<<endl;
    st.pop();
   cout<< st.peek()<<""<<endl;
       st.pop();
          st.pop();

   st.pop();
   st.pop();
   cout<< st.peek()<<""<<endl;
   
}


 
