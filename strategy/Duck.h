#pragma once
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class FlyBehavior
{
  public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
  public:
    void fly() override
    {
      cout << "I'm Flying" << endl;
    }
};

class FlyNoWay : public FlyBehavior
{
  public:
    void fly() override
    {
      cout << "I can't Fly" << endl;
    }
};


class Duck
{
  public:
    Duck(const std::shared_ptr<FlyBehavior> & flyBehavior)
      : flyBehavior_(flyBehavior)
    {

    }

    void fly()
    {
      flyBehavior_->fly();
    }

  private:
    std::shared_ptr<FlyBehavior> flyBehavior_;

};
