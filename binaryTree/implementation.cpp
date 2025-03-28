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
    root = new node(data);
    cout<< "enter the value for left of "<< data<<endl;
    root-> left = buildTree(root->left);
    cout<< "enter the value for right of "<<data<<endl;
    root-> right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();  
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp-> data<<" ";
            if(temp-> left){
                q.push(temp-> left);
        }
     if(temp-> right){
            q.push(temp-> right);
        }
    }
    }
}

void buildLevelOrderTraversal(node* &root){
    queue<node*> q;
    cout<<"Enter the data: "<<endl;
    int data;
    cin>> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
    node* temp = q.front();
    q.pop();

    cout<< "Enter the data for the left node "<<temp-> data<<endl;

    int leftData;
    cin>> leftData;

    if(leftData!=-1){
        temp-> left = new node(leftData);
        q.push(temp-> left);
    }
    cout<<"Enter the data for the right node "<< temp-> data<<endl;
    int rightData;
    cin>>rightData;
    if(rightData!= -1){
        temp-> right = new node(rightData);
        q.push(temp-> right);
    }

}
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<< root-> data<<" ";
    inorder(root-> right);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<< root-> data<<" ";
    preorder(root-> left);
    preorder(root-> right);

}

void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root-> left);
    postorder(root-> right);
    cout<< root-> data<<" ";
}
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main(){
    node* root = NULL;
    // root = buildTree(root);
    //levelOrderTraversal(root);
    buildLevelOrderTraversal(root);
    // levelOrderTraversal(root);
    cout<< "inorder-> "<<endl;
    inorder(root);
    cout<<endl;
    cout<< "preorder-> "<<endl;
    preorder(root);
    cout<<endl;
    cout<< "postorder-> "<<endl;
    postorder(root);
}
 