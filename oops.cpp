#include <iostream>
#include "Hero.cpp"
using namespace std;

int main(){
    Hero ramesh;
    // cout<<"size of h1: "<<sizeof(h1)<<endl;
    cout<<":health is:" << ramesh.gethealth()<<endl;
    cout<<":Level is:" << ramesh.getLevel()<<endl;
    return 0;
}