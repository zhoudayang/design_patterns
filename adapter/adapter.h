#pragma once

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class Duck
{
  public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class Turkey
{
  public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class MallardDuck : public Duck
{
  public:
    virtual void quack() override
    {
      cout << "Quack" << endl;
    }

    virtual void fly() override
    {
      cout << "I'm flying" << endl;
    }
};


class WildTurkey : public Turkey
{
  public:
    virtual void gobble() override
    {
      cout << "Gobble gobble" << endl;
    }

    virtual void fly() override
    {
      cout << "I'm flying a short distance" << endl;
    }
};

// 适配器，将Turkey接口包装成为Duck接口
class TurkeyAdapter : public Duck
{
  public:
    TurkeyAdapter(std::unique_ptr<Turkey>&& turkey)
      : turkey_(std::move(turkey))
    {

    }

    virtual void quack() override
    {
      turkey_->gobble();
    }

    virtual void fly() override
    {
      turkey_->fly();
    }

  private:
    std::unique_ptr<Turkey> turkey_;
};
