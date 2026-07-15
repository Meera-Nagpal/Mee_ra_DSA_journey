#include<iostream>
#include<stack>
using namespace std;
class Stack{
    public:
    int data;
    int top2;
    int top1;
    int *arr;//pointer banana hoga becuz stack ka to size bada hoga hi agar pointer nhi banyenge to arr bhi utne size ka create hoga heap ke form mai memory ko rakhega jisse extra memory ko lega but agar pointer bnayenge to sirf jiyne elements stack mai honge utne hi elements ki memoryko lega.

// Stack(int d){
//     this->data=d;
//     arr=new int[d];
//     top=-1;
// }
Stack(int d){
    this->data=d;
    arr=new int[d];
    top1=-1;
    top2=d;
}

void push1(int element){
    if(top2-top1>1){
        top1++;
        arr[top1]=element;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }
}
void push2(int element){
    if(top2-top1>1){
        top2--;
        arr[top2]=element;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }
}
int pop1(){
    if(top1>=0){
        int ans=arr[top1];
        top1--;
    }
    else{
        return -1;
    }
}
int pop2(){
    if(top2<data){
        int ans=arr[top2];
        top1++;
    }
    else{
        return -1;
       // cout<<"stack underflow"<<endl;
    }
}
};