#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};


class Solution{
    private:
    int height(Node* node){
        if(node==NULL){
            return 0;
        }
        int left=height(node->left);
        int right=height(node->right);
        return max(left,right)+1;
    }
    public:
    pair<bool,int>isSum(Node *root){
        if(root==NULL){
             pair<int,int>p=make_pair(true,0);
             return p;

        }
        pair<int,int>left=isBalancedFast(root->left);
        pair<int,int>right=isBalancedFast(root->right);
        bool leftAns=left.first;
        bool rightAns=right.first;
        bool cond=root->data==left.second+right.second;
        pair<bool,int>ans;
         if(leftAns && rightAns && cond){
            ans.first=true;
            ans.second=root->data+left.second+right.second;
        }
        else{
            ans.first=false;
        }
        return ans;

    }
    bool isSumtree(Node *root){
        return isSum(root).first;
    }
    bool identical(Node* r1,Node* r2){
        if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1!=NULL && r2==NULL || r1!=NULL && r1==NULL ){
            return false;
        }
        else{
            bool left=identical(r1->left,r2->left);
            bool right=identical(r1->right,r2->right);
            bool value=r1->data==r2->data;
            if(left && right && value ){
                return true;
            }
            else{
                return false;
            }
        }
    }
    pair<int,int>isBalancedFast(Node* root){
        if(root==NULL){
            pair<int,int>p=make_pair(true,0);
        }
        pair<int,int>left=isBalancedFast(root->left);
        pair<int,int>right=isBalancedFast(root->right);
        bool leftAns=left.first;
        bool rightAns=right.first;
        bool diff=abs(left.second+right.second)<=1;
        pair<bool,int>ans;
        ans.second=max(left.second,right.second)+1;
        if(leftAns && rightAns && diff){
           ans.first=true;
        }
        else{
             ans.first=false;
        }
        
        return ans;
    }
    bool isBalanced(Node *root){
        if(root==NULL){
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
         
        if(left && right && diff){
            return 1;
        }
        else{
            return false;
        }
    }
    pair<int,int>diameterFast(Node * root){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int ,int>left=diameterFast(root->left);
        pair<int ,int>right=diameterFast(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second + right.second +1 ;
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    int diameter(Node *root){
        return diameterFast(root).first;
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int op1=diameter(root->left);
    //     int op2=diameter(root->right);
    //     int op3=height(root->left)+height(root->right)+1;
    //     int ans=max(op1,max(op2,op3));
    //     return ans;
     }
};
int main(){

}