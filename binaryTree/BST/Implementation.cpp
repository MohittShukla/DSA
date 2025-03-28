#include <iostream>
#include<queue>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    
};

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data ){
       root->right =  insertIntoBST(root->right,data);
    }
    else{
       root->left =  insertIntoBST(root->left,data);
    }
    return root;

}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();  
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
void takeInput(Node* &root){
    int data;
    cin>> data;
    while(data != -1){
       root = insertIntoBST(root,data);
        cin>>data;
    }
}
int main(){
    Node* root = NULL;
    cout<<"Enter the element "<<endl;
    takeInput(root);
    levelOrderTraversal(root);
}
