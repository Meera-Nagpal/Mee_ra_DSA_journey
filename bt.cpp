#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

Node(int d){
    this->data=d;
    this->left=NULL;
    this->right=NULL;

}  
}; 
Node* buildTree(Node *root){
    cout<<"Enter data= "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for left Node= "<<data;
    root->left = buildTree(root->left);
    cout<<"Enter data for right Node= "<<data;
    root->right = buildTree(root->right);
    return root;

} 
void level(Node* root){
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
void inorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";//recursion ye bolta h ki after return from base case hum recursive call wali statements ko execute krte h aur yahi vo node h .
    inorder(root->right);
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
void postorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(Node* &root){
    queue<Node*>q;
    cout<<"Enter the data for root node"<<endl;
    int data;
    cin>>data;
    root=new Node (data);
    q.push(root);
    //q.push(NULL);
    while(!q.empty()){
    Node*temp=q.front();
     q.pop();
      cout<<"Enter data for left Node="<<temp->data<<endl;
      int leftData;
      cin>>leftData;
      if(leftData!=-1){
      temp->left=new Node(leftData);
      q.push(temp->left);
      }
    cout<<"Enter data for right Node="<<temp->data<<endl;
      int rightData;
      cin>>rightData;
      if(rightData!=-1){
      temp->right=new Node(rightData);
      q.push(temp->right);
     
      }
    }
    }
    
void inorder(Node* root,int &count){
    //base case
    if(root==NULL){
        return;
    }
    
    inorder(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    inorder(root->right,count);
}
int leafNode(Node* &root){
    int count=0;
    inorder(root,count);
    return count;
}
int main(){
    Node* root=NULL;
    levelOrder(root);
    level(root);
   int cnt=leafNode(root);
    cout<<"count is="<<cnt<<endl;
    
    //creating a tree
    // root=buildTree(root);
//78 90 101 7 6 56 79 4 8 3 1
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout<<"printing the level"<<endl;
    // level(root);
    // cout<<"inorder traversal= "<<endl;
    // inorder(root);
    // cout<<"preoder traversal= "<<endl;
    // preorder(root);
    // cout<<"postoder traversal= "<<endl;
    // postorder(root);

    return 0;
}