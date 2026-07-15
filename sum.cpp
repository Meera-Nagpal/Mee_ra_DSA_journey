#include <iostream>
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
Node*add(Node*&first,Node* &second){
    int carry=0;
    Node*anshead=NULL;
    Node*anstail=NULL;
    Node*curr1=first;
    Node*curr2=second;
    int sum=0;
    int digit=0;
    while(curr1!=NULL&&curr2!=NULL){
        sum=curr1->data+curr2->data+carry;
        digit=sum%10;
        curr1=curr1->next;
        curr2=curr2->next;
        carry=sum/10;//har loop mai return krne ki zarurat nhi h .
         insertatTail(anshead,anstail,digit);
        }
    while(curr1!=NULL){
        sum=curr1->data+carry;
        digit=sum%10;
        curr1=curr1->next;
        carry=sum/10;
        insertatTail(anshead,anstail,digit);
         
        }
    while(curr2!=NULL){
        sum=curr2->data+carry;
        digit=sum%10;
        curr2=curr2->next;
        carry=sum/10;
        insertatTail(anshead,anstail,digit);
         
        }    
     while(carry!=0){
        int sum=carry;
        digit=sum%10;
        insertatTail(anshead,anstail,digit);
       carry=sum/10;
     }   
     return anshead;


}
Node* sum(Node*&first,Node*&second){
    first=rev(first);
    second=rev(second);
    Node* ans=add(first,second);
    ans=rev(ans);
    return ans;

}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertatHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
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
        insertatTail(head,tail,d);
        return;
    }//order matter karega ye kahi bhi nhi likh skte ye yaha h tabhi comdtion tru hogi aur fn cjhjalega otherwise nodekanext kabhi khali higa hi nhi to condition always false ayegi.
    Node*NodetoInsert=new Node(d);
    NodetoInsert->next=temp->next;
    temp->next=NodetoInsert;

}   
int main(){
     Node* node1=new Node(3);
     Node* node2=new Node(4);
    cout<<node1->data<<endl;
    cout<<(*node1).next<<endl;
    Node *head=node1;
    Node *head2=node2;

    //insertatHead(head);
    print(head);

    insertatHead(head,8);
    print(head);
    Node *tail=node1;
    Node *tail2=node2;
    
    insertatTail(head2,tail2,9);
    insertatTail(head,tail,7);
    insertatTail(head2,tail2,5);
    insertatTail(head,tail,2);
    insertatTail(head2,tail2,5);
    //insertatTail(tail,40);
    print(head2);
    print(head);
    Node*ans=sum(head,head2);//we have made it node type means that we are returining the entire LL and not the only node.
    //if we wouldhave made it in int then it would have given us only head and hence we printed head only as it would have been only that single node.
    //return in node type main hum sirf prev,head ,ans return krte hain iska mtlb ye nhi ki sirf head hi return hua h , iska mtlb hai ki puri list return hui h. 
    cout<<"SUM IS=";
    print(ans);//kyunki opuri list return hui h ans node mai isliye head se pass karane mai puri lisyt print hogi.
    return 0;}