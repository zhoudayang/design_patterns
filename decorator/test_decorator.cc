#include "decorator.h"

int main(int argc, char* argv[])
{
  std::shared_ptr<ConcreteComponent> component = std::make_shared<ConcreteComponent>();

  std::shared_ptr<ConcreteDecoratorA> decorator_a = std::make_shared<ConcreteDecoratorA>(component);
  std::shared_ptr<ConcreteDecoratorB> decorator_b = std::make_shared<ConcreteDecoratorB>(component);

  std::shared_ptr<ConcreteDecoratorC> decorator_c = std::make_shared<ConcreteDecoratorC>(component);

  decorator_a->operation();
  decorator_b->operation();

  decorator_c->operation();

  return 0;
}
