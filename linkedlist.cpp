#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node* next; 
   // int position;

Node(int data){
    this->data=data;
    this->next=NULL;
}
~Node(){
    int value=this->data;
    //memory free
    if (next!=NULL)
    delete next;
    this->next=NULL;
}
// cout<<"Memory is free for node with data"<<value<<endl; 
};

void insertatHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertatTail(Node* &tail,int d){
    Node *temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertatPosition(Node* &head,Node* &tail,int position,int d){
    if(position==1){
        insertatHead(head,d);
        return;//imp h varna value 2 baar implement hojayegi yaha sirf 2 baar hi implement hota h cuz when position is 2 then whi=le wali condition bhi true hojayego isliye 2 baar implement hoga .
    }


    
    Node*temp=head;
    int cnt=1;
    while(cnt<position-1 && temp!=NULL){
        temp=temp->next;
        cnt++;


    }
    if(temp->next==NULL){
        insertatTail(tail,d);
        return;
    }//order matter karega ye kahi bhi nhi likh skte ye yaha h tabhi comdtion tru hogi aur fn cjhjalega otherwise nodekanext kabhi khali higa hi nhi to condition always false ayegi.
    Node*NodetoInsert=new Node(d);
    NodetoInsert->next=temp->next;
    temp->next=NodetoInsert;

}   

void deleteNode(Node* &head,int position){
        if(position==1){
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;//isliye liye destructor banaya h upar
        }
        else{
            //middle or end node
            Node *curr=head;
            Node *prev=NULL;
            int cnt=1;
            while(cnt<position){
                prev=curr;
                curr=curr->next;
                cnt++;

            }
            prev->next=curr->next; 
            curr->next=NULL;
            delete curr;
        }

}
Node*Floyds(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL&& fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    if(slow==fast){
        cout<<"Yes floyds detection works="<<slow->data<<endl;
        return slow;
    }
    
    }
    return NULL;
}
Node* getNode(Node *&head){
    if(head==NULL){
        return NULL;
    }
    Node*intersection=Floyds(head);
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
bool detectloop(Node* &head){
    Node*temp=head;
    map<Node*,bool>visited;
    while(temp!=NULL){
        if(visited[temp]==true){
            return 1;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
void removeloop(Node* &head){
    if(head==NULL){
        return;
    }
    else{
        Node* startingNode=getNode(head);
        Node*temp=startingNode;
        while(temp!=startingNode){
            temp=temp->next;
        }
        temp->next=NULL;
    }
    
}
int main(){
    Node* node1=new Node(10);
    cout<<node1->data<<endl;
    cout<<(*node1).next<<endl;
    Node *head=node1;
    //insertatHead(head);
    print(head);

    insertatHead(head,12);
    print(head);
    Node *tail=node1;
    insertatTail(tail,13);
    insertatTail(tail,19);
    insertatTail(tail,23);
    insertatTail(tail,27);
    insertatTail(tail,31);
    insertatTail(tail,40);
    print(head);
    insertatPosition(head,tail,1,45);
    insertatPosition(head,tail,8,56);
    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    deleteNode(head,5);
    deleteNode(head,5);
    print(head);
    tail->next=head->next;
    if(detectloop(head)){
        cout<<"Yes"<<endl;
    }
    cout<<"MEETING POINT IS="<<Floyds(head)->data<<endl;
    cout<<"Node is"<<getNode(head)->data<<endl;
    removeloop(head);
    print(head);
    //cout<<node1->data<<endl; 
    //cout<<node1->next<<endl;
    return 0;
} 