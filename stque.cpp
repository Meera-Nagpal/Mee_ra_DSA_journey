#include<iostream>
#include<stack>
using namespace std;
bool isValid(string str){
    stack<char>s;
    for(int i=0;i<str.length();i++){
    char ch=str[i];
   if(ch=='('|| ch=='{'|| ch=='['){
   s.push(ch);
}
  else{
    if(!s.empty()){
        char top=s.top();
        if((ch==')'&&top=='(')||(ch=='}'&&top=='{')|| (ch==']'&&top=='[')){
            s.pop();
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
    }
  }
  if(s.empty()){
    return true;
  }
  else{
    return false;
  }
}
// void solve(stack<int>s,int count,int n){
//     if(count==n/2){
//         s.pop();
//         return;
//     }
//     else{
//         int num=s.top();
//         s.pop();
//         solve(s,count+1,n);
//         s.push(num);
//     }
// }
int main(){
    string str="{({{}))}";
    stack<char>s;
    if(isValid(str)){
    cout<<"YES"<<endl;
}
else{
    cout<<"No"<<endl;
}
    // for(int i=0;i<str.length();i++){
    //     char ch=str[i];
    //     s.push(ch);
    // }
    // string ans="";
    // while(!s.empty()){
    //     char ch=s.top();
    //     ans.push_back(ch);
    //     s.pop();
    // }
    // cout<<"Reversed string is="<<ans<<endl;
    return 0;
}