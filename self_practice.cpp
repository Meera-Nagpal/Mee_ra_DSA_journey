#include <iostream>
using namespace std;
class Human{
    public:
    string name;
    int age;
    int height;
    int weight;
    public:
    int getAge(){
        return this->age;
    }
    void setWeight(int w){
        this->weight=w;
    }
};
class Male:public Human{
    public:
    string color;
    void sleep(){
    cout<<"Male sleeping"<<endl;

    }
};
class Male:protected Human{
    public :
    string colour;
    void sleep(){
     cout<<"Man is sleeping"<<endl;
    }
    int getHeight(){
        return this->height;
    }
};
int main(){
    Male obj;
    // cout<<obj.age<<endl;
    // cout<<obj.weight<<endl;
    // cout<<obj.height<<endl;
    // cout<<obj.color<<endl;

    return 0;
}