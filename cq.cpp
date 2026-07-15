#include<iostream>
#include<queue>
using namespace std;
class Que{
    public:
    int *arr;
    int qfront;
    int rear;
    int size;

Que(){
    size=100001;
    arr=new int[size];
    qfront =0;
    rear =0;
}
bool isEmpty(){
    if(qfront==rear){
        cout<<"Que is empty"<<endl;
    }
    else{
        cout<<"Que is not empty"<<endl;
    }
}
bool enqueue(int d){
    if((qfront==0 && rear==size-1 )|| (rear=(qfront-1)%(size-1))){
        cout<<"Que is full"<<endl;
        return false;
    }
    else if(qfront==-1){
        qfront=rear=0;
        arr[rear]=d;
    }
    else if(rear==size-1){
        rear=0;
        arr[rear]=d;

    }
    else{
        rear++;
        arr[rear]=d;
    }
}
int dequeue(){
    if(qfront==-1){
        cout<<"que is empty"<<endl;
        return -1;
    }
    int ans=arr[qfront];
    arr[qfront]=-1;
    if(qfront==rear){//single element
        
        qfront=rear=-1;
    }
       else if(qfront=size-1){
        qfront=0;
       } 
        else{
        qfront++;
        }
        
        return ans;
    }

int qfront(){
    if(qfront==rear){
        return -1;
    }
    else{
        return arr[qfront];
    }
}
};
int main(){
    Que q;
    q.enqueue(8);
    q.enqueue(18);
    q.enqueue(18);

}