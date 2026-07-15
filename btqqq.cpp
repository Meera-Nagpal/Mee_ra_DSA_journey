#include <iostream>
#include<vector>
#include<map>
#include<queue>
#include<climits>
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
    public:
    Node* solve(Node* root,int &k,int n){
        if(root==NULL){
         return NULL;
    }
    if(root->data==n){
        return root;
    }
    Node*leftAns=solve(root->left,k,n);
    Node*righttAns=solve(root->right,k,n);
     if(leftAns!=NULL && righttAns!=NULL){
        return root;
    }
    if(leftAns!=NULL && righttAns==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;//ye isliye ki ek baar 0 ho bhi gyi value k ki to dubara na ho its like usse 0 se dur rakhne ke liye ye kiya 
            return root;
        }
        return leftAns;
    }
    if(righttAns!=NULL && leftAns==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return righttAns;
    }
    else{
        return NULL;
    }
    }
    int kA(Node*root,int k ,int n){
        Node* ans=solve(root,k,n);
        if(ans==NULL || ans->data==n){ //jab ans hi node hogyi to vo process nhi hoga cuz kshould be between 1-100 and uss case mai 0 hojayega ){
            return -1;
        }
        else{
           return ans->data;
        }
    }

};
    // void solve(Node*root,int &count,int k,vector<int>path){
    //     if(root==NULL){
    //         return ;
    //     }
    //     path.push_back(root->data);
    //     solve(root->left,count,k,path);
    //     solve(root->right,count,k,path);
    //     int size=path.size();
    //     int sum=0;
    //     for(int i=size-1;i>=0;i--){
    //         sum+=path[i];
    //         if(sum==k);
    //         count++;
    //     }
    //     path.pop_back();
    // }
    // int sumK(Node*root,int k){
    //     vector<int>path;
    //         int count=0;
    //     solve(root,count,k,path);
    //     return count;
    // }

    // Node* lca(Node* root,int n1,int n2){
    //     if(root==NULL){
    //      return NULL;
    // }
    // if(root->data==n1|| root->data==n2){
    //     return root;
    // }
    // Node*leftAns=lca(root->left,n1,n2);
    // Node*righttAns=lca(root->right,n1,n2);
    //  if(leftAns!=NULL && righttAns!=NULL){
    //     return root;
    // }
    // if(leftAns!=NULL && righttAns==NULL){
    //     return leftAns;
    // }
    // if(righttAns!=NULL && leftAns==NULL){
    //     return righttAns;
    // }
    // else{
    //     return NULL;
    // }

    // }


//     void Solve(Node* root,int sum,int &maxsum,int len,int &maxlen)
//     {
//         if(root==NULL){
//             if(len>maxlen){
//                 maxlen=len;
//                 maxsum=sum;
//             }
//             else if(len==maxlen){
//                 maxsum=max(sum,maxsum);
//             }
//             return;
//         }
//         sum=sum+root->data;
//         Solve(root->left,sum,maxsum,len+1,maxlen);
//         Solve(root->right,sum,maxsum,len+1,maxlen);
//     }
//     int sum(Node* root){
//         int sum=0;
//         int maxsum=INT_MIN;
//         int len=0;
//         int maxlen=0;
//         Solve(root,sum,maxsum,len,maxlen);
//         return maxsum;
//     }
// };