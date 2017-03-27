#include "observer.h"

#include <memory>

int main(int argc, char* argv[])
{
  auto subject = std::make_shared<ConcreteSubject>();

  std::shared_ptr<Observer> observer_1 = std::make_shared<ConcreteObserver1>(subject.get());
  std::shared_ptr<Observer> observer_2 = std::make_shared<ConcreteObserver2>(subject.get());

  subject->set_value(100);
  subject->registerObserver(observer_1.get());
  subject->registerObserver(observer_2.get());

  subject->notifyObserver();

  subject->removeObserver(observer_2.get());

  subject->set_value(666);
  subject->notifyObserver();

  return 0;
}
