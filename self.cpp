#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

Node(int d){
    this->data=d;
    this->next=NULL;
}
~Node(){
     int value=this->data;
    // if(this->next!=NULL){
    //     delete next;
    //     this->next=NULL;
    // }
    cout<<"Value deleted for"<<value<<endl;
}
};
void insertathead(Node* &head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertatPosition(Node* &head,Node* &tail,int position,int d){
    if(position==1){
        insertathead(head,d);
        return;                              
    }
    else{
  Node*temp=head;
  int cnt=1;
  while(cnt<position-1){
    temp=temp->next;
    cnt++;
  }
  if(temp->next==NULL){
    insertattail(tail,d);
    return;
  }
  Node* Nodetoinsert=new Node(d);
  Nodetoinsert->next=temp->next;
  temp->next=Nodetoinsert;
}
}
void removeduplicates(Node*&head){
    Node* temp=head;
    while(temp!=NULL&& temp->next!=NULL){
        if(temp->data==temp->next->data){
            Node* duplicate=temp->next;
            temp->next=duplicate->next;//linked lists h to linking krna hoga
            duplicate->next=NULL;
            delete duplicate;
            //temp->next=NULL;
            //delete temp;
        }
        else{
            temp=temp->next;
        }
    }
}
void deleteNode(Node* &head,Node* &tail,int position){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
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
        curr->next=NULL;
        delete curr;
    }
}
void print(Node* &head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void unremove(Node* &head){
    Node*temp=head;
    while(temp->next!=NULL ){
        Node*prev=temp;
        Node*curr=temp->next;
        while(curr!=NULL){
            if(curr->data!=temp->data){
                prev=curr;
                curr=curr->next;
            }
            else{
                prev->next=curr->next;
                curr->next=NULL;
                delete curr;
                curr=prev->next;
                
            }
        }
        temp=temp->next;
    }

}
Node* sort(Node*&head){
    Node* temp=head;
    int zcount=0;
    int ocount=0;
    int tcount=0;
    while(temp!=NULL){
        if(temp->data==0){
            zcount++;
        }
        else if(temp->data==1){
            ocount++;
        }
        
        else if(temp->data==2){
            tcount++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(zcount!=0){
            temp->data=0;
            zcount--;
        }
        else if(ocount!=0){
            temp->data=1;
            ocount--;
        }
        else if(tcount!=0){
            temp->data=2;
            tcount--;
        }
        temp=temp->next;
    }
    return head;
}
void insert(Node* &tail,Node*curr){
    tail->next=curr;
    tail=curr;
}
Node* sortlist(Node*& head){
    Node*zerohead=new Node(-1);
    Node*onehead=new Node(-1);
    Node*twohead=new Node(-1);
    Node*zerotail=zerohead;
    Node*onetail=onehead;
    Node*twotail=twohead;
    Node*temp=head;
    while(temp!=NULL){
    int value=temp->data;{
        if(value==0){
            insert(zerotail,temp);
        }
        if(value==1){
            insert(onetail,temp);
        }
        else if(value==2){
            insert(twotail,temp);
        }

    }
    temp=temp->next;
}
//merge
    if(onehead!=NULL){
    zerotail->next=onehead->next;
}
    else{
    zerotail->next=twohead->next;
}
    onetail->next=twohead->next;
    twotail->next=NULL;
    head=zerohead->next;
    delete zerohead;//destructor agar recursive hoga to vo next node ko delete krta jayega aur aise puri list hi delete hojayegi but agar jaisa h upar vaisa hoga tabhi sirf duplicate node delete hogi.
    delete onehead;
    delete twohead;
    return head;

}
Node* arr(Node* &first, Node*&second){
    if(first->next==NULL){
        first->next=second;
        return second;
    }
    Node*curr1=first;
    Node*next1=curr1->next;
    Node*curr2=second;
    Node*next2=curr2->next;
    
    while(next1!=NULL&&curr2!=NULL){
    if((curr2->data>=curr1->data) && (curr2->data <= next1->data)){
        curr1->next=curr2;
        next2=curr2->next;
        curr2->next=next1;
        curr1=curr2;
        curr2=next2;

    }
    else{
        curr1=next1;
        next1=next1->next;
    
    if(next1==NULL){
        curr1->next=curr2;
        return first;
    }
    }
    }
    return first;
}

//merge two sorted lists
Node*merge(Node* &first,Node*&second){
    if(first==NULL){
        return second;
    }
    else if(second==NULL){
        return first;
    }
    else{
        if(first->data<=second->data){
            arr(first,second);
        }
        if(first->data>=second->data){
            arr(second,first);
        }
    }
}
int main(){
    Node* node1= new Node(0);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
    insertathead(head,1);
    insertattail(tail,2);
    insertathead(head,0);
    print(head);
    insertatPosition(head,tail,2,2);
    insertatPosition(head,tail,3,1);
    insertatPosition(head,tail,4,0);
    insertatPosition(head,tail,5,1);
    print(head);
    //deleteNode(head,tail,4);
    //deleteNode(head,tail,1);
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
    //removeduplicates(head);
    //sort(head);
    sortlist(head);
    print(head);
    //unremove(head);
    print(head);
    

    return 0;
}
