#include "Duck.h"

int main()
{
  auto flyBehavior1 = std::make_shared<FlyWithWings>();
  auto flyBehavior2 = std::make_shared<FlyNoWay>();

  Duck duck1(flyBehavior1);
  duck1.fly();

  Duck duck2(flyBehavior2);
  duck2.fly();

  return 0;
}
