#include<iostream>
#include<vector>
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
bool checkPalindrome(vector<int>arr){
    int n =arr.size();
    int s=0;
    int e=n-1;
    while(s<=e){
        if(arr[s]!=arr[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
        
    }
    return 1;
}
Node* getMid(Node* &head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
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

bool isPalindrome(Node* & head){
    // Node*temp=head;
    // vector<int>arr;
    // while(temp!=NULL){
    //     arr.push_back(temp->data);
    //     temp=temp->next;

    // }
    // return checkPalindrome(arr);
    if(head->next==NULL){
        return true;
    }
    Node *middle=getMid(head);
    Node* temp=middle->next;
    middle->next=rev(temp);
    Node*head1=head;
    Node*head2=middle->next;

    while(head2!=NULL){

        if(head1->data!=head2->data){
            return 0;
        }
        else{
            head1=head1->next;
            head2=head2->next;
        }


    }
    return true;
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
    insertatTail(tail,13);
    insertatTail(tail,10);
    insertatTail(tail,12);
    //insertatTail(tail,40);
    print(head);
    //insertatPosition(head,tail,1,45);
    //insertatPosition(head,tail,8,56);
    if(isPalindrome(head)){
        cout<<"Yes my dear it is a Palindrome"<<endl;
    }
    else{
        cout<<"No my dear it is not"<<endl;
    }
    
    return 0;
}