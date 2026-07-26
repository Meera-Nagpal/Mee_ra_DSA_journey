#include<iostream>
#include<map>
#include<queue>
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
Node* minValue(Node* root){
    Node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxValue(Node* root){
    Node *temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
Node* deleteBST(Node* &root,int data){
    if(root==NULL){
        
        return root;
    }
    if(root->data==data){
        //0child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //rightchild
        if(root->left==NULL && root->right!=NULL){
            Node*temp=root->right;
            delete root;
            return temp;
        }
        //2child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minValue(root->right)->data;
            root->data=mini;//humne root ko replace krwa diya smalklesr value in right se
            root->right=deleteBST(root->right,mini);
        }
    }
    if(data>root->data){
        root->right=deleteBST(root->right,data);
    }
     if(data<root->data){
        root->left=deleteBST(root->left,data);
    }
    return root;
}
// bool searchinBST(Node* root,int x){
    
//      if(root==NULL){
//         return false;
//     }
//     if(root->data==x){
//         return true;
//     }
//     if(root->data>x){
//         return searchinBST(root->left,x);
//     }
//     else{
//         return searchinBST(root->right,x);
//     }
// }

    
   
Node* insertinBST(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        root->right=insertinBST(root->right,data);
        return root;
    }
    else {
        root->left=insertinBST(root->left,data);
        return root;
    }
    return root;

}
void preorder(Node* root){
    //base case
    if(root!=NULL){
        cout<<root->data<<" ";
    }
    else if(root==NULL){
        return;
    }
    //recursive call ke upar vo sab saari baar implement hoga jitni baar call hoga recursion. uske baad ki statement ki koi value nhi hai before return .
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";//recursion ye bolta h ki after return from base case hum recursive call wali statements ko execute krte h aur yahi vo node h .
    inorder(root->right);
}
void postorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void level(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    }
    
}
void takeInput(Node * &root){
    int data;
    cin>>data;
    while(data!=-1){
        insertinBST(root,data);
        cin>>data;
    }
}

int main(){
    Node* root=NULL;
    cout<<"Enter the data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    level(root);
    insertinBST(root,67);
    cout<<"Printing the BST"<<endl;
    level(root);
   
    cout<<"Printing the BST in preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Printing the BST in inorder"<<endl;
    inorder(root); 
    cout<<endl;
    cout<<"Printing the BST in postorder"<<endl;
    postorder(root);
    root=deleteBST(root,5);
     cout<<"Printing the BST"<<endl;
    level(root);
   
    cout<<"Printing the BST in preorder"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Printing the BST in inorder"<<endl;
    inorder(root); 
    cout<<endl;
    cout<<"Printing the BST in postorder"<<endl;
    postorder(root);
    return 0;
}