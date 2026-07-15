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
void enqueue(int d){
    if(rear==size){
        cout<<"Que is full"<<endl;
    }
    else{
        arr[rear]=d;
        rear++;
    }
}
int dequeue(){
    if(rear==qfront){
        cout<<"que is empty"<<endl;
    }
    else{
        int ans=arr[qfront];
        arr[qfront]=-1;
        qfront++;
        if(qfront==rear){
            qfront=0;
            rear=0;
        }
        return ans;
    }
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