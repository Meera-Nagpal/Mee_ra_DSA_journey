#include<iostream>
#include<map>
#include<queue>
using namespace std;
class BTNode{
    public:
    int data;
    BTNode *left;
    BTNode *right;
    BTNode(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};
bool search(BTNode*root,int x){
    BTNode *temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;

    }
    return false;
}
