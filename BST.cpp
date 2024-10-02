#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node *left, *right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public: 

    Node* insertInBST(Node* root, int key){

        Node* temp = new Node(key);
        
        if(root == NULL){
            return temp;
        }

        if(key > root->data){
            root->right = insertInBST(root->right, key);
        }else{
            root->left = insertInBST(root->left, key);
        }

        return root;
    }

    void print(Node* root){
        if(root==NULL)return;
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }

    Node* deletionInBst(Node* root, int key){
        if(root == NULL)return root;

        //find the key in BST: 
        if(key < root->data){
            root->left = deletionInBst(root->left, key);
            return root;
        }else if(key == root->data){
            
            if(root->left == NULL and root->right == NULL){
                delete root;
                return NULL;
            }else if(root->left != NULL and root->right == NULL){
                //find the potential person which we can remove 
                Node* temp = root->left;
                delete root;
                return temp;
            }else if(root->left == NULL and root->right != NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }else{
                Node* temp = root->left;
                while(temp->right){
                    temp=temp->right;
                }
                root->data = temp->data;
                root->left = deletionInBst(root->left, temp->data);
                return root;
            }

        }else{
            root->right = deletionInBst(root->right, key);
            return root;
        }
    }

};

int main(){
    
    BST bst;

    Node *root = NULL;
    int key;cin>>key;
    while(key!=-1){
        root = bst.insertInBST(root, key);
        cin>>key;
    }

    bst.print(root);

    //i want to delete some number from the bst: 
    int d;cin>>d;
    root = bst.deletionInBst(root,d);

    bst.print(root);

    return 0;
}