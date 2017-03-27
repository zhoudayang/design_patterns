#pragma once

#include <iostream>
using namespace std;

// singleton in C++, thread safe, auto call destructor when exit
class singleton
{
  public:
    static singleton* getInstance()
    {
      static singleton instance;
      return &instance;
    }

    ~singleton()
    {
      cout << "singleton::~singleton()" << endl;
    }

    void print() const { cout << "hello world from singleton" << endl; }

    singleton(const singleton&) = delete;
    void operator = (const singleton&) = delete;

  private:
    singleton() { cout << "singletion::singletion()" << endl; }

};
