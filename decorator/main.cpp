#include<iostream>
#include<string>
using namespace std; 

class Pizza{
protected:
    int m_price;
    string m_name;
public:
    Pizza(){m_price=0; m_name="";}
    virtual int getPrice(){return m_price;}
    virtual string getName(){return m_name;}
};
class NormalPizza : public Pizza{
public:
    NormalPizza(){m_price=15; m_name="普通披薩";}
};
class PestoPizza: public Pizza{
public:
    PestoPizza(){m_price=30; m_name="青醬披薩";}
};

class Topping : public Pizza{
};
class Onion : public Topping{
public:
    Pizza *m_pizza;
    Onion(Pizza *pizza){
        m_pizza = pizza;
    }
    int getPrice(){return 10 + m_pizza->getPrice();}
    string getName(){return "洋蔥" + m_pizza->getName();}
};
class Egg : public Topping{
public:
    Pizza *m_pizza;
    Egg(Pizza *pizza){
        m_pizza = pizza;
    }
    int getPrice(){return 10 + m_pizza->getPrice();}
    string getName(){return "蛋" + m_pizza->getName();}
};
class Tomato : public Topping{
public:
    Pizza *m_pizza;
    Tomato(Pizza *pizza){
        m_pizza = pizza;
    }
    int getPrice(){return 15 + m_pizza->getPrice();}
    string getName(){return "番茄" + m_pizza->getName();}
};
int main() { 
    Pizza *myPizza = new PestoPizza();
    Pizza *temp = myPizza;
    myPizza = new Onion(myPizza);
    myPizza = new Onion(myPizza);
    myPizza = new Tomato(myPizza);
    int price = myPizza->getPrice();
    string name = myPizza->getName();
    cout<<"The ordered pizza is "<<name<<"."<<endl
        <<"The ordered will cost you "<<price<<" dollars."<<endl;
    delete temp;
    return 0; 
}
