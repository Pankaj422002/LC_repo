#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data,height;
    Node* left, *right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
        this->height=1;
    }
};


class AVL_Tree{
    public:
    
    int height(Node* root){
        if(root==NULL)return 0;
        return root->height;
    }

    Node* LeftRotate(Node* root){
        Node *temp = root->right;
        root->right = temp->left;
        temp->left = root;

        root->height = 1+max(height(root->left), height(root->right));
        temp->height = 1+max(height(temp->left), height(temp->right));

        return temp;
    }

    Node* RightRotate(Node* root){
        Node *temp = root->left;
        root->left = temp->right;
        temp->right = root;

        root->height = 1+max(height(root->left), height(root->right));
        temp->height = 1+max(height(temp->left), height(temp->right));

        return temp;
    }

    Node* insert(Node *root, int key){
        Node* temp = new Node(key);
        if(root == NULL){
            return temp;
        }

        if(root->data < key){
            root->right = insert(root->right, key);
        }else if(root->data > key){
            root->left = insert(root->left, key);
        }

        root->height = 1+max(height(root->left), height(root->right));
        int balance_factor = height(root->left) - height(root->right);

        if(balance_factor > 1){
            //left if greater than right:
            if(root->left->data > key){
                //LL: rotate right and change the height
                return RightRotate(root);
            }else{
                //LR: 
                root->left = LeftRotate(root->left);
                return RightRotate(root);
            }
        }
        if(balance_factor < -1){
            //right is greater than left: 
            if(root->right->data > key){
                //RL: 
                root->right = RightRotate(root->right);
                return LeftRotate(root);
            }else{
                //RR: 
                return LeftRotate(root);
            }
        }

        return root;
    }

    void print(Node *root){
        if(root==NULL)return;
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }

    int getDifference(Node* root){
        if(root==NULL)return 0;
        return height(root->left)-height(root->right);
    }

    Node* deleteInAVL(Node *root, int key){
        if(root == NULL)return root;

        if(root->data > key){
            root->left = deleteInAVL(root->left, key);

        }else if(root->data < key){
            root->right = deleteInAVL(root->right, key);
            
        }else{

            if(root->left == NULL and root->right == NULL){
                root=NULL;
            }else if(root->left != NULL and root->right == NULL){
                Node* temp = root;
                root = root->left;
                free(temp);
            }else if(root->left == NULL and root->right != NULL){
                Node* temp = root;
                root = root->right;
                free(temp);
            }else{
                
                Node* temp = root->left;
                while(temp->right){
                    temp=temp->right;
                }
                root->data = temp->data;
                root->left = deleteInAVL(root->left, temp->data);
            }

        }

        //after delete : ON returing ==> 
        if(root == NULL)return root;

        root->height = 1+max(height(root->left), height(root->right));

        int balance_factor = height(root->left) - height(root->right);

        if(balance_factor > 1){
            //left is greater : 
            if(getDifference(root->left) > 0){
                //LL: 
                return RightRotate(root);
            }else{
                //LR: 
                root->left = LeftRotate(root->left);
                return RightRotate(root);
            }
        }
        if(balance_factor < -1){
            //right is greater: 
            if(getDifference(root->right) > 0){
                //RL: 
                root->right = RightRotate(root->right);
                return LeftRotate(root);
            }else{
                //RR: 
                return LeftRotate(root);
            }
        }
        return root;
    }

};

int main(){

    AVL_Tree avl;
    Node* root=NULL;

    int n;cin>>n;
    while(n--){
        int ip;cin>>ip;
        root=avl.insert(root,ip);
    }

    avl.print(root);

    int d;cin>>d;
    root = avl.deleteInAVL(root,d);
    avl.print(root);

    return 0;
}