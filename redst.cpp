#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;
class NStack{
    public:
    stack<int>s;
    int min=INT_MAX;

void push(int data){//the advantage of this approach is that we get prev min witht he help of curr min at the end of solving of pop fn .
//     push and pop ki help se humne repretedly min ki value ko update kiya h and they ar interconnected as wel cuzz we get prev min withthe help of curr min also . agar push la use nhi katrnge to getMin corect min ka value nhi dega .
//     also hum simply max value return kr skte the buthumn ye method use kiya h cuz humai time complexity O(1 chahiye thi ki koi loop na aaye bas directly push pop karke min ki value evluate hoti rahe aur return hojaye .
//     also pop fn ka kaam max return krna ni h .
// uska kaam simply pop fn reurn krna h . min aur pop alag hain . vo sirf pop element ko return karega ,tlnb normal element ko return karega.and encoded  ko evaluate krta rahega that is min elemwnet ].)
    if(s.empty()){
        s.push(data);
        min=data;
    }
    else{
        if(data<min){
            int value=2*data-min;
            push(value);
            min=data;
        }
        else{
            s.push(data);
        }
    }
}
int pop(){
    if(s.empty()){
        return -1;
    }
    int curr=s.top();
    s.pop();
    if(curr>min){
        return curr;
    }
    else{
        int prevMin=min;
        int value=2*min-curr;
        min=value;
        return prevMin;
    }

        
    }
int top(){
    if(s.empty()){
        return -1;
    }
    int curr=s.top();
    if(curr<min){
        return min;
    }
    else{
        return curr;
    }
}
bool isEmpty(){
    return s.empty();
}
int getMin(){
    if(s.empty()){
    return -1;
    }
    else{
        return min;
    }
}


// NStack(int N,int S){
//     n=N;
//     s=S;
//     arr=new int[s];
//     top=new int[N];
//     next=new int[s];
//     for(int i=0;i<n;i++){
//         top[i]=-1;
//     }
//     for(int i=0;i<s;i++){
//         next[i]=i+1;
//     }
    //last index=-1
    // next[s-1]=-1;
    // //initialise free spot
    // freespot=0;


// bool push(int x,int m){
//     if(freespot==-1){
//         return false;
//     }
//     int index=freespot;
//     freespot=next[index];
//     arr[index]=x;
//     next[index]=top[m-1];
//     top[m-1]=index;
//     return true;
// }
// int pop(int m){
//     if(top[m-1]==-1){
//         return -1;
//     } 
//     int index=top[m-1];
//     top[m-1]=next[index];
//     next[index]=freespot;
//     freespot=index;
//     return arr[index];

// }

    
// bool push(int x,int s){
//     //check for overflow
//     if(freespot==-1){
//         return false;
//     }
//     //find index
//      freespot=next[index];
//      //insert element in the array
//      arr[index]=x;
//      //update next
//      next[index]=top[m-1];
     
// }


// bool knows(vector<vector<int>>&M,int a,int b,int n){
//   if(M[a][b]==1){
//     return true;
//   }
//   else{
//     return false;
//   }
// }
// //celebrity question
// int celebrity(vector<vector<int>>&M,int n){
// stack<int>s;
// for(int i=0;i<n;i++){
//     s.push(n);
// }
// //step 2
// while(s.size()>1){
//     int a=s.top();
//     s.pop();
//     int b=s.top();
//     s.pop();
//     if(knows(M,a,b,n)){
//     s.push(b);
//     }
//     else{
//         s.push(a);
//     }
    
// }
// int candidate=s.top();
// int zerocount=0;
//     bool rowcheck=false;
//     for(int i=0;i<n;i++){
//         if(M[candidate][i]==0){
//             zerocount++;
//         }
//         // if(zerocount==n){
//         //     rowcheck=true;
//         // }
//         if(zerocount!=n){
//             return -1;
//         }
//     }
//     bool columncheck=false;
//     int onecount=0;
//     for(int i=0;i<n;i++){
//         if(M[i][candidate]==1){
//             onecount++;

//         }
//         // if(onecount==n-1){
//         //     columncheck=true;
//         // }
//         if(onecount!=n-1){
//             return -1;
//         }
//     }
//     // if(rowcheck==true && columncheck==true){
//     //     return candidate;
//     // }
    
//         return candidate;
//     }
    





// vector<int>smaller(vector<int>&arr,int n){
//     stack<int>s;
//     s.push(-1);
//     vector<int>ans;
//     for(int i=n-1;i>=0;i--){
//         int curr=arr[i];
//         while(s.top()>=arr[i]){
//             s.pop();
//         }
//         ans[i]=s.top();
//         s.push(curr);
//     }
//     return ans;
// }



// bool findRed(string &str){
//     stack<char>s;
//     for(int i=0;i<str.length();i++){
//         char ch=str[i];
//         if(ch=='('|| ch=='+'||ch=='-'|| ch=='/'|| ch=='*'){
//             s.push(ch);
//         }
//         else{
//             if(ch==')'){
//             bool isRed=true;
//             while(s.top()!='('){//tab tak pop krte raho jab tak opening bracket na mil jaye
//             char top=s.top();
//             if(top=='+'||top=='-'|| top=='/'|| top=='*'){
//                 isRed=false;
//             }
//                 s.pop();
//             }
//             if(isRed==true){
//                 return true;
//                 s.pop();
//             }

//         }
//     }
//      return false;
 };