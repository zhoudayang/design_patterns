#pragma once
#include <string>
#include <assert.h>
#include <memory>
#include <iostream>

using std::string;
using std::unique_ptr;
using std::cout;
using std::endl;

// follow java iterator, not compatible with C++
template<typename T>
class Iterator
{
  public:
    virtual bool hasNext() const = 0;
    virtual T next() const = 0;
};


// simple implementation of array iterator
template<typename T>
class ArrayIterator : public Iterator<T>
{
  public:
    ArrayIterator(T* array, int size)
      : array_(array),
        size_(size),
        pos_(0)
    { }
//
//    ArrayIterator(T* array, int size, int pos)
//      : array_(array),
//        size_(size),
//        pos_(pos)
//    {
//    }

    virtual T next() const override
    {
      return array_[pos_ ++];
    }

    virtual bool hasNext() const override
    {
      if(pos_ >= size_ || array_ == nullptr)
        return false;
      return true;
    }

  private:

    T* array_;
    int size_;
    mutable int pos_;
};

// 菜单内容项目
class Item
{
  public:
    Item(const string& name, const string& description, double price)
      : name_(name),
        description_(description),
        price_(price)
    {  }

    Item() = default;

    string get_name() const { return name_; }

    string get_description() const { return description_; }

    double get_price() const { return price_; }

  private:
    string name_;
    string description_;
    double price_;
};

class DinnerMenu
{
  public:
    explicit DinnerMenu(int size)
      : items_(nullptr),
        size_(size),
        pos_(0)
    {
      items_ = new Item[size_];
      assert(items_);
    }

    DinnerMenu(Item* items, int size)
      : items_(items),
        size_(size),
        pos_(0)
    { }

    ArrayIterator<Item> createIterator() const
    {
      return ArrayIterator<Item>(items_, pos_);
    }

    ~DinnerMenu()
    {
      delete [] items_;
      items_ = nullptr;
      size_ = 0;
    }

    bool push_back(const Item& item)
    {
      if(pos_ < size_)
      {
        items_[pos_ ++ ] = item;
        return true;
      }
      return false;
    }

  private:
      Item * items_;
      int size_;
      int pos_;
};

class Waitress
{
  public:
    explicit Waitress(unique_ptr<DinnerMenu>&& menu)
      : menu_(std::move(menu))
    {

    }

    void printMenu()
    {
      print_helper(menu_->createIterator());
    }

  private:

    template<typename T>
    void print_helper(const Iterator<T>& iterator)
    {
      while(iterator.hasNext())
      {
        auto item = iterator.next();
        cout << item.get_name() << ", " << item.get_price() << ", " << item.get_description() << endl;
      }
    }

    unique_ptr<DinnerMenu> menu_;
};
