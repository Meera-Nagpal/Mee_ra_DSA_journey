#include <iostream>
using namespace std;
class Animal{
    public:
    void speak(){
        cout<<"Speaking"<<endl;//jab tak dog ke andar implementation nhi daali h tab tak yhi use karenge varna vohi wala fn use karenge.
    }
};
class Dog: public Animal{
    public:
    cout<<"Barking"<<endl;
   
};



/*class B{
public:
int a;
int b;
int add(){
    return a+b;

}
void operator + (B &obj){
    // int value1=this->a;
    // int value2=obj.a;
   // cout<<"output="<<value2-value1<<endl;
    cout<<"Meera hates tushar "<<this->a<<endl;
}
void operator() (){
    cout<<"Main bracket"<<endl;
}
};
// class A{
//     public:
//     void sayHello(){
//         cout<<"Say hello"<<endl;
//     }
//     int sayHello(string a,int n){
//         cout<<"Say hello"<<endl;
//         return 1;
//     }
//     void sayHello(string a){
//         cout<<"Say hello"<<endl;
       
//     }
 */
int main(){

Dog obj;
obj.speak();




















    /*B obj1,obj2;
    obj1.a=4;
    obj2.a=7;
    obj1 + obj2;
    obj1();
    */
    return 0;
}