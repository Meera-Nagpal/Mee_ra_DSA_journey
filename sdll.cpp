#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node*prev;
Node(int d){
    this->data=d;
    this->next=NULL;
    this->prev=NULL;
}
~Node(){
    int value=this->data;
    if(this->next!=NULL){
        delete next;
        this->next=NULL;
    }
    cout<<"Value deleted for="<<value<<endl;
}
};
void insertatHead(Node* &head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertatTail(Node* &tail,int d){
    Node*temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertatPosition(Node* &head,Node* &tail,int position,int d){
    if(position==1){
        insertatHead(head,d);
    }
    else{
        Node*temp=head;
        int cnt=1;
        while(cnt<position){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            insertatTail(tail,d);
        }
        Node* Nodetoinsert=new Node(d);
        Nodetoinsert->next=temp->next;
        temp->next->prev=Nodetoinsert;
        temp->next=Nodetoinsert;
        Nodetoinsert->prev=temp;
    }
}
void nodetodelete(Node* &head,Node* &tail,int position){
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;

    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        curr->prev=NULL;
        curr->next=NULL;
        delete curr;

    }

}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}
int main(){
    Node * node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertatHead(head,45);
    insertatTail(tail,67);
    insertatTail(tail,90);
    insertatTail(tail,144);
    insertatPosition(head,tail,2,53);
    print(head);
    nodetodelete(head,tail,4);
    print(head);
    return 0;
}