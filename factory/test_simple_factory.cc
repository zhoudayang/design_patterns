#include "simple_factory.h"

int main(int argc, char* argv[])
{

  std::shared_ptr<Simple_Factory> factory = std::make_shared<Simple_Factory>();

  auto product_A = factory->createProduct(TypeA);
  auto product_B = factory->createProduct(TypeB);
  auto product_C = factory->createProduct(TypeC);

  product_A->show();
  product_B->show();
  product_C->show();

  return 0;
}
