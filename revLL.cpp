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

};
// void reverse(Node* head,Node * curr,Node*prev){
//     if(curr==NULL){
//         head=prev;
//         return;
//     }
//     else{
//         Node* forward=curr->next;
//         reverse(head,forward,curr);
//         curr->next=NULL;
//     }
// }
// Node* rev(Node*&head){
//     Node* curr=head;
//     Node* prev=NULL;
//     Node* forward=NULL;

    //reverse(head,curr,prev);
    //return head;}    // if(curr==NULL|| curr->next==NULL){
    //     return head;
    // }
    // while(curr!=NULL){
    //     forward=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=forward;
    // }
    // return prev;

//

// int getlen(Node* &head){
//     Node* temp=head;
//     int cnt=1;
//     while(temp!=NULL){
//         temp=temp->next;
//         cnt++;
//     }
//     return cnt;
// }
// Node* reverse(Node* &head){
//     int len=getlen(head);
//     int ans=(len/2)+1;
//     Node*temp=head;
//     int cnt=1;
//     while(cnt<ans){
//         temp=temp->next;
//         cnt++;
//     }
//    return temp;
// }

Node*getMiddle(Node*&head){
    //1 or no elements
    if(head==NULL||head->next==NULL){
        return head;
    }
    //2 elements
    else if(head->next->next==NULL){
        return head->next;
    }
    else{
        Node*slow=head;
        Node*fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            while(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
}
Node*findMid(Node*&head){
    return getMiddle(head);
}
void print(Node* &head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* rev(Node*&head){
    Node*curr=head;
    Node*next=NULL;
    Node*prev=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main(){
    Node* node1=new Node(10);
    Node*head=node1;
    //rev(head);
   // findMid(head);
    //print(head);
    return 0;
}