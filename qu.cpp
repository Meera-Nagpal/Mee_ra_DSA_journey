#include<iostream>
#include<queue>
//#include<stack>
//#include<unordered_map>
using namespace std;
int solve(int *arr,int n,int k){
    deque<int>maxi(k);
    deque<int>mini(k);
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans=0;
    for(int i=k;i<n;i++){
        ans+=arr[maxi.front()]+arr[mini.front()];
        //removal
        while(!maxi.empty()&&i-maxi.front()>=k){
            maxi.pop_front();
        }
        while(!mini.empty()&&i-mini.front()>=k){
            mini.pop_front();
        }
        //addition
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty()&&arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }
    ans+=arr[maxi.front()]+arr[mini.front()];
        return ans;
}
int main(){
    int arr[7]={2,5,-1,7,-3,-1,-2};
    int k=4;
    cout<<solve(arr,7,k)<<endl;
    return 0;
}
// class kq
// {
// public:
//    int n;
//    int k;
//    int *front;
//    int *rear;
//    int *arr;
//    int *next;
//    int freespot;
// kq(int n,int k){
//     arr=new int[n];
//     next=new int[n];
//     front=new int[k];
//     rear=new int[k];
//     for(int i=0;i<k;i++){
//         front[i]=-1;
//         rear[i]=-1;
//     }
//     for(int i=0;i<n;i++){
//         next[i]=i+1;
//     }
//     next[n-1]=-1;
//     freespot=0;

// }
// void enq(int data,int qn){
//     //overflow
//     if(freespot=-1){
//         cout<<"No empty space available"<<endl;
//         return;
//     }
//     int index=freespot;
//     freespot=next[index];
//     if(front[qn-1]){
//         front[qn-1]=index;
//     }
//     else{
//         next[rear[qn-1]]=index;
//     }
//     next[index]=-1;
//     rear[qn-1]=index;
//     arr[index]=data;
// }
// int dq(int qn){
//     if(front[qn-1]==-1){
//         cout<<"FULL"<<endl;
//     }
//     int index=front[qn-1];
//     front[qn-1]=next[index];
//     next[index]=freespot;
//     freespot=index;
// }

// };

// int tour( p[],int n){
//     int def=0;
//     int bal=0;
//     int start=0;
//     for(int i=0;i<n;i++){
//         bal+=p.petrol[]-p.distance[];
//         if(bal<0){
//         def+=bal;
//         start=i+1;
//         bal=0;
//     }
//     }
//     if(def+bal>=0){
//         return start;
//     }
//     else{
//         return -1;
//     }
// }
// string fNon(string A){
//     unordered_map<char,int>count;//iska mtlb ye h ki jo charater la coun puchh ajayega uska coun milega humko irrespective of order + time and space complexity bhi O(1) hoti h isliye better h ye .u
//     queue<char>q;
//     string ans="";
//     for(int i=0;i<A.length();i++){
//         char ch=A[i];
//         count[ch]++;
//         q.push(ch);
//     }
//     while(!q.empty()){
//         if(count[q.front()]>1){
//             q.pop();
//         }
//         else{
//             ans.push_back(q.front());
//             break;
//         }
//     }
//     if(q.empty()){
//         ans.push_back('#');
//     }
//     return ans;
// }   
// queue<int>modq(queue<int>q,int k){
//     stack<int>s;
//     for(int i=0;i<k;i++){
//         int value=q.front();
//         q.pop();
//         s.push(value);
//     }
//     while(!s.empty()){
//         int value=s.top();
//         s.pop();
//         q.push(value);
//     }
//     int t=q.size()-k;
//     while(t!=0){
//         int val=q.front();
//         q.pop();
//         q.push(val);
//         t--; 
//     }
//     return q;
// }
// vector<long long int>fnint(long long int A,long long int N ,long long int K){
//     deque<long long int>dq;
//     vector<long long>ans;
//     for(int i=0;i<K;i++){//ye for loop apne aap removal aur addition aur window formation dekhta rahega simultaneously.
//         if(A[i]<0){
//             dq.push_back(i);
//         }
//     }
//     if(dq.size()>0){//yaha removal ki baat hogi iss array mai
//         ans.push_back(A[dq.front()]);
//     }
//     else{
//         ans.push_back(0);
//     }
// //rest of the elements 
//     for(int i=K;i<N;i++){
//         if(!dq.empty()&& i-dq.front()>=K){
//             dq.pop_front();
//         }
//         if(A[i]<0){
//             dq.push_back(i);
//         }
//         if(dq.size()>0){
//             ans.push_back(A[dq.front()]);
//         }
//         else{
//             ans.push_back(0);
//         }
//     }
//     return ans;
// }

// stack<int>s;
// queue<int>q;
// queue<int>rev(queue<int>q){
//     stack<int>s;
//     while(!q.empty()){
//         int element=q.front();
//         q.pop();
//         s.push(element);

//     }
//     while(!s.empty()){
//         int element=s.top();
//         s.pop();
//         q.push(element);
//     }
//     return q;
// }