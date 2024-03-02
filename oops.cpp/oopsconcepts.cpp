#include<iostream>
using namespace std;
class Hero{
    
    
    public:
   int health;
   char name[10];
   char level;
   Hero()
   {
    cout<<"contructor  called"<<endl;
   }
   Hero(int health){
    this->health=health;
   }
   Hero(Hero &temp){
    this->health=temp.health;
 ;
   }
  /* int gethealth()
   {
    return health;
   }
   void sethealth(int h)
   {
    health=h;
   }*/
};
int main()
{
    Hero a; //static alloc
    a.health=10;

    Hero *b=new Hero(); //dynamic alloc
    b->health=20;
    
    //cout<<"level is: "<<(*b).level<<endl;
        /*cout<<"size: "<<sizeof(a.health)<<endl;
    cout<<"size: "<<sizeof(a.name)<<endl;
    cout<<"size: "<<sizeof(a.level)<<endl;
    cout<<"szie: "<<sizeof(a)<<endl;//object gets one byete of memeory*/
    /*cout<<a.gethealth()<<endl;//garbagw value
    a.sethealth(10);
    cout<<a.gethealth()<<endl;*/
    Hero temp(a);
    cout<<"temp health"<<temp.health<<endl;
    cout<<"parmetrixed constr: "<<b->health<<endl;
    cout<<"parmetrixed constr: "<<a.health<<endl;
   


}