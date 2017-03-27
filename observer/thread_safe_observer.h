#pragma once

#include <iostream>
#include <list>
#include <memory>

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
    virtual void removeObserver(std::weak_ptr<Observer>) = 0;
    virtual void notifyObserver() = 0;
};

