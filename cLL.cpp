#include <iostream>
#include<map>
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
}
};
void insertNode(Node* &tail,int element,int d){
    if(tail==NULL){//empty list
        Node*temp=new Node(d);
        tail=temp;
        temp->next=temp;//indicating that this is a cLL
    }
    else{
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node*temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;//cLL clue.
    }
}
void print(Node* tail){
    
    Node*temp=tail;
     if(tail==NULL){
        cout<<"Please check again"<<endl;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
        cout<<endl;
    
}
void deleteNode(Node* &tail,int value){
    if(tail==NULL){
        cout<<"Please check again"<<endl;
    }
    else{
        Node* prev=tail;
        Node *curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        if(curr==prev){//1node cll
            tail=NULL;
        }
        else if(tail==curr){//2node cll
            tail=prev;
        }
        prev->next=curr->next;
        // if (tail==curr){
        //     tail=prev; //tail ko bhi evaluate krna zaruri hai varna hum tail ko hi dlete kr rhe h jisse segmentation fault aara h.only jab curr=tail hoga tab hi ye condition apply hogi.tail ko redefine kiya h .
        // }       
         curr->next=NULL;
        delete curr;
        
    }
}
bool isCircular(Node* &tail){
    if(tail==NULL){
        return NULL;
    }
    Node*temp=tail;
    while(temp!=NULL && temp!=tail){
        temp=temp->next;

    }
    if(temp==tail){
        return true;

    }
    return false;

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
int main(){
    Node* tail=NULL;
    //empty list mai insert kr rhe h abhi
    insertNode(tail,5,3);
    insertNode(tail,3,5);
    insertNode(tail,5,7);
    insertNode(tail,5,6);
    deleteNode(tail,3);
    print(tail);
    if(isCircular(tail)){
        cout<<"It is CLL"<<endl;
    }
    else{
        cout<<"Its not CLL"<<endl;
    }

    return 0;
}