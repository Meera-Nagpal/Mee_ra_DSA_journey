#include<iostream>
#include <cstring>
using namespace std;   
class  hero{
    public:
 //properties
 //char name[100];
 int health;
 char *name;
 char level;
  static int timetoComplete;
 public:
 hero(){
   cout<<"constructor called"<<endl;
  name=new char[100];
 }//parametrised constructor banane ka matlb ye ni ki hum default wale ko hata denge .dono ko rakho.
 hero(int health,char level){
   cout<<"this->"<<this<<endl;
   this->health=health;
   this->level=level;
   name=new char[100];
   cout<<"constructor called"<<endl;//default iske banne ke baad gayab hojata h
 }
 //copy constructor
 hero(hero &temp){//datatype is;iye mention krte hain cuz in class humne har cheez ka datatype mention kiya h apart from passing only paramaters in main fn.isliye yaha apne parametrer ka datatype mention kiya h.also copy cons mai datatype ame hona chahiye varna there is no point of using copy constructor.
  this->health=temp.health;
    this->level=temp.level;
    char *ch=new char[strlen(temp.name)+1];
    strcpy(ch,temp.name);
    this->name=ch;
   //hero.health=temp.health;//yaha hero class h obj nhi isliye classs ke parameter ko ref krne ke liye this leyword ka use krte h na ki . operator.
 }

 
//  int gethealth(){
//     return health;
//  }
//  int getlevel(){
//     return level;
//  }
//  void sethealth(int h){
//     health=h;
//  }
//  void setlevel(char l){
//     level=l;
//  }
//  void setName(char name[]){
//    strcpy(this->name,name);
//  }
 void print(){
    cout<<"level->"<<this->level<<endl;
    cout<<"health->"<<this->health<<endl;
    cout<<"name is->"<<this->name<<endl;
 }
 static int random(){//static fns can acess only static members
return timetoComplete;

 }
 //destructor
 ~hero(){
   cout<<"destructor is called"<<endl;

 }

} ;
int hero :: timetoComplete=5;
int main(){
   hero a;
   hero *b=new hero();//destructor is called once only while constructor twice becuz static allocation ke liye destructor automatically call hota h .dynamic ke liye call krna pdega. khud print ni hoga jaise static ke liye hua.
   cout<<a.timetoComplete<<endl;//not recommended coz ye static member class ko nhi object ko belong krta h.
   b->timetoComplete=10;
   cout<<b->timetoComplete<<endl;
   //static members ke paas this keyword ni hota cuz this means pointer to obj and since obj create hi ni hora to ye bhi koi sense ni banat.
   delete b;
   cout<<hero::timetoComplete<<endl;
   cout<<hero::random()<<endl;
//    hero suresh(90,'M');
//    char name[8]="Anshuuu";
//    strcpy(suresh.name,name);
//    //suresh.setName(name);
//    //hero ritesh(suresh);
//    suresh.print();
//    //deafult copy constructor
//    hero ramesh(suresh);
//    //hero ramesh=suresh;
//    ramesh.print();
//    suresh.name[0]='J';
//    suresh.print();
//    ramesh.print();
//    suresh=ramesh;
//    suresh.print();
//    ramesh.print();//call by ref h isliye changes nhi honge default copy constructor shallow copy krta h .
//    //shallow copy maihum same hi memory ko access krte h .
//    //deep copy....ek alag se copy create hoti h aur suresh usko acces krnta h
//    //ismai copyconstructor hi use hoga fir not the default one .



//    // ritesh.health=suresh.health;
//    // ritesh.level=suresh.level;
//    //  cout<<"level->"<<ritesh.level<<endl;
//    //  cout<<"health->"<<ritesh.health<<endl;
// //destructor bhi create hojata h automatically koi return type ni hota iska koi parameter ni hota iska.
// //aur ye memory ko free krwane mai help krta h jab obj fill hone wala hota h
   






//    // suresh.sethealth(90);
//    // suresh.setlevel('M');
//     //object is an instance of a class
//     //cout<<"hello"<<endl;
    
//     //hero ramesh(50,'B');
//     //cout<<"Adress of Ramesha"<<&ramesh<<endl;
//    //  ramesh.gethealth();
//    //  cout<<"bye"<<endl;
//    //  cout<<"ramesh health is "<<ramesh.gethealth()<<endl;
//    //  cout<<"ramesh level is "<<ramesh.level<<endl;
//    //  hero *h=new hero;//dynamic object allocation
//    // ramesh.sethealth(70);
//     //ramesh.setlevel('A');
//     // ramesh.health=70;
//     // ramesh.level='A';
//    //  cout<<"h health is "<<(*h).gethealth()<<endl;
//    //  cout<<"h level is "<<(*h).level<<endl;
//    //  cout<<"h health is "<<h->gethealth()<<endl;
//    //  cout<<"h level is "<<h->level<<endl;
//    //  cout<<"="<<sizeof(ramesh)<<endl;
//     // cout<<"health is="<<ramesh.health<<endl;
//     // cout<<"level is="<<ramesh.level<<endl;
return 0;
}