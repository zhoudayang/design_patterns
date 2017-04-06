#include "iterator.h"

int main(int argc, char* argv[])
{
  unique_ptr<DinnerMenu> menu(new DinnerMenu(10));

  for(int i = 0; i < 5; ++i)
  {
    menu->push_back(Item("beef", "hot beef", 30));
  }

  Waitress waitress(std::move(menu));
  waitress.printMenu();

  return 0;
}
