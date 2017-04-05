#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class CaffeIneBevarageWithHook {
  public:
    void prepareRecipe()
    {
      boilWater();
      brew();
      pourInCup();
      if(customerWantsCondiments())
      {
        addCondiments();
      }
    }

    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    void boilWater()
    {
      cout << "Boiling water" << endl;
    }

    void pourInCup()
    {
      cout << "Pouring into cup" << endl;
    }

    // 钩子方法，子类可以选择自行覆盖这个方法。
    virtual bool customerWantsCondiments()
    {
      return true;
    }
};

class CoffeWithHook : public CaffeIneBevarageWithHook
{
  virtual void brew() override
  {
    cout << "Dripping Coffe through filter" << endl;
  }

  virtual void addCondiments() override
  {
    cout << "Adding Sugar and Milk" << endl;
  }

  bool customerWantsCondiments() override
  {
    char answer = 'y';
    cout << "Would you like milk and sugar with your coffe(Y|N)?" << endl;
    cin >> answer;
    if(std::tolower(answer) == 'y')
    {
      return true;
    }
    return false;
  }
};

