#pragma once

#include <iostream>
#include <list>
#include <memory>
#include <mutex>

using std::cout;
using std::endl;

class Observer
{
  public:
    virtual void update(int value) = 0;
};

class Subject
{
  public:
    virtual void registerObserver(std::weak_ptr<Observer>) = 0;
    // but there remains a question, the weak_ptr can't support operator == !
    virtual void removeObserver(std::weak_ptr<Observer>) = 0;
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

    // no call in mutex locked state
    void registerObserver(std::weak_ptr<Observer> observer) override
    {
      std::lock_guard<std::mutex> lock(mutex_);
      observers_.push_back(observer);
    }

    // no call in mutex locked state
    /// but there remains a question, the weak_ptr can't support operator == !
    /// if you want to unregister, please just reset the concrete observer
    void removeObserver(std::weak_ptr<Observer> observer) override
    {
//      std::lock_guard<std::mutex> lock(mutex_);
//      auto it = std::find(observers_.begin(), observers_.end(), observer);
//      if(it != observers_.end())
//        observers_.erase(it);
    }

    void notifyObserver() override
    {
      std::lock_guard<std::mutex> lock(mutex_);
      for(auto it = observers_.begin(); it != observers_.end(); ++it)
      {
        std::shared_ptr<Observer> obj(it->lock());
        if(obj)
        {
          obj->update(value_);
        }
        else
        {
          cout << "notifyObserver() erase" << endl;
          it = observers_.erase(it);
        }
      }
    }

    // no call in mutex locked state
    void set_value(int value)
    {
      std::lock_guard<std::mutex> lock(mutex_);
      value_ = value;
    }

  private:
    std::mutex mutex_;
    std::list<std::weak_ptr<Observer>> observers_;
    int value_;
};

