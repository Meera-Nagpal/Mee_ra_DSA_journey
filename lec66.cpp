#include<iostream>
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
    // int findPos(int in[],int element,int n){
    //     for(int i=0;i<n;i++){
    //         if(in[i]==element){
    //             return i;
    //         }
    //         }
    //     return -1;
    // }
    Node*createParentMap(Node* root,int target,map<Node*,Node* >&nodetoParent){
    Node* res=NULL;
    nodetoParent[root] =NULL;   
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
       
        Node* front=q.front();
        q.pop();
        if(front->data==target){
            res=front;

        }
        if(front->left){
            nodetoParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodetoParent[front->right]=front;
            q.push(front->right);
        }
        
        

    }
    return res;
    }
    int burnTree(Node* root, map<Node*,Node* >&nodetoParent){
        map<Node*,bool>visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=true;
        int ans=0;
        
        while(!q.empty()){
            bool flag=false;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    flag=true;
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right && !visited[front->right]){
                    flag=1;
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(nodetoParent[front] && !visited[nodetoParent[front]]){
                    flag=1;
                  q.push(nodetoParent[front]);
                  visited[nodetoParent[front]]=true;
                }
                
            }
            if(flag==1){
                ans++;
            }
            
        }
        return ans;
    }
    int minTime(Node* root,int target){
        int ans=0;
        map<Node*,Node*>nodetoParent;
        Node*targetNode=createParentMap(root,target,nodetoParent);
        if(targetNode==NULL){
            return 0;
        }
        ans=burnTree(targetNode,nodetoParent);
        return ans;
    }
    void createMap(int in[],map<int,int>&nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
                
            }
    }
    Node* solve(int in[],int post[],int &index,int inorderstart,int inorderend,int n,map<int,int>nodeToIndex){
        if(index<=0||inorderstart>inorderend){
            return NULL;
        }
        int element=post[index--];
        Node * root=new Node(element);
        int posi=nodeToIndex[element];
        //int posi=findPos(in,element,n);
        root->right=solve(in,post,index,posi+1,inorderend,n,nodeToIndex);
        root->left=solve(in,post,index,inorderstart,posi-1,n,nodeToIndex);
       
        return root;

    }

    Node*buildTree(int in[],int post[],int n){
        int postOrder=n-1;
        map<int,int>nodetoIndex;
        createMap(in,nodetoIndex,n);
        Node* ans=solve(in,post,postOrder,0,n-1,n,nodetoIndex);
        return ans;
    }
};