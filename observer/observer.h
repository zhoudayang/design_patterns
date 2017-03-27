#pragma once
#include <list>
#include <iostream>

using std::cout;
using std::endl;

// base class of Subject and Observer
class Observer
{
  public:
    virtual void update(int value) = 0;
};

class Subject
{
  public:
    virtual void registerObserver(Observer*) = 0;
    virtual void removeObserver(Observer*) = 0;
    virtual void notifyObserver() = 0;
};

class ConcreteObserver1 : public Observer
{
  public:
    ConcreteObserver1(Subject* subject)
      : subject_(subject)
    { }

    void update(int value) override
    {
      cout << "ConcreteObserver1 receive update value : " << value << endl;
    }

  private:
    Subject* subject_;
};

class ConcreteObserver2 : public Observer
{
  public:
    ConcreteObserver2(Subject* subject)
      : subject_(subject)
    { }

    void update(int value) override
    {
      cout << "ConcreteObserver2 receive update value : " << value << endl;
    }

  private:
    Subject* subject_;
};

class ConcreteSubject : public Subject
{
  public:
    void registerObserver(Observer* observer) override
    {
      observers_.push_back(observer);
    }

    void removeObserver(Observer* observer) override
    {
      observers_.remove(observer);
    }

    void notifyObserver()
    {
      for(auto it = observers_.begin(); it != observers_.end(); ++it)
      {
        (*it)->update(value_);
      }
    }

    void set_value(int value) { value_ = value; }

  private:
    std::list<Observer*> observers_;
    int value_;
};

