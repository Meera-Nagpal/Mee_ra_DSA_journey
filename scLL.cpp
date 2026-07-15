#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

Node(int d){
    this->data=d;
    this->next=NULL;
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
void insertNode(Node* &tail,int position,int d){
    if(tail==NULL){
        Node *temp=new Node(d);
        tail=temp;
        temp->next=temp;
    }
    else{
        Node* curr=tail;
        int cnt=1;
        while(cnt<position){
            curr=curr->next;
            cnt++;

        }
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }

}

void deletenode(Node* &tail,int position){
    if(tail==NULL){
        cout<<"Please check again"<<endl;
        return;
    }
    else{
    Node* prev=tail;
    Node* curr=prev->next;
    int cnt=1;
    while(cnt<position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    if(prev==curr){
        tail=NULL;
    }
    else if(tail==curr){
        tail=prev;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;

}}


void print(Node* &tail){
    if(tail==NULL){
        cout<<"Please check again"<<endl;
    }
    Node* temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail);
    cout<<endl;
}
int main(){
    Node* node1=new Node(10);
    node1->next=node1;
    Node* tail=node1;
    insertNode(tail,1,345);
    insertNode(tail,2,999);
    insertNode(tail,3,890);
    insertNode(tail,4,458);
    insertNode(tail,5,665);
    print(tail);
    deletenode(tail,3);
    deletenode(tail,4);
    deletenode(tail,2);
    print(tail);
    cout<<"tail is"<<tail->data<<endl;
    return 0;

}