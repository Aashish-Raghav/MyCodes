#include <iostream>
#include <cstring>

using namespace std;
class Hero
{
private:
    int health;
    char level;
    char* name;
    static int time;
public:
    
    Hero(){
        cout << "constructor called" << endl;
        name = new char[100];
    }
    //constructor overloading;
    Hero(int health,char level,const char* name) : health(health), level(level){
        cout << "constructor overloaded" << endl;
        this->name = new char[100];
        strcpy(this->name,name);
    }

    Hero(const Hero & temp) : health(temp.health) 
    {
        cout << "copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
        char* ch = new char[strlen(temp.name) + 1];
        strcpy(ch,temp.name);
        this->name = ch;
    }

    void print() const {
        cout << endl;
        cout << "[ Name : " << name << ", ";
        cout << "health : " << health << ", ";
        cout << "level : " << level << " ]\n";
    }
    int getHealth() const{ return health;}
    char getLevel() const { return level;}
    char* getName() const { return name;}
    void setHealth(const int health) { Hero::health = health;}
    void setLevel(const char level) { Hero::level = level; }
    void setName(const char* name) { strcpy(this->name,name);}
    static int timeLeft() { return time;}
    Hero & operator=(const Hero& temp)
    {
        if (this == &temp)
            return *this;
        this->health = temp.health;
        this->level = temp.level;
        delete [] name;
        name = new char[strlen(temp.name) + 1];
        strcpy(name,temp.name);
        return *this;
    }
    ~Hero()
    {
        cout << endl;
        cout << "destructor called " << endl;
        delete [] name;
    }

};

int Hero::time = 5;

int main()
{
    cout << Hero::timeLeft() << endl;
    Hero h3(10,'A',"Aashish");
    Hero *h1 = new Hero;
    *h1 = h3;
    h1->print();
    h3.print();
    cout << h3.timeLeft << endl;        //WHY SHOWING 1;
    cout << h1->timeLeft << endl;       //WHY SHOWING 1;
    cout << Hero::timeLeft() << endl;

    delete h1;
    // h1.setHealth(60);
    // h1.setLevel('A');
    // cout << h1.getHealth() << " " << h1.getLevel() << endl;
    // h1.print();

    // Hero* a = new Hero;
    // cout << sizeof(Hero) << endl;
}