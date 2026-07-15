#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&s,int x){//ab iss baar hum num ko x element ki tarah bhejre hain jiski vajah se ye recursive order mai yaha nhi ayenge jaise 9 pehle tha to vhi ayega aur kyunkiyaha iss fn mai recursion hoga to pehle x value at the bottom jayega .
    if(s.empty()||(!s.empty() && x>s.top())){
        s.push(x);
        return;
    }
    else{
        int num=s.top();
        s.pop();
        solve(s,x);
        s.push(num);
    }
}
void reverse(stack<int>&s){
    if(s.empty()){
        return;
    }
    else{
        int num=s.top();
        s.pop();
        reverse(s);
        solve(s,num);
    }
}

stack<int>push(stack<int>&s,int x){
    solve(s,x);
    return s;

}