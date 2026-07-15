#include<iostream>
using namespace std;
class human{
  public:
  string name;
  int age;
  protected:
  int height;
  public:
  int getage(){
    return age;
  }
  void setage(int a){
    this->age=a;
  }
};
class Male: private  human{
    public:
    string colour;
    void sleep(){
    cout<<"Male is sleeping"<<endl;
    }
    int getheight(){
        return height;
    }
    void attack(){
    cout<<"Male is attacking"<<endl;
    }
};
int main(){
    human me;

    Male obj;
    
    cout<<"height of student us "<<obj.getheight()<<endl;
    // cout<<"name of student us "<<obj.name<<endl;
    // cout<<"age of student us "<<obj.age<<endl;
   // cout<<"colour of student us "<<obj.colour<<endl;
    return 0;
}