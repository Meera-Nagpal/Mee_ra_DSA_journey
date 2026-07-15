#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;


Node(int d){
  this->data=d;
  this->prev=NULL;
  this->next=NULL;
}
~Node(){
    int value=this->data;
    if(next!=NULL){
        delete next;
        next=NULL;
    }
cout<<"memory free for node with data="<<value<<endl;
}
};
void print(Node * head){
    Node*temp=head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<endl;
}
int getlen(Node*head){
    int len=0;
    Node*temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertatHead(Node* &head,Node* &tail,int d){
    //empty list case
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;

    }
    else{
    Node* temp=new Node(d); 
    temp->next=head;
    head->prev=temp;
    head=temp;

    }
}
void insertatTail(Node* &head,Node* &tail,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;

    }
    else{
    Node *temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
}
 void insertatMiddle(Node*&head,int position,int d){
    Node*temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    Node*Nodetoinsert=new Node(d);      //temp->next;wrong
    Nodetoinsert->next=temp->next;
    temp->next->prev=Nodetoinsert;
    temp->next=Nodetoinsert;
    Nodetoinsert->prev=temp;
}
void deleteNode(Node*head,int position){
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    delete temp;  
  }
    else{
        Node*curr=head;
        Node*prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;

        }
        curr->prev=NULL;

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main(){
Node* node1=new Node(10);
Node* head=NULL;
Node* tail=NULL;
print(head);
cout<<getlen(head)<<endl;
insertatHead(head,tail,40);
insertatHead(head,tail,80);
insertatTail(head,tail,60);
insertatMiddle(head,2,77);
insertatMiddle(head,3,67);
insertatMiddle(head,4,97);
deleteNode(head,3);
print(head);
cout<<head->data<<endl;
cout<<tail->data<<endl;
return 0;
}