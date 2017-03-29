#include "abstract_factory.h"

int main(int argc, char* argv[])
{
  std::unique_ptr<ConcreteFactory1> factory1(new ConcreteFactory1());
  std::unique_ptr<ConcreteFactory2> factory2(new ConcreteFactory2());

  SampleCode code1(std::move(factory1));
  SampleCode code2(std::move(factory2));

  code1.execute();
  code2.execute();

  return 0;
}
