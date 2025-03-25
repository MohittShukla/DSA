#include <iostream>
#include<queue>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this-> data = d;
        this-> left = NULL;
        this-> right = NULL;
    }
    
};
node* buildTree(node* root){
    cout<< "enter the data: "<<endl;
    int data;
    cin>> data;
    if(data == -1){
        return NULL;
    }
    cout<<"your data is -> "<<data<<endl;
    root = new node(data);
    cout<< "enter the value for left of "<< data<<endl;
    root-> left = buildTree(root->left);
    cout<< "enter the value for right of "<<data<<endl;
    root-> right = buildTree(root->right);
    return root;
}
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<< root-> data<<" ";

    inorder(root-> right);
}

int main(){
    node* root = NULL;
     root = buildTree(root);
    
    cout<< "inorder-> "<<endl;
    inorder(root);
   
}
