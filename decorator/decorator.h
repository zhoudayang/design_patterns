#pragma once

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class Component{
  public:
    virtual void operation() = 0;
};

class ConcreteComponent : public Component
{
  public:
  virtual void operation() override
  {
    cout << "operation function in ConcreteComponet function" << endl;
  }
};

class Decorator : public Component
{
  public:
    explicit Decorator(const std::shared_ptr<Component>& component)
      : component_(component)
    {
    }

    // 基本属性
    virtual void operation() override
    {
      // if component_ is not null, call operation function
      auto component = component_.lock();
      if(component)
        component->operation();
    }

  protected:
    // changed here: use std::weak_ptr rather than raw pointer
    /// use according to detail environment
    std::weak_ptr<Component> component_;
};

class ConcreteDecoratorA : public Decorator
{
  public:
    explicit ConcreteDecoratorA(const std::shared_ptr<Component>& component)
      : Decorator(component)
    { }

    virtual void operation() override
    {
      // 新增属性
      added_operation();
      Decorator::operation();
    }

    void added_operation()
    {
      cout << "this is the added operation of ConcreteDecoratorA" << endl;
    }
};

class ConcreteDecoratorB : public Decorator
{
  public:
    explicit ConcreteDecoratorB(const std::shared_ptr<Component>& component)
      : Decorator(component)
    { }

    virtual void operation() override
    {
      // 新增属性
      added_operation();
      Decorator::operation();
    }

    void added_operation()
    {
      cout << "this is the added operation of ConcreteDecoratorB" << endl;
    }
};
