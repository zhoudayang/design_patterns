#pragma once

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

class ProductA
{
  public:
    virtual void show() = 0;
};

class ProductA1 : public ProductA
{
  public:
    virtual void show() override
    {
      cout << "I am ProductA1 " << endl;
    }
};

class ProductA2 : public ProductA
{
  public:
    virtual void show() override
    {
      cout << "I am ProductA2" << endl;
    }
};

class ProductB
{
  public:
    virtual void show() = 0;
};

class ProductB1 : public ProductB
{
  public:
    virtual void show() override
    {
      cout << "I am ProductB1 " << endl;
    }
};

class ProductB2 : public ProductB
{
  public:
    virtual void show() override
    {
      cout << "I am ProductB2" << endl;
    }
};

class Factory
{
  public:
    virtual std::unique_ptr<ProductA> CreateProductA() = 0;
    virtual std::unique_ptr<ProductB> CreateProductB() = 0;
};

class ConcreteFactory1 : public Factory
{
  public:
    virtual std::unique_ptr<ProductA> CreateProductA()
    {
      return std::unique_ptr<ProductA>(new ProductA1());
    }
    virtual std::unique_ptr<ProductB> CreateProductB()
    {
      return std::unique_ptr<ProductB>(new ProductB1());
    }
};

class ConcreteFactory2 : public Factory
{
  public:
    virtual std::unique_ptr<ProductA> CreateProductA()
    {
      return std::unique_ptr<ProductA>(new ProductA2());
    }

    virtual std::unique_ptr<ProductB> CreateProductB()
    {
      return std::unique_ptr<ProductB>(new ProductB2());
    }
};

class SampleCode
{
  public:
    explicit SampleCode(std::unique_ptr<Factory>&& factory)
      : factory_(std::move(factory)),
        product_a_(factory_->CreateProductA()),
        product_b_(factory_->CreateProductB())
  { }

    void execute()
    {
      cout << "this is the sample execute code of class SampleCode " << endl;
      product_a_->show();
      product_b_->show();
    }

  private:

  std::unique_ptr<Factory> factory_;
  std::unique_ptr<ProductA> product_a_;
  std::unique_ptr<ProductB> product_b_;
};
