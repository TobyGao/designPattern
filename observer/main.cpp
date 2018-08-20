#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

class Observer{
public:
    virtual void update(string message) = 0;
};
class Subject{
public:
    virtual void registerObserver(Observer *) = 0;
    virtual void removeObserver(Observer *) = 0;
    virtual void notifyObservers(string message) = 0;
};

class NewsOffice : public Subject{
private:
    list <Observer *> m_observesList;
public:
    void registerObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void notifyObservers(string message);
};
class Customer : public Observer{
private:
    string m_name;
public: 
    Customer(string name){m_name = name;}
    void update(string message);
};

void NewsOffice::registerObserver(Observer *observer){
    m_observesList.push_back(observer);
}
void NewsOffice::removeObserver(Observer *observer){
    list <Observer *>::iterator itr = find(m_observesList.begin(), m_observesList.end(), observer);
    if (itr != m_observesList.end()){
        m_observesList.remove(*itr);
    }
}
void NewsOffice::notifyObservers(string message){
    list <Observer *>::iterator listBegin = m_observesList.begin();
    list <Observer *>::iterator listEnd = m_observesList.end();
    while (listBegin != listEnd){
        (*listBegin)->update(message);
        listBegin++;
    }
}
void Customer::update(string message){
    cout << m_name << "收到" << message << endl;
}
int main() {
    NewsOffice office;
    Observer *bill = new Customer("Bill");
    Observer *mike = new Customer("Mike");
    Observer *toby = new Customer("Toby");
    Observer *lily = new Customer("Lily");
    office.registerObserver(bill);
    office.registerObserver(mike);
    office.registerObserver(toby);
    office.registerObserver(lily);
    office.notifyObservers("一封訊息");

    cout<<endl<<endl;
    office.removeObserver(bill);
    office.notifyObservers("一封新訊息");
    delete bill;
    delete mike;
    return 0;
}
