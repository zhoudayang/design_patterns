#include "singleton1.h"

int main()
{
  auto instance = singleton::getInstance();
  instance->print();

  return 0;
}
