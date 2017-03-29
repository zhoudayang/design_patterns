#pragma once

#include <iostream>
#include <memory>

using std::cout;
using std::endl;

typedef enum ProductTypeTag
{
  TypeA = 0,
  TypeB,
  TypeC,
}PRODUCT_TYPE;

class Product
{
  public:
    virtual void show() = 0;
};

class ProductA : public Product
{
  public:
    virtual void show() override
    {
      cout << "I am ProductA" << endl;
    }
};

class ProductB : public Product
{
  public:
    virtual void show() override
    {
      cout << "I am ProductB" << endl;
    }
};

class ProductC : public Product
{
  public:
    virtual void show() override
    {
      cout << "I am ProductC" << endl;
    }
};

class Simple_Factory
{
  public:
    // use std::unique_ptr rather than raw pointer
    std::unique_ptr<Product> createProduct(PRODUCT_TYPE type)
    {
      switch(type)
      {
        case TypeA:
          return std::unique_ptr<Product>(new ProductA());
        case TypeB:
          return std::unique_ptr<Product>(new ProductB());
        case TypeC:
          return std::unique_ptr<Product>(new ProductC());
        default:
          return std::unique_ptr<Product>();
      }
    }
};
