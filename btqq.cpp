#include <iostream>
#include<vector>
#include<map>
#include<queue>
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
    void solve(Node* root,vector<int>&ans,int level){
        if(root==NULL){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->data);
        
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
        }
    }
    vector<int>leftView(Node*root){
        vector<int>ans;
        solve(root,ans,0);
        return ans;
    }
};
    // vector<int>topview(Node* root){
    //     vector<int>ans;
    //     if(root==NULL){
    //         return ans;
    //     }
    //     map<int,int>topNode;
    //     queue<pair<Node*,int>>q;
    //     q.push(make_pair(root,0));
    //     while(!q.empty()){
    //         pair<Node,int>temp=q.front();
    //         q.pop();
    //         Node*frontNode=temp.first;
    //         int hd=temp.second;
    //         //if(topNode.find(hd)!=topNode.end()){for bottom elements ko print krne ke liye 
    //             topNode[hd]=frontNode->data;
            
    //         if(frontNode->left){
    //             q.push(make_pair(frontNode->left,hd-1));

    //             }
    //         if(frontNode->right){
    //             q.push(make_pair(frontNode->right,hd+1));
    //         }  
    //         for(auto i:topNode){
    //             ans.push_back(i.second);
    //         } 
    //         return ans; 
    //         }

    //     }
    // };

    // vector<int>verticalOrder(Node* root){
    //     map<int,map<int,vector<int>>>nodes;
    //     vector<int>ans;
    //     queue<pair<Node*,pair<int,int>>>q;
    //     if(root==NULL){
    //         return ans;
    //     }
    //     q.push(make_pair(root,make_pair(0,0)));
    //     while(!q.empty()){
    //         pair<Node*,pair<int,int>>temp=q.front();
    //         q.pop();
    //         Node*frontNode=temp.first;
    //         int hd=temp.second.first;
    //         int lvl=temp.second.second;
    //         nodes[hd][lvl].push_back(frontNode->data);//vector ka hi value dalwa rhe h isliye push_back
    //         if(frontNode->left){
    //             q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
    //         }
    //         if(frontNode->right){
    //             q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
    //         }
    //         for(auto i: nodes){
    //             for(auto j:i.second){
    //                 for(auto k:j.second){
    //                     ans.push_back(k);
    //                 }

    //             }

    //         }
    //         return ans;
    //     }
    // }
    // void traversal(Node*root,vector<int> &ans){
    //     if(root==NULL){
    //         return;
    //     }
    //     if(root->left==NULL && root->right==NULL){
    //         return;
    //     }
    //     ans.push_back(root->data);
    //     if(root->left){
    //         traversal(root->left,ans);
    //     }
    //     else{
    //         traversal(root->right,ans);
    //     }
    // }
    // void traversaleaf(Node*root,vector<int> &ans){
    //     if(root==NULL){
    //         return;
    //     }
    //     if(root->left==NULL && root->right==NULL){
    //         ans.push_back(root->data);
    //         return;
    //     }
        
    //    traversaleaf(root->left,ans);
    //    traversaleaf(root->right,ans);
        
       
    // }
    // void traverseR(Node* root,vector<int>ans){
    //     if(root==NULL){
    //         return;
    //     }
    //     if(root->left==NULL && root->right==NULL){
    //         return;
    //     }
    //     if(root->right){
    //         traverseR(root->right,ans);
    //     }
    //     else {
    //         traverseR(root->left,ans);
    //     }
    //     ans.push_back(root->data);
    

//     }
//     vector<int>boundary(Node* root){
//         vector<int>ans;
//         if(root==NULL){
//             return ans;
//         }
//         ans.push_back(root->data);
//         traversal(root,ans);
//         traversaleaf(root->left,ans);
//         traverseR(root->right,ans);
//         return ans;
//     }
//     vector<int>Zig(Node* root){
//         vector<int>result;
//         if(root==NULL){
//             return result;
//         }
//         queue<Node*>q;
//         q.push(root);
//         bool leftToRight=true;
//         while(!q.empty()){
//             int size=q.size();
//             vector<int>ans(size);
//             for(int i=0;i<size;i++){
//                 Node*frontNode=q.front();
//                 q.pop();
//                 int index=leftToRight ? i:size-i-1;
//                 ans[index]=frontNode->data;
//                 if(frontNode->left){
//                     q.push(frontNode->left);
//                 }
//                 if(frontNode->right){
//                     q.push(frontNode->right);
//                 }
//             }


//             leftToRight=!leftToRight;
//             for(auto i:ans){
//                 result.push_back(i);
//             }
//         }
//         return result;
//     }
