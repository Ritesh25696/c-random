#include<iostream>
using namespace std;

class human{
private:
    int *age;
    string *name;

public:
    human(string iname,int ages)
    {age=new int;
    name = new string;
    *age=a;
    *name=iname;
    }

    void display(){
    cout<<*age<<endl<<*name<<endl;
    }

    ~human(){
    cout<<"destructor at work";
    delete name;
    delete age;
    }

    };

int main(){
    human *aruna;
    aruna=new human("aruna",100);
    aruna->display();
    delete aruna;
return 0;}
