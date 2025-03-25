#include<iostream>
#include<string>
using namespace std;

class Teacher{
public:
    string name;
    string lastName;
    float salary;

    void print(){

        cout<< name<< lastName;
       
    }



};


int main(){
    Teacher t1;
    t1.name = "Mohit";
    t1.lastName= "shukla";
    t1.print();



}
