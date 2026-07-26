#include<iostream>
#include<map>
#include<climits>
#include<vector>
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
void inorder(Node* &root,vector<int>&in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

}
Node* flatten(Node* root){
    vector<int>v;
    inorder(root,v);
    Node* newroot=new Node(v[0]);
    Node* curr=newroot;
    for(int i=1;i<v.size();i++){
        Node* temp=new Node(v[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    //4rd step
    curr->left=NULL;
    curr->right=NULL;
    return newroot;     
}
Node* inBST(int s,int e,vector<int>v){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    Node* root=new Node(v[mid]);
    root->left=inBST(s,mid-1,v);
    root->right=inBST(mid+1,e,v);
    return root;
}
Node* balanced(Node* root){
    vector<int>v;
    inorder(root,v);
    return inBST(0,v.size()-1,v);
}
Node*solve(vector<int>&preorder,int mini,int maxi,int &i){
    if(i>preorder.size()){
        return NULL;
    }
    if(maxi<preorder[i] || mini>preorder[i]){
        return NULL;
    }
    Node* root=new Node(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->left=solve(preorder,root->data,maxi,i);
    return root;

}
Node*preorder(vector<int>&preorder){
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}
bool inOrder(Node* root,int target){
    vector<int>v;
    inorder(root,v);
    int i=0,j=v.size()-1;
    while(i<j){
        int sum=v[i]+v[j];
        if(sum==target){
            return true;
        }
        else if(sum<target){
            i++;
        }
        else{
            j--;
        }


    }
}