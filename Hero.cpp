#include <iostream>
using namespace std;
class Hero{
    public:
char name[100];
int health;

char level;

int gethealth(){
    return health;
}
char getLevel(){
    return level;
}
void sethealth(int h){
    health =h;
}
void setLevel(char ch){
    level=ch;
}



};


int main(){
    return 0;
}