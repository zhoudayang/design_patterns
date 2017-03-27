#include "singleton2.h"

int main()
{
  auto instance = singleton::getInstance();
  instance->print();

  return 0;
}
