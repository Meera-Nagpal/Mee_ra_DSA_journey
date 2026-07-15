#include <iostream>
#include <map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
Node(int d){
    this->data=d;
    this->next=NULL;
}
};
Node*findMid(Node*&head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        
    }
    return slow;
}
Node* mergeSort(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    else{
        Node* mid=findMid(head);
        Node*left=head;
        Node*right=mid->next;
        mid->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        Node*result=merge(left,right);
        return result;
}      
    }
    
Node*merge(Node*left,Node*right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node*ans=new Node(-1);
    Node*temp=ans;
    while(left!=NULL&& right!=NULL){
        if(left->data<right->data){
            temp->next=left;
            left=temp;
            left=left->next;
        }
        if(right->data<left->data){
            temp->next=right;
            right=temp;
            right=right->next;
        }
    }
     while(left!=NULL){
        
            temp->next=left;//ye additions ans wali LL ke andar hi hora h cuz temp mai ans hi stored h aur jo mujhe dount tha ki temp ko kyu nhi badharhe vo aap dekho hsr itersrtion mai ans ko next kr rhe hai.
            left=temp;
            left=left->next;
     }
     while( right!=NULL){
        temp->next=right;
        right=temp;
        right=right->next;
     }
    ans=ans->next;
     return ans;
}
void insertatTail(Node* &head,Node*&tail,int d){
    Node *temp=new Node(d);
    if(head==NULL){
        head=temp;//jab single element hoga tab ussi ko head aur tail lenge aur return kr jayenge.
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* copyList(Node*&head){
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    Node* temp=head;
    while(temp!=NULL){
    insertatTail(cloneHead,cloneTail,temp->data);
    temp=temp->next;  
  }
  //O(1) memory wala logic h ye
    Node* ogNode=head;
    Node* clNode=cloneHead;
    while(ogNode!=NULL && clNode!=NULL){
        Node*next=ogNode->next;
        ogNode->next=clNode;
        ogNode=next;

        next=clNode->next;
        clNode->next=ogNode;
        clNode=next;
     }
     //randpm pointer copy

  //map create
//   map<Node*,Node*>oldToNew;
//   Node* ogNode=head;
//   Node* clNode=cloneHead;
//   while(ogNode!=NULL){
//     oldToNew[ogNode]=clNode;
//     ogNode=ogNode->next;
//     clNode=clNode->next;
//   }
//   ogNode=head;
//   clNode=cloneHead;
//   while(ogNode!=NULL){
//     clNode->random=oldToNew[ogNode->random];
//     ogNode=ogNode->next;
//     clNode=clNode->next;

//   }
//   return clNode;
}


int main(){
     Node* node1=new Node(3);
     Node* node2=new Node(4);
    cout<<node1->data<<endl;
    cout<<(*node1).next<<endl;
    Node *head=node1;
    

    
    print(head);

    
    print(head);
    Node *tail=node1;
    Node *tail2=node2;
    
    
   
    print(head);