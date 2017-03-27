#pragma once
#include <pthread.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class singleton
{
  public:
    static singleton* getInstance()
    {
      pthread_once(&ponce_, singleton::init);
    }

    ~singleton()
    {
      cout << "singleton::~singleton()" << endl;
    }

    void print() const
    {
      cout << "hello world from singleton" << endl;
    }

    singleton(const singleton&) = delete;
    void operator = (const singleton&) = delete;

  private:

    singleton()
    {
      cout << "singleton::singleton()" << endl;
    }

    static void init()
    {
      value_ = new singleton();
      ::atexit(&singleton::destroy);
    }

    static void destroy()
    {
      delete value_;
      value_ = nullptr;
    }

  static singleton*     value_;
  static pthread_once_t ponce_;
};

singleton* singleton::value_ = nullptr;
pthread_once_t singleton::ponce_ = PTHREAD_ONCE_INIT;
