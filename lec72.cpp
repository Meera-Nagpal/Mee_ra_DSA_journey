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
vector<int>mergeArrays(vector<int>bst1,vector<int>bst2){
      vector<int>ans(bst1.size()+bst2.size());
      int i=0,j=0,k=0;
      while(i<bst1.size()&& j<bst2.size()){
        if(bst1[i]<bst2[j]){
            ans[k++]=bst1[i];
             i++;
        }
        else{
            ans[k++]=bst2[j];
            j++;
        }
        while(i<bst1.size()){
            ans[k++]=bst1[i];
            i++;
            

        }
        while(j<bst2.size()){
            ans[k++]=bst2[j];
            j++;
        }
      }
}
Node* mergeBST(Node*root1,Node* root2){
    vector<int>bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    mergeArrays(bst1,bst2);
}