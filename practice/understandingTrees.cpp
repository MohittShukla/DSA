#include<iostream>
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

int height(node* &root){
    if(root == NULL){
        return 0;
    }
    cout<< " currently i am  at   "<< root->data<<endl;
    int left = height(root->left);
    int right = height(root->right);
    cout<< "now i am at "<< root->data<<endl;
    int i = 0;
    int ans = 1 + max(left,right);
    cout<< "the value is "<<ans<<endl;
    return ans;
}

void inorder(node* &root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}
node* buildTree(node* root){
    cout<< "enter the data: "<<endl;
    int data;
    cin>> data;
    if(data == -1){
       
        return NULL;
    }
    root = new node(data);
     
    cout<< "enter the value for left of "<< data<<endl;
   
    root-> left = buildTree(root->left);
    
    cout<< "enter the value for right of "<<data<<endl;
    
    root-> right = buildTree(root->right);
    return root;
}
// 5 10 7 6 -1 -1 2 -1 -1 4 -1 -1 8 9 4 -1 -1 -1 11 21 -1 -1 22 -1 -1

int main(){
    node* root = NULL;
    root = buildTree(root);
    inorder(root);
    cout<<endl;
    cout<< height(root);
    return 0;
}
