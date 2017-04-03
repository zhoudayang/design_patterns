#include "adapter.h"

int main(int argc, char* argv[])
{
  std::unique_ptr<Duck> duck(new MallardDuck());
  std::unique_ptr<Turkey> turkey(new WildTurkey());

  turkey->gobble();
  turkey->fly();

  return 0;
}
