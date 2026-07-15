#include<iostream>
using namespace std;
// class Animal{
//     public:
//     int age;
//     int weight;
//     public:
//     void bark(){
//         cout<<"Barking"<<endl;
//     }
// };
// class dog:public Animal{

// };
// class Germanshephard: public dog{

// };
// class Human{
//     public:
//     string colour;
//     void speak(){
//         cout<<"Speaking"<<endl;
//     }   
// };
// class Hybrid: public Animal,public Human{
   
// };




class A{
    public:
    void fun1(){
        cout<<"Indside fn 1"<<endl;
    }
};

class B :virtual public A{
    public:
    void fun2(){
        cout<<"Indside fn 2"<<endl;
    }
};

class C :virtual public A,public B{
    public:
    void fun3(){
        cout<<"Indside fn 3"<<endl;
    }
};

int main(){
  C obj;//scope resolution operator jo h vo sirf heirarchy wali class ke fns ko access krne ke liye hota hai otherwise hum aise hi likhe dete withut scope resolution.
  obj.A::fun1();
  obj.B::fun2();
  obj.C::fun1();






    // dog d;
    // d.speak();
    // cout<<d.age<<endl;
    // Germanshephard *g;
    // (*g).speak();
    // // cout<<(*g).age<<endl;
    // Hybrid obj1;
    // obj1.speak();
    // obj1.bark();




    // A object1;
    // object1.fun1();
    // B object2;
    // object2.fun2();
    // C object3;
    // object3.fun1();
    return 0;
}
