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
bool pushfront(int d){
if((qfront==0 && rear==size-1 )|| (rear=(qfront-1)%(size-1))){
        cout<<"Que is full"<<endl;
        return false;
    }
    else if(qfront==-1){//only in the case when u have to insert the first element 
        qfront=rear=0;
        // arr[rear]=d;
    }
    else if(qfront=0){
        qfront=size-1;
        arr[rear]=d;

    }
    else{
        qfront--;
        
    }
    arr[qfront]=d;
    return true;
}
bool pushrear(int d){
    if((qfront==0 && rear==size-1 )|| (rear=(qfront-1)%(size-1))){
        cout<<"Que is full"<<endl;
        return false;
    }
    else if(qfront==-1){
        qfront=rear=0;
    }
        
    else if(rear==size-1 && qfront!=0){
        rear=0;
       
    }
    else{
        rear++;
        
    }
    arr[rear]=d;
    return true;
}
int popfront(){
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
    int popfront(){
    if(qfront==-1){
        cout<<"que is empty"<<endl;
        return -1;
    }
    int ans=arr[qfront];
    arr[qfront]=-1;
    if(qfront==rear){//single element
        
        qfront=rear=-1;
    }
       else if(rear=0){
        rear=size-1;
       } 
        else{
        rear--;
        }
        
        return ans;
    }


};
int main(){
deque<int>d;
d.push_front(12);
d.push_back(34);
cout<<d.front()<<endl;
cout<<d.back()<<endl;
d.pop_front();
cout<<d.front()<<endl;
cout<<d.back()<<endl;
d.pop_back();
if(d.empty()){
    cout<<"que is empty"<<endl;
}
else{
    cout<<"que is not empty"<<endl;
}
return 0;
}