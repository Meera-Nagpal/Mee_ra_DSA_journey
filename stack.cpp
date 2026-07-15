#include<iostream>
#include<stack>
using namespace std;
class Stack{
    public:
    int data;
    int top2;
    int top;
    int *arr;//pointer banana hoga becuz stack ka to size bada hoga hi agar pointer nhi banyenge to arr bhi utne size ka create hoga heap ke form mai memory ko rakhega jisse extra memory ko lega but agar pointer bnayenge to sirf jiyne elements stack mai honge utne hi elements ki memoryko lega.

// Stack(int d){
//     this->data=d;
//     arr=new int[d];
//     top=-1;
// }
Stack(int d){
    this->data=d;
    arr=new int[d];
    top=-1;
    top2=d;
}

void push(int element){
    if(data-top>1){
        top++;
        arr[top]=element;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }
}
void pop(){
    if(top>=0){
        top--;
    }
    else{
        cout<<"stack underflow"<<endl;
    }
}
int peek(){
    if(top>=0 && top<data){
    return arr[top];
}
    else{
        cout<<"Stack is empty"<<endl;
    }
}
bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }

}
};
int main(){
    Stack st(5);
    st.push(34);
    st.push(45);
    st.push(77);
    st.push(90);
    st.push(100);
    cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    if(st.isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Stack is not Empty"<<endl;
    }
// stack<int>s;
// s.push(4);
// s.push(8);
// s.pop();
// cout<<"Top element is"<<s.top()<<endl;
// if(s.empty()){
    //cout<<"Stack is empty"<<endl;

// else{
//     cout<<"Stack is not empty"<<endl;

// }
return 0;
}
