#include<iostream>
#include<map>
#include<queue>
#include<climits>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};
void flatten(Node* root){
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left){
            Node* pred=curr->left;
            while(pred->right){
                pred=pred->right;
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
        curr=root;
        while(curr!=NULL){
            curr->left=NULL;
            curr=curr->right;
        }

    }
}
int solve(Node* root,int &i,int k ){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,i,k);
    if(left!=-1){
        return;
    }
    i++;
    if(i==k){
        return root->data;
    }
    int right=solve(root->right,i,k);
}
int kth(Node*root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;

}
pair<int,int>pre(Node*root,int key){
    Node* temp=root;
    int pred=-1;
    int succ=-1;
    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data; 
            temp=temp->right;
        }
    }
    Node*leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    Node* rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    pair<int,int>ans=make_pair(pred,succ);
    return ans;
}
Node* cA(Node * root,Node*P,Node*Q){
    while(root!=NULL){
        
    
    if(root->data>P->data && root->data>Q->data){
    //return cA(root->left,P,Q);
    root=root->left;
}
    if(root->data<P->data && root->data<Q->data){
    //return cA(root->right,P,Q);
    root=root->right;
}
return root;
}
}
bool isBST(Node* &root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data<=max && root->data>=min){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left&&right;
    }
    else{
        return false;
    }

}
bool validate(Node* root){
    return isBST(root,INT_MIN,INT_MAX); 
}